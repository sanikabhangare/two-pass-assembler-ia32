#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

#include "preprocessor.h"
#include "mnemonics_validator.h"
#include "register_validator.h"

using namespace std;

int main()
{
    ifstream file("text.asm");

    if (!file)
    {
        cout << "Error: Cannot open text.asm\n";
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        ParsedLine parsed = preprocess(line);

        if (parsed.mnemonic.empty())
            continue;

        if (!isValidMnemonic(parsed.mnemonic, "opcode.txt"))
        {
            cout << "Mnemonic: " << parsed.mnemonic << "\n";
            cout << "Status: Not Found\n";
            cout << "\n";
            continue;
        }

        cout << "Mnemonic: " << parsed.mnemonic << "\n";
        cout << "Status: Found\n";

        if (!checkOperandCount(parsed.mnemonic, parsed.operands))
        {
            cout << "Error: Invalid number of operands\n";
            cout << "\n";
            continue;
        }

        for (string operand : parsed.operands)
        {
            cout << "Operand: " << operand << "\n";

            if (isRegister(operand, "registers.txt"))
            {
                cout << "Type: Register\n";
            }
            else
            {
                cout << "Type: Unknown\n";
            }

            cout << "\n";
        }
    }

    file.close();

    return 0;
}
