#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand {
private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;

public:
    TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff);
    ~TouchCommand() override = default;

    void displayInfo() override;
    int execute(std::string) override;
};