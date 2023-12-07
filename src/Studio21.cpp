#include <iostream>
#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/TouchCommand.h"

int main() {
    SimpleFileSystem* fs = new SimpleFileSystem();
    SimpleFileFactory* ff = new SimpleFileFactory();
    TouchCommand* tc = new TouchCommand(fs, ff);

    CommandPrompt cmd_prompt;
    cmd_prompt.setFileSystem(fs);
    cmd_prompt.setFileFactory(ff);
    cmd_prompt.addCommand("touch", tc);

    cmd_prompt.run();

    fs->openFile("example.txt");

    return 0;
}
