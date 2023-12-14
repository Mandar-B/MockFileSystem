#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileVisitor.h"
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
    return 0;
}

int TextFile::append(const std::vector<char>& data) {
    contents.insert(contents.end(), data.begin(), data.end());
    return 0;
}

vector<char> TextFile::read() const {
    return contents;
}
void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}

AbstractFile* TextFile::copy(string n) const {
    TextFile* cp = new TextFile(n+name.substr(name.find(".")));
    cp->write(read());
    return cp;
}
