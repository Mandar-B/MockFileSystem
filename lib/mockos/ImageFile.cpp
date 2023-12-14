#include "../include/mockos/ImageFile.h"
#include "../include/mockos/AbstractFileVisitor.h"
#include "../include/mockos/Constants.h"
#include <iostream>
#include <string>

using namespace std;


ImageFile::ImageFile(const std::string& name) : fileName(name), imageSize(0) {

}


ImageFile::~ImageFile() {

}

unsigned int ImageFile::getSize() const {
    return static_cast<unsigned int>(imageSize*imageSize);
}

std::string ImageFile::getName() const {
    return fileName;
}
int ImageFile::write(const std::vector<char>& data) {
    if (data.empty()) {
        contents.clear();
        imageSize = 0;
        return NDATA;
    }

    char sizeChar = data.back();
    int size = sizeChar-'0';

    if (size <= 0 || size * size + 1 != data.size()) {

        contents.clear();
        imageSize = 0;
        return NARGS;
    }

    // Check for valid pixels
    for (int i = 0; i < size * size; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {

            contents.clear();
            imageSize = 0;
            return UPIXL;
        }
    }


    contents.assign(data.begin(), data.end() - 1);


    imageSize = static_cast<char>(size);

    return OK;
}


int ImageFile::coordToIndex(int x, int y) const {
    return y * static_cast<int>(imageSize) + x;
}



int ImageFile::append(const std::vector<char>& data) {

    return 4;
}

std::vector<char> ImageFile::read() const {
    return contents;
}
void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::copy(string name) const {
    ImageFile* cp = new ImageFile(name+fileName.substr(fileName.find(".")));
    cp->write(read());
    return cp;
}