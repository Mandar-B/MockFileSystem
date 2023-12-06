#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include <iostream>

// Constructor
MetadataDisplayVisitor::MetadataDisplayVisitor() {}

// Destructor
MetadataDisplayVisitor::~MetadataDisplayVisitor() {}

// Implement visit method for TextFile
void MetadataDisplayVisitor::visit_TextFile(TextFile* textFile) {
    std::cout << "Metadata for TextFile:" << std::endl;
    std::cout << "Name: " << textFile->getName() << std::endl;
    std::cout << "Size: " << textFile->getSize() << " bytes" << std::endl;
    std::cout << "Type: text" << std::endl;
    std::cout << std::endl;
}

// Implement visit method for ImageFile
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {
    std::cout << "Metadata for ImageFile:" << std::endl;
    std::cout << "Name: " << imageFile->getName() << std::endl;
    std::cout << "Size: " << imageFile->getSize() << " bytes" << std::endl;
    std::cout << "Type: image" << std::endl;
    std::cout << std::endl;
}

// Implement other methods if needed
