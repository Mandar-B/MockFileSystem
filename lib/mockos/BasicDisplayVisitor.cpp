#include <iostream>
#include <vector>

#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"

void BasicDisplayVisitor::visit_ImageFile(ImageFile& f) {
    std::vector<char> content = f.read();
    for (int y = 0; y < static_cast<int>(f.getSize()); ++y) {
        for (int x = 0; x < static_cast<int>(f.getSize()); ++x) {
            char pixel = content[f.coordToIndex(x, y)];
            std::cout << pixel << ' ';
        }
        std::cout << std::endl;
    }
}
void BasicDisplayVisitor::visit_TextFile(TextFile& f) {
    std::vector<char> content = f.read();
    for (char c : content) {
        std::cout << c;
    }
    std::cout << std::endl;
}