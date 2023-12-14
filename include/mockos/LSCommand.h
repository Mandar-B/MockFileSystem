#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
    void displayMetadata(const std::string& fileName);
    void displayFileName(const std::string& fileName, int index);
public:
    LSCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;

};
