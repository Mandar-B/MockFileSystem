#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void CopyCommand::displayInfo() {
    cout << "ls displays all files in the current directory. Add the `-m` flag to display the metadata of each file" << endl;
}

int CopyCommand::execute(std::string flags) {
    istringstream ss(flags);

    string src;
    string dest;

    if (!(ss >> src)) return NARGS;
    if (!(ss >> dest)) return NARGS;

    AbstractFile* srcf = file_system->openFile(src);
    AbstractFile* destf = srcf->copy(dest);

    file_system->addFile(destf->getName(), destf);

    return OK;
}
