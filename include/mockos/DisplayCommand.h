#pragma once

#include "AbstractCommand.h"
class DisplayCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    DisplayCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
};