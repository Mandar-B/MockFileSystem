#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileVisitor.h"
#include "../include/mockos/Constants.h"
#include <iostream>
#include <string>

using namespace std;

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
    return OK;
}

int TextFile::append(const std::vector<char>& data) {
    contents.insert(contents.end(), data.begin(), data.end());
    return OK;
}

vector<char> TextFile::read() const {
    return contents;
}
void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}

AbstractFile* TextFile::copy(string n) const {
    string newname = n+".txt";


    TextFile* cp = new TextFile(newname);

    cp->write(read());
    return cp;
}
