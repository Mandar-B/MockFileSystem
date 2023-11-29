#include "../include/mockos/TextFile.h"
#include <iostream>

TextFile::TextFile(string filename):name(filename){

}

unsigned int TextFile::getSize() const {
    return static_cast<unsigned int>(contents.size());
}

std::string TextFile::getName() const {
    return name;
}

int TextFile::write(const std::vector<char>& data) {
    contents = data;
    return 0;
}

int TextFile::append(const std::vector<char>& data) {
    contents.insert(contents.end(), data.begin(), data.end());
    return 0;
}

void TextFile::read() const {
    for (char c : contents) {
        std::cout << c;
    }
    std::cout << std::endl;
}

