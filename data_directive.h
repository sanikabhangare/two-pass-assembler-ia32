#ifndef DATA_DIRECTIVE_H
#define DATA_DIRECTIVE_H

#include <string>
using namespace std;

int getDataSize(string directive)
{
    if (directive == "DB")
        return 1;

    if (directive == "DW")
        return 2;

    if (directive == "DD")
        return 4;

    return 0;
}

#endif
