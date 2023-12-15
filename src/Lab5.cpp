#include "../include/mockos/Constants.h";
#include "../include/mockos/CommandPrompt.h";
#include "../include/mockos/CatCommand.h";
#include "../include/mockos/SimpleFileSystem.h";
#include "../include/mockos/SimpleFileFactory.h";
#include "../include/mockos/MacroCommand.h";
#include "../include/mockos/CopyCommand.h";
#include "../include/mockos/RemoveCommand.h";
#include "../include/mockos/LSCommand.h";
#include "../include/mockos/TouchCommand.h";
#include "../include/mockos/DisplayCommand.h";
#include "../include/mockos/RenameParsingStrategy.h";
#include "../include/mockos/GenerateParsingStrategy.h";
#include "../include/mockos/PermissionFile.h"

int main() {
    CommandPrompt cmd;

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    cmd.setFileSystem(fs);
    cmd.setFileFactory(ff);

    CatCommand cat (fs);
    DisplayCommand ds (fs);
    CopyCommand cp (fs);
    RemoveCommand rm (fs);
    LSCommand ls (fs);
    TouchCommand touch (fs, ff);

    MacroCommand* rn = new MacroCommand(fs);
    RenameParsingStrategy* rnps = new RenameParsingStrategy();
    rn->setParseStrategy(rnps);
    rn->addCommand(&cp);
    rn->addCommand(&rm);
     // collect resources

    // Create file, edit it, and display it
    MacroCommand* gen = new MacroCommand(fs);
    GenerateParsingStrategy* genps = new GenerateParsingStrategy();
    gen->setParseStrategy(genps);
    gen->addCommand(&touch);
    gen->addCommand(&cat);
    gen->addCommand(&ds);
     // collect resources

    cmd.addCommand("cp", &cp);
    cmd.addCommand("ds", &ds);
    cmd.addCommand("cat", &cat);
    cmd.addCommand("rm", &rm);
    cmd.addCommand("ls", &ls);
    cmd.addCommand("touch", &touch);
    cmd.addCommand("rn", rn);
    cmd.addCommand("gen", gen);

    int ret = cmd.run();

    // We need to properly delete resources
    delete fs;
    delete ff;
    // Commands will be deleted when CommandPrompt is automatically destroyed
    delete rnps;
    delete genps;
    return ret;
}