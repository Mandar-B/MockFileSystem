#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include "../include/mockos/CatCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void CatCommand::displayInfo() {
    cout << "cat " << endl;
}

int CatCommand::execute(std::string args) {
    if (args == "")
        return NARGS;

    istringstream ss(args);

    string fname;

    if (!(ss >> fname)) return SFAIL;

    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr)
        return UFILE;

    cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving and without -a, we don't append but overwrite the old contents" << endl;

    string flag;
    if (ss >> flag && flag == "-a") {
        const vector<char> contents = f->read();
        copy(contents.begin(), contents.end(), ostream_iterator<char>(std::cout, ""));
    }

    vector<char> file_data;
    
    string input;
    getline(cin, input);
    while (input != ":wq" && input != ":q") {
        copy(input.begin(), input.end(), back_inserter(file_data));
        file_data.push_back('\n');
        getline(cin, input);
    }

    if (input == ":wq") {
        if (flag == "-a") {
            vector<char> prev = f->read();
            copy(file_data.begin(), file_data.end(), back_inserter(prev));
            return f->write(prev);
        } else {
            return f->write(file_data);
        }
    }

    return OK;
}
