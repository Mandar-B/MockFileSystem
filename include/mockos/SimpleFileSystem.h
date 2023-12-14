#ifndef SIMPLE_FILE_SYSTEM_H
#define SIMPLE_FILE_SYSTEM_H

#include "AbstractFileSystem.h"
#include <map>
#include <set>

class SimpleFileSystem : public AbstractFileSystem {
private:
    std::map<std::string, AbstractFile*> filesMap;
    std::set<AbstractFile*> openFiles;

public:
    // Constructor and Destructor
    SimpleFileSystem();
    ~SimpleFileSystem() override;

    // Implementing AbstractFileSystem interface
    int addFile(const std::string& filename, AbstractFile* file) override;
    int createFile(const std::string& filename) override;
    int deleteFile(const std::string& filename) override;
    AbstractFile* openFile(const std::string& filename) override;
    int closeFile(AbstractFile* file) override;
    std::set<std::string> getFileNames() override;
};

#endif // SIMPLE_FILE_SYSTEM_H