#pragma once


#include <string>
#include "AbstractFile.h"  // Include the header file for AbstractFile

class AbstractFileFactory {
public:
    virtual ~AbstractFileFactory() = default;


    virtual AbstractFile* createFile(const std::string& fileName) = 0;
};