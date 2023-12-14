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

int main() {
    CommandPrompt cmd;

    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();
    cmd.setFileSystem(fs);
    cmd.setFileFactory(ff);

    CatCommand* cat = new CatCommand(fs);
    DisplayCommand* ds = new DisplayCommand(fs);
    CopyCommand* cp = new CopyCommand(fs);
    RemoveCommand* rm = new RemoveCommand(fs);
    LSCommand* ls = new LSCommand(fs);
    TouchCommand* touch = new TouchCommand(fs, ff);

    MacroCommand* rn = new MacroCommand(fs);
    RenameParsingStrategy* rnps = new RenameParsingStrategy();
    rn->setParseStrategy(rnps);
    rn->addCommand(cp);
    rn->addCommand(rm);

    MacroCommand* gen = new MacroCommand(fs);
    GenerateParsingStrategy* genps = new GenerateParsingStrategy();
    gen->setParseStrategy(genps);
    gen->addCommand(cp);
    gen->addCommand(rm);

    cmd.addCommand("cp", cp);
    cmd.addCommand("ds", ds);
    cmd.addCommand("cat", cat);
    cmd.addCommand("rm", rm);
    cmd.addCommand("ls", ls);
    cmd.addCommand("touch", touch);
    cmd.addCommand("rn", rn);
    cmd.addCommand("gen", gen);

    return cmd.run();
}