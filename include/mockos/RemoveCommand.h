#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;

public:
    RemoveCommand(AbstractFileSystem* sfs);
    void displayInfo() override;
    int execute(std::string) override;
};
