#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

#include "../include/mockos/CatCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* fs) : file_system(fs) {}

void CatCommand::displayInfo() {
    cout << "cat <filename> [-a]" << endl;
}

int CatCommand::execute(string args) {
    if (args == "") return NARGS;

    istringstream ss(args);

    string fname;

    if (!(ss >> fname)) return NARGS;

    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr) return UFILE;

    cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving and without -a, we don't append but overwrite the old contents" << endl;

    string flag;
    if (ss >> flag && flag == "-a") {
        const vector<char> contents = f->read();
        copy(contents.begin(), contents.end(), ostream_iterator<char>(cout, ""));
        cout << endl;
    }

    vector<char> file_data;

    string input;
    getline(cin, input);
    while (input != ":wq" && input != ":q") {
        copy(input.begin(), input.end(), back_inserter(file_data));
        // Check if input ends with '\n' and remove it
        if (!input.empty() && input.back() == '\n') {
            file_data.pop_back();
        }
        file_data.push_back('\n');
        getline(cin, input);
    }
    int ret = OK;
    if (input == ":wq") {
        // Remove the last '\n' character if present
        if (!file_data.empty() && file_data.back() == '\n') {
            file_data.pop_back();
        }

        if (flag == "-a") {
            vector<char> prev = f->read();
            copy(file_data.begin(), file_data.end(), back_inserter(prev));
            ret=f->write(prev);

        } else {
            ret= f->write(file_data);
        }

    }
    
    file_system->closeFile(f);

    return ret;
}
