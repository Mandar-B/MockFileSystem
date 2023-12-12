#pragma once

#include "AbstractParsingStrategy.h"

class GenerateParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string) const override;
};