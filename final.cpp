#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdint>
#include <cctype>

#include "flags.h"
#include "add_flags.h"
#include "sub_flags.h"

using namespace std;

int main()
{
    ifstream file("text.asm");

    if (!file)
    {
        cout << "Error: Could not open text.asm\n";
        return 1;
    }

    map<string, uint32_t> registers = {
        {"EAX", 0},
        {"EBX", 0},
        {"ECX", 0},
        {"EDX", 0}
    };

    FlagRegister flags;
    string line;

    cout << "============================================\n";
    cout << "       IA-32 FLAG REGISTER SIMULATION\n";
    cout << "============================================\n";

    while (getline(file, line))
    {
        // Remove comments
        size_t comment = line.find(';');

        if (comment != string::npos)
            line = line.substr(0, comment);

        // Convert instruction to uppercase
        for (char &c : line)
            c = static_cast<char>(
                toupper(static_cast<unsigned char>(c)));

        // Replace commas with spaces
        for (char &c : line)
        {
            if (c == ',')
                c = ' ';
        }

        stringstream ss(line);
        string mnemonic, op1, op2;

        if (!(ss >> mnemonic))
            continue;

        // Ignore section declarations and labels
        if (mnemonic == "SECTION" ||
            mnemonic.back() == ':')
            continue;

        ss >> op1 >> op2;

        // MOV: copy a value into a register
        if (mnemonic == "MOV")
        {
            if (registers.find(op1) == registers.end())
            {
                cout << "Invalid destination register: "
                     << op1 << '\n';
                continue;
            }

            if (registers.find(op2) != registers.end())
                registers[op1] = registers[op2];
            else
                registers[op1] =
                    static_cast<uint32_t>(stoull(op2));

            cout << "MOV " << op1 << ", " << op2
                 << " -> " << op1 << " = "
                 << registers[op1]
                 << " | Flags unchanged\n";
        }
        // ADD: add and update flags
        else if (mnemonic == "ADD")
        {
            if (registers.find(op1) == registers.end())
            {
                cout << "Invalid destination register: "
                     << op1 << '\n';
                continue;
            }

            uint32_t a = registers[op1];
            uint32_t b = (registers.find(op2) != registers.end())
                         ? registers[op2]
                         : static_cast<uint32_t>(stoull(op2));

            update_add_flags(flags, a, b);
            registers[op1] = a + b;

            cout << "ADD " << op1 << ", " << op2
                 << " -> Result = " << registers[op1] << " | ";
            flags.display();
            cout << '\n';
        }
        // SUB: subtract and update flags
        else if (mnemonic == "SUB")
        {
            if (registers.find(op1) == registers.end())
            {
                cout << "Invalid destination register: "
                     << op1 << '\n';
                continue;
            }

            uint32_t a = registers[op1];
            uint32_t b = (registers.find(op2) != registers.end())
                         ? registers[op2]
                         : static_cast<uint32_t>(stoull(op2));

            update_sub_flags(flags, a, b);
            registers[op1] = a - b;

            cout << "SUB " << op1 << ", " << op2
                 << " -> Result = " << registers[op1] << " | ";
            flags.display();
            cout << '\n';
        }
        // CMP: update flags without changing the register
        else if (mnemonic == "CMP")
        {
            if (registers.find(op1) == registers.end())
            {
                cout << "Invalid register: " << op1 << '\n';
                continue;
            }

            uint32_t a = registers[op1];
            uint32_t b = (registers.find(op2) != registers.end())
                         ? registers[op2]
                         : static_cast<uint32_t>(stoull(op2));

            update_sub_flags(flags, a, b);

            cout << "CMP " << op1 << ", " << op2
                 << " -> Compare | ";
            flags.display();
            cout << '\n';
        }
        // Jump if Zero Flag = 1
        else if (mnemonic == "JZ" || mnemonic == "JE")
        {
            cout << mnemonic << " " << op1 << " -> "
                 << (flags.ZF ? "Jump condition TRUE (ZF=1)"
                               : "Jump condition FALSE (ZF=0)")
                 << '\n';
        }
        // Jump if Zero Flag = 0
        else if (mnemonic == "JNZ" || mnemonic == "JNE")
        {
            cout << mnemonic << " " << op1 << " -> "
                 << (!flags.ZF ? "Jump condition TRUE (ZF=0)"
                                : "Jump condition FALSE (ZF=1)")
                 << '\n';
        }
        else
        {
            cout << "Unsupported instruction: "
                 << mnemonic << '\n';
        }
    }

    file.close();
    return 0;
}
