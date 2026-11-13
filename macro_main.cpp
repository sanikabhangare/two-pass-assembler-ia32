#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "macro_tables.h"
#include "macro_def.h"
#include "macro_expand.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input.asm>\n";
        return 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) {
        cout << "Error opening file!\n";
        return 1;
    }

    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        // Trim leading/trailing whitespace
        size_t start = line.find_first_not_of(" \t\r\n");
        size_t end = line.find_last_not_of(" \t\r\n");
        if (start != string::npos) {
            lines.push_back(line.substr(start, end - start + 1));
        }
    }
    inFile.close();

    vector<MNTEntry> MNT;
    vector<MDTEntry> MDT;
    vector<string> expandedCode;

    for (int i = 0; i < lines.size(); i++) {
        stringstream ss(lines[i]);
        string first, second;
        ss >> first >> second;

        if (second == "MACRO") {
            defineMacro(lines, i, MNT, MDT);
        } else {
            int idx = searchMNT(first, MNT);
            if (idx != -1) {
                string args;
                getline(ss, args);
                expandMacro(idx, args, MNT, MDT, expandedCode);
            } else {
                expandedCode.push_back(lines[i]);
            }
        }
    }

    printTables(MNT, MDT);

    ofstream outFile("output.asm");
    cout << "\n--- Expanded Assembly Code (output.asm) ---\n";
    for (int i = 0; i < expandedCode.size(); i++) {
        cout << expandedCode[i] << "\n";
        outFile << expandedCode[i] << "\n";
    }
    outFile.close();

    return 0;
}
