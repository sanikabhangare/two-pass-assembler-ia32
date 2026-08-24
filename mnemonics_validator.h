#ifndef MNEMONIC_VALIDATOR_H
#define MNEMONIC_VALIDATOR_H

#include <string>
#include <vector>
using namespace std;

bool isValidMnemonic(string mnemonic)
{
    string instructions[] = {
        "MOV", "ADD", "SUB", "CMP",
        "XOR", "OR", "AND", "INC", "DEC", "MUL", "DIV"
    };

    for (string instruction : instructions) {
        if (mnemonic == instruction)
            return true;
    }

    return false;
}

bool checkOperandCount(vector<string> operands)
{
    return operands.size() == 2;
}

#endif
