#pragma once

#include "AbstractCommand.h"
class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
};