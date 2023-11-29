#ifndef ABSTRACT_FILE_SYSTEM_H
#define ABSTRACT_FILE_SYSTEM_H

#include "AbstractFile.h"
#include <string>

class AbstractFileSystem {
public:
    virtual ~AbstractFileSystem() = default; // Virtual destructor for proper polymorphism

    virtual int addFile(const std::string& filename, AbstractFile* file) = 0;
    virtual int createFile(const std::string& filename) = 0;
    virtual int deleteFile(const std::string& filename) = 0;
    virtual AbstractFile* openFile(const std::string& filename) = 0;
    virtual int closeFile(AbstractFile* file) = 0;
};

#endif // ABSTRACT_FILE_SYSTEM_H

