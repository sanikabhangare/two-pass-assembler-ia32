#ifndef REGISTER_VALIDATOR_H
#define REGISTER_VALIDATOR_H

#include <string>
#include <fstream>
using namespace std;

bool isRegister(string reg, string registerFile)
{
    ifstream file("registers.txt");

    if (!file)
        return false;

    string registerName;

    while (file >> registerName)
    {
        if (registerName == reg)
            return true;
    }

    return false;
}

#endif

