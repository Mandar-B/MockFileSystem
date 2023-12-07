#include <iostream>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"

#include "mockos/SimpleFileSystem.h"
#include <iostream>

int main() {
    // Create TextFile

        // Create TextFile and ImageFile
        TextFile textFile("example.txt");
        ImageFile imageFile("example.img");

        // Create MetadataDisplayVisitor
        MetadataDisplayVisitor metadataDisplayVisitor;

        // Test by calling accept on the file objects
        textFile.accept(&metadataDisplayVisitor);
        imageFile.accept(&metadataDisplayVisitor);

        return 0;

}