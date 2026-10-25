#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    ifstream file("text.asm");

    if (!file)
    {
        cout << "Error: Could not open text.asm" << endl;
        return 1;
    }

    string line;
    string variable;
    string directive;

    int value;
    int size;
    int address = 0;

    cout << "Symbol Table" << endl;

    
    cout << left
         << setw(15) << "Variable"
         << setw(15) << "Directive"
         << setw(15) << "Value"
         << setw(15) << "Size"
         << setw(15) << "Address"
         << endl;

    cout << "  "<< endl;

    
    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

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

        
        if (directive == "DB")
            size = 1;
        else if (directive == "DW")
            size = 2;
        else
            size = 4;

        
        cout << left
             << setw(15) << variable
             << setw(15) << directive
             << setw(15) << value
             << setw(15) << size
             << setw(15) << address
             << endl;

        
        address = address + size;
    }

    cout << "\nFinal Location Counter: "
         << address << " bytes" << endl;

    file.close();

    return 0;
}
