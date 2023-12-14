#include <iostream>
#include <string>
#include <sstream>

#include "../include/mockos/Constants.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/PasswordProxy.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
        : fileSystem(fs), fileFactory(ff) {}

void TouchCommand::displayInfo() {
    cout << "touch creates a file, touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string args) {
    if (args == "")
        return NARGS;

    istringstream ss(args);

    string fname;

    if (!(ss >> fname))return SFAIL;


    string flag;

    AbstractFile* f = fileFactory->createFile(fname);

    if (ss >> flag) {
        if (flag == "-p") {
            cout << "What is the password?" << endl;
            string pwd;
            cin >> pwd;
            f = new PasswordProxy(f, pwd);
        } else return NFLAG;
    }

    if (f == nullptr)
        return NFILE;

    return fileSystem->addFile(f->getName(), f);
}