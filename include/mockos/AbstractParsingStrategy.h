#pragma once

#include <vector>

class AbstractParsingStrategy {
public:
    virtual std::vector<std::string> parse(std::string) const = 0;
};