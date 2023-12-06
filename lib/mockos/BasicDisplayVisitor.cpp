// Inside BasicDisplayVisitor.cpp
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include <iostream>

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
    for (int y = 0; y < static_cast<int>(imageFile->getSize()); ++y) {
        for (int x = 0; x < static_cast<int>(imageFile->getSize()); ++x) {
            char pixel = content[imageFile->coordToIndex(y, x)];
            std::cout << pixel << ' ';
        }
        std::cout << std::endl;
    }
}
