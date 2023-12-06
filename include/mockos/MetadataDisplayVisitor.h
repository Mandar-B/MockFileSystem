#pragma once

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
    // Constructor
    MetadataDisplayVisitor();

    // Destructor
    ~MetadataDisplayVisitor() override;

    // Implement visit method for TextFile
    void visit_TextFile(TextFile* textFile) override;

    // Implement visit method for ImageFile
    void visit_ImageFile(ImageFile* imageFile) override;

    // Implement other methods if needed
};
