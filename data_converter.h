#ifndef DATA_CONVERTER_H
#define  DATA_CONVERTER_H

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

string decimalToHex(int value)
{
    stringstream ss;

    ss << uppercase << hex << value;

    return ss.str();
}

#endif
