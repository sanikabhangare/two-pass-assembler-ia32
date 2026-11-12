#ifndef MACRO_DEF_H
#define MACRO_DEF_H

#include <sstream>
#include "macro_tables.h"

using namespace std;

inline vector<string> parseArgs(string str) {
    vector<string> list;
    stringstream ss(str);
    string item;
    while (getline(ss, item, ',')) {
        size_t start = item.find_first_not_of(" \t");
        size_t end = item.find_last_not_of(" \t");
        if (start != string::npos) {
            list.push_back(item.substr(start, end - start + 1));
        }
    }
    return list;
}

inline void defineMacro(vector<string> &lines, int &i, vector<MNTEntry> &MNT, vector<MDTEntry> &MDT) {
    stringstream ss(lines[i]);
    string macroName, keyword, paramStr;
    ss >> macroName >> keyword;
    getline(ss, paramStr);

    vector<string> params = parseArgs(paramStr);

    MNT.push_back({macroName, (int)params.size(), (int)MDT.size()});

    i++;
    while (i < lines.size()) {
        string bodyLine = lines[i];
        if (bodyLine == "ENDM") {
            MDT.push_back({(int)MDT.size(), "ENDM"});
            break;
        }

        for (int p = 0; p < params.size(); p++) {
            string marker = "#" + to_string(p + 1);
            size_t pos = bodyLine.find(params[p]);
            while (pos != string::npos) {
                bodyLine.replace(pos, params[p].length(), marker);
                pos = bodyLine.find(params[p], pos + marker.length());
            }
        }

        MDT.push_back({(int)MDT.size(), bodyLine});
        i++;
    }
}

#endif
