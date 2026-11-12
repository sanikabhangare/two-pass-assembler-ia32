#ifndef MACRO_TABLES_H
#define MACRO_TABLES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct MNTEntry {
    string name;
    int paramCount;
    int mdtIndex;
};

struct MDTEntry {
    int index;
    string line;
};

inline void printTables(const vector<MNTEntry> &MNT, const vector<MDTEntry> &MDT) {
    cout << "\n--- MNT (Macro Name Table) ---\n";
    cout << "Name\tParams\tMDT_Index\n";
    for (int i = 0; i < MNT.size(); i++) {
        cout << MNT[i].name << "\t" << MNT[i].paramCount << "\t" << MNT[i].mdtIndex << "\n";
    }

    cout << "\n--- MDT (Macro Definition Table) ---\n";
    cout << "Index\tInstruction\n";
    for (int i = 0; i < MDT.size(); i++) {
        cout << MDT[i].index << "\t" << MDT[i].line << "\n";
    }
}

#endif
