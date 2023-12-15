//
// Created by Mandar Brahmbhatt on 12/12/23.
//
#include <string>
#include <vector>
#include <sstream>

#include "../include/mockos/Constants.h"
#include "../include/mockos/GenerateParsingStrategy.h"

using namespace std;

vector<string> GenerateParsingStrategy::parse(string input) const {
    istringstream ss(input);
    ss>>input;
    vector<string> out = {input, input, input};
    return out;
};
