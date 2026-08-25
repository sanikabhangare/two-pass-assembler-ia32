#ifndef REGISTER_VALIDATOR_H
#define REGISTER_VALIDATOR_H

#include <iostream>
#include <string>
using namespace std;

bool isRegister(string reg)
{
    string registers[] = {
        "EAX", "EBX", "ECX", "EDX",
        "ESI", "EDI", "ESP", "EBP"
    };

    for (string r : registers)
    {
        if (reg == r)
            return true;
    }

    return false;
}

// Check instruction that requires TWO registers                                                                                                                                        
bool checkTwoRegisters(string op1, string op2)
{
    if (!isRegister(op1))
    {
        cout << "Error: Invalid register '" << op1 << "'\n";
        return false;
    }

    if (!isRegister(op2))
    {
        cout << "Error: Invalid register '" << op2 << "'\n";
        return false;
    }

    return true;
}
// Check instruction that requires ONE register                                                                                                                                         
bool checkOneRegister(string op1)
{
    if (!isRegister(op1))
    {
        cout << "Error: Invalid register '" << op1 << "'\n";
        return false;
    }

    return true;
}

#endif
