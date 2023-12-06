#include <iostream>

#include "../include/mockos/ImageFile.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

void MetadataDisplayVisitor::visit_ImageFile(ImageFile& f) {
    std::cout << "Name: " << f.getName() << ", Size: " << f.getSize() << ", Type: image" << endl;
}

void MetadataDisplayVisitor::visit_TextFile(TextFile& f) {
    std::cout << "Name: " << f.getName() << ", Size: " << f.getSize() << ", Type: text" << endl;
}