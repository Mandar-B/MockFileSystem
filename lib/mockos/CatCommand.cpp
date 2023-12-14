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
    std::cout << "cat <filename> [-a]" << std::endl;
}

int CatCommand::execute(std::string args) {
    if (args == "")
        return 1;

    std::istringstream ss(args);

    std::string fname;

    if (!(ss >> fname)) return 1;

    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr)
        return 1;

    std::cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving and without -a, we don't append but overwrite the old contents" << std::endl;

    std::string flag;
    if (ss >> flag && flag == "-a") {
        const std::vector<char> contents = f->read();
        std::copy(contents.begin(), contents.end(), std::ostream_iterator<char>(std::cout, ""));
        std::cout << std::endl;
    }

    std::vector<char> file_data;

    std::string input;
    getline(std::cin, input);
    while (input != ":wq" && input != ":q") {
        std::copy(input.begin(), input.end(), std::back_inserter(file_data));
        // Check if input ends with '\n' and remove it
        if (!input.empty() && input.back() == '\n') {
            file_data.pop_back();
        }
        file_data.push_back('\n');
        getline(std::cin, input);
    }
    int ret=0;
    if (input == ":wq") {
        // Remove the last '\n' character if present
        if (!file_data.empty() && file_data.back() == '\n') {
            file_data.pop_back();
        }

        if (flag == "-a") {
            std::vector<char> prev = f->read();
            std::copy(file_data.begin(), file_data.end(), std::back_inserter(prev));
            ret=f->write(prev);

        } else {
            ret= f->write(file_data);
        }

    }
file_system->closeFile(f);
    return ret;
}
