//
// Created by Mandar Brahmbhatt on 12/12/23.
//

#ifndef MOCKOS_GENERATEPARSINGSTRATEGY_H
#define MOCKOS_GENERATEPARSINGSTRATEGY_H
#pragma once

#include "AbstractParsingStrategy.h"

class GenerateParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string) const override;
};
#endif //MOCKOS_GENERATEPARSINGSTRATEGY_H
