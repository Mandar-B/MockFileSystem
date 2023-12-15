#include <string>
#include <vector>
#include <sstream>

#include "../include/mockos/Constants.h"
#include "../include/mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) const {
    istringstream ss(input);
    string original;
    string dest;
    if (!(ss >> original)) return vector<string>();
    if (!(ss >> dest)) return vector<string>();
    vector<string> out = {original, dest};
    return out;
};