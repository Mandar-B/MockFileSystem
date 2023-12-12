#include <string>
#include <vector>
#include <sstream>

#include "../include/mockos/Constants.h"
#include "../include/mockos/RenameParsingStrategy.h"

using namespace std;

vector<string> RenameParsingStrategy::parse(string input) const {
    vector<string> out;
    out.push_back(input);
    istringstream ss(input);
    string rmf;
    ss >> rmf;
    out.push_back(rmf);
    return out;
};