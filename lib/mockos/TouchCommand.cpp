#include <iostream>
#include <string>
#include <sstream>

#include "../include/mockos/Constants.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/PermissionFile.h"

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
        : fileSystem(fs), fileFactory(ff) {}

void TouchCommand::displayInfo() {
    cout << "touch creates a file. use '-p' to create a password protected file and add any or all of 'r', 'w', or 'x' to the end of the command call to specify wheteher the file can be read, written to, or executed, respectfully (note that by default a file will have all of the permissions enabled). command format: touch <filename> [-p] [r][w][x]" << endl;
}

int TouchCommand::execute(string args) {
    if (args == "")
        return NARGS;

    istringstream ss(args);

    string fname;

    if (!(ss >> fname))return SFAIL;


    string flag;

    AbstractFile* f = fileFactory->createFile(fname);

    string perms = "";

    if (ss >> flag) {
        if (flag == "-p") {
            cout << "What is the password?" << endl;
            string pwd;
            cin >> pwd;
            f = new PasswordProxy(f, pwd);
            ss >> perms;
        } else {
            perms = flag;
        }
    }

    PermissionFile* fw = new PermissionFile(f);

    if (perms != "") {
        fw->setRead(false);
        fw->setWrite(false);
        fw->setExecute(false);
        for (char p : perms) {
            if (p == 'r') {
                fw->setRead(true);
            } else if (p == 'w') {
                fw->setWrite(true);
            } else if (p == 'x') {
                fw->setExecute(true);
            }
        }
    }

    if (f == nullptr || fw == nullptr)
        return NFILE;

    return fileSystem->addFile(fname, fw);
}