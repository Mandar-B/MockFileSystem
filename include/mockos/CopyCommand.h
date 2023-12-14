#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
    AbstractFile* copyFile(const std::string& originalName, const std::string& newName);
public:
    CopyCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;
};