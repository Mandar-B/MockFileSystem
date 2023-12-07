// ABSTRACT_FILE_VISITOR_H

#pragma once

class TextFile;
class ImageFile;

class AbstractFileVisitor {
public:
    virtual ~AbstractFileVisitor() = default;  // Virtual destructor for proper polymorphic destruction

    virtual void visit_TextFile(TextFile* textFile) = 0;
    virtual void visit_ImageFile(ImageFile* imageFile) = 0;
    // Add additional virtual methods for each concrete file type

    // Example:
    // virtual void visit_AudioFile(AudioFile* audioFile) = 0;
};
