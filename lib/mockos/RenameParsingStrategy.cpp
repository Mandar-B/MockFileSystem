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
    ss >> original;
    ss >> dest;
    vector<string> out = {original, dest};
    return out;
};