#pragma once

#include "ImageFile.h"
#include "TextFile.h"

class AbstractFileVisitor {
public:
    virtual void visit_ImageFile(ImageFile& f) = 0;
    virtual void visit_TextFile(TextFile& f) = 0;
};