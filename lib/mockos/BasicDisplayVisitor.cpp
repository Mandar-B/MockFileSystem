// Inside BasicDisplayVisitor.cpp
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include <iostream>
#include <cmath>

// Implementation of the visit functions for each concrete file type
void BasicDisplayVisitor::visit_TextFile(TextFile* textFile) {
    std::vector<char> content = textFile->read();
    for (char c : content) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
    std::vector<char> content = imageFile->read();
    int imageSize = static_cast<int>(std::sqrt(imageFile->getSize())); // Assuming square image
    for (int y = 0; y < imageSize; ++y) {
        for (int x = 0; x < imageSize; ++x) {
            char pixel = content[imageFile->coordToIndex(x, y)];
            std::cout << pixel << ' ';
        }
        std::cout << std::endl;
    }
}



