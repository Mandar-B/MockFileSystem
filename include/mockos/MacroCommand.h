#pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
class MacroCommand : public AbstractCommand {
private:
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* strategy;
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    MacroCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
    void addCommand(AbstractCommand*);
    void setParseStrategy(AbstractParsingStrategy*);
};