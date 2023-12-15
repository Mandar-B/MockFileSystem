#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ostream>
#include <iterator>

#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "../include/mockos/BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fs)
        : file_system(fs) {

}

void DisplayCommand::displayInfo() {
    cout << "ds <filename> [-d]" << endl;
}

int DisplayCommand::execute(string args) {
    if (args == "") return NARGS;

    istringstream ss(args);

    string fname;


    if (!(ss >> fname)) return NARGS;

    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr) {
        cout << "Failed to open file" << endl;
        return UFILE;
    }

    string flag;
    ss >> flag;

    if (flag == "-d") {
        // Display unformatted data only
        vector<char> contents = f->read();
        copy(contents.begin(), contents.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    } else {
        // Display formatted contents

        AbstractFileVisitor* fv = new BasicDisplayVisitor();
        f->accept(fv);
    }

    file_system->closeFile(f);

    return OK;
}