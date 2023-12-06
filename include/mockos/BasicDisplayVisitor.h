#pragma once

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    // Implementation of the visit functions for each concrete file type
    void visit_TextFile(TextFile* textFile) override;
    void visit_ImageFile(ImageFile* imageFile) override;
    // Add additional visit functions for other concrete file types if needed
};
