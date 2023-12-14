#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class DisplayCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    DisplayCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;
};