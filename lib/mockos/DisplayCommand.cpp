#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void DisplayCommand::displayInfo() {
    cout << "ds" << endl;
}

int DisplayCommand::execute(std::string flags) {
    istringstream ss(flags);

    string src;

    if (!(ss >> src)) return NARGS;

    AbstractFile* srcf = file_system->openFile(src);

    AbstractFileVisitor* fv = new BasicDisplayVisitor();

    srcf->accept(fv);
    
    return OK;
}
