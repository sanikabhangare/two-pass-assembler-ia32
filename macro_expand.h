#ifndef MACRO_EXPAND_H
#define MACRO_EXPAND_H

#include "macro_tables.h"
#include "macro_def.h"

using namespace std;

inline int searchMNT(const string &name, const vector<MNTEntry> &MNT) {
    for (int i = 0; i < MNT.size(); i++) {
        if (MNT[i].name == name) return i;
    }
    return -1;
}

inline void expandMacro(int mntIdx, string argStr, const vector<MNTEntry> &MNT,
                        const vector<MDTEntry> &MDT, vector<string> &expandedCode) {
    vector<string> actualArgs = parseArgs(argStr);
    int mdtPtr = MNT[mntIdx].mdtIndex;

    while (MDT[mdtPtr].line != "ENDM") {
        string line = MDT[mdtPtr].line;

        // Replace #1, #2 with actual arguments
        for (int a = 0; a < actualArgs.size(); a++) {
            string marker = "#" + to_string(a + 1);
            size_t pos = line.find(marker);
            while (pos != string::npos) {
                line.replace(pos, marker.length(), actualArgs[a]);
                pos = line.find(marker, pos + actualArgs[a].length());
            }
        }

        expandedCode.push_back(line);
        mdtPtr++;
    }
}

#endif
