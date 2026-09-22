#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "data_directive.h"
#include "data_converter.h"
#include "location_counter.h"

using namespace std;

int main()
{
    ifstream file("text.asm");

    if (!file)
    {
        cout << "Error: Could not open text.asm" << endl;
        return 1;
    }

    LocationCounter lc;

    string line;

    cout << "Variable\tDirective\tValue\tHex\tSize\tAddress" << endl;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string variable;
        string directive;
        int value;

        ss >> variable;

        if (variable == "SECTION")
            continue;

        ss >> directive;

        if (directive != "DB" &&
            directive != "DW" &&
            directive != "DD")
        {
            continue;
        }

        ss >> value;

        int size = getDataSize(directive);

        string hexValue = decimalToHex(value);

        int address = lc.getAddress();

        cout << variable << "\t\t"
             << directive << "\t\t"
             << value << "\t"
             << hexValue << "h\t"
             << size << "\t"
             << "00000000h + " << address
             << endl;

        lc.update(size);
    }

    cout << "\nFinal Location Counter: "
         << lc.getAddress()
         << " bytes" << endl;

    file.close();

    return 0;
}
