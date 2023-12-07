#include <iostream>
#include <string>

#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem*, AbstractFileFactory*) {

}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string filename) {
    AbstractFile* f = file_factory->createFile(filename);

    if (f == nullptr)
        return 1;

    return file_system->addFile(f->getName(), f);
}
