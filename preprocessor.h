#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

struct ParsedLine {
    string mnemonic;
    vector<string> operands;
};

ParsedLine preprocess(string line)
{
    ParsedLine result;

    size_t pos = line.find(';');
    if (pos != string::npos)
        line = line.substr(0, pos);

    for (char &c : line) {
        if (c == ',')
            c = ' ';
    }

    string word;
    stringstream ss(line);

    ss >> result.mnemonic;

    while (ss >> word)
        result.operands.push_back(word);

    for (char &c : result.mnemonic)
        c = toupper(c);

    for (string &operand : result.operands) {
        for (char &c : operand)
            c = toupper(c);
    }

    return result;
}
