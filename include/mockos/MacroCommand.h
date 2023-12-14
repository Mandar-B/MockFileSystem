#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class MacroCommand : public AbstractCommand {
private:
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* strategy;
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    MacroCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;
    void addCommand(AbstractCommand*);
    void setParseStrategy(AbstractParsingStrategy*);
};