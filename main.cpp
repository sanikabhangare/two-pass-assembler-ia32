#include <iostream>
#include <fstream>
#include <cctype>
#include "preprocessor.h"
#include "mnemonics_validator.h"
#include "register_validator.h"

using namespace std;

int main()
{
    ifstream file("text.asm");

    if (!file) {
        cout << "Error: Cannot open text.asm\n";
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        ParsedLine parsed = preprocess(line);

        if (parsed.mnemonic.empty())
            continue;

        for (char &c : parsed.mnemonic)
            c = toupper(c);


        for (string &op : parsed.operands)
        {
            for (char &c : op)
                c = toupper(c);
        }

        if (!isValidMnemonic(parsed.mnemonic))
        {
            cout << "Error: Invalid instruction '"
                 << parsed.mnemonic << "'\n";
            continue;
        }

        if (parsed.mnemonic == "INC" ||
            parsed.mnemonic == "DEC" ||
            parsed.mnemonic == "MUL" ||
            parsed.mnemonic == "DIV")
        {
          
            if (parsed.operands.size() != 1)
            {
                cout << "Error: " << parsed.mnemonic
                     << " requires one register\n";
                continue;
            }

           
            if (checkOneRegister(parsed.operands[0]))
            {
                cout << "Valid: "
                     << parsed.mnemonic << " "
                     << parsed.operands[0] << "\n";
            }
        }
        else
        {
           
            if (parsed.operands.size() != 2)
            {
                cout << "Error: " << parsed.mnemonic
                     << " requires two registers\n";
                continue;
            }

            if (checkTwoRegisters(parsed.operands[0],
                                  parsed.operands[1]))
            {
                cout << "Valid: "
                     << parsed.mnemonic << " "
                     << parsed.operands[0] << ", "
                     << parsed.operands[1] << "\n";
            }
        }
    }

    file.close();
    return 0;
}
