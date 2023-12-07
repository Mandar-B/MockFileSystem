// SimpleFileFactory.h

#pragma once

#include "AbstractFileFactory.h"
// Include the header file for SimpleFile



#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileFactory : public AbstractFileFactory {
public:
    // Implementation of the createFile method
    AbstractFile* createFile(const std::string& fileName) override;
};
// SIMPLE_FILE_SYSTEM_H

