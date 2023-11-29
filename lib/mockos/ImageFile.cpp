#include "../include/mockos/ImageFile.h"

#include <iostream>


ImageFile::ImageFile(const std::string& name) : fileName(name), imageSize(0) {

}


ImageFile::~ImageFile() {

}

unsigned int ImageFile::getSize() const {
    return static_cast<unsigned int>(imageSize);
}

std::string ImageFile::getName() const {
    return fileName;
}
int ImageFile::write(const std::vector<char>& data) {
    if (data.empty()) {
        content.clear();
        imageSize = 0;
        return 1;
    }

    char sizeChar = data.back();
    int size = static_cast<int>(sizeChar) - static_cast<int>('0');

    if (size <= 0 || size * size + 1 != data.size()) {

        content.clear();
        imageSize = 0;
        return 2;
    }

    // Check for valid pixels
    for (int i = 0; i < size * size; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {

            content.clear();
            imageSize = 0;
            return 3;
        }
    }


    content.assign(data.begin(), data.end() - 1);


    imageSize = static_cast<char>(size);

    return 0;
}


int ImageFile::coordToIndex(int x, int y) const {
    return y * static_cast<int>(imageSize) + x;
}



int ImageFile::append(const std::vector<char>& data) {

    return 4;
}

void ImageFile::read() const {

    for (int y = 0; y < static_cast<int>(imageSize); ++y) {
        for (int x = 0; x < static_cast<int>(imageSize); ++x) {
            char pixel = content[coordToIndex(x, y)];
            std::cout << pixel << ' ';
        }
        std::cout << std::endl;
    }
}
