#pragma once

#include "AbstractCommand.h"
class CopyCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    CopyCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
};