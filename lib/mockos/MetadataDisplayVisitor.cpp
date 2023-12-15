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
    string name = textFile->getName();

    std::cout << name;
    std::cout << " text ";
    std::cout << textFile->getSize() <<  std::endl;


}

// Implement visit method for ImageFile
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imageFile) {

    std::cout << imageFile->getName();
    std::cout << " image ";
    std::cout <<  imageFile->getSize();

    std::cout << std::endl;
}

// Implement other methods if needed