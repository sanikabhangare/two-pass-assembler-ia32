#ifndef MNEMONIC_VALIDATOR_H
#define MNEMONIC_VALIDATOR_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

bool isValidMnemonic(string mnemonic, string opcodeFile)
{
    ifstream file("opcode.txt");

    if (!file)
        return false;

    string instruction;

    while (file >> instruction)
    {
        if (instruction == mnemonic)
            return true;
    }

    return false;
}

bool checkOperandCount(string mnemonic, vector<string> operands)
{
    if (mnemonic == "INC" ||
        mnemonic == "DEC" ||
        mnemonic == "MUL" ||
        mnemonic == "DIV")
    {
        return operands.size() == 1;
    }

    return operands.size() == 2;
}

#endif
