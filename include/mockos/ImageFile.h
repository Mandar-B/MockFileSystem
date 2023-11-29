#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include "AbstractFile.h"
#include <vector>
#include <string>

class ImageFile : public AbstractFile {
private:
    std::string fileName;
    std::vector<char> content;
    char imageSize;

public:
    // Constructor
    ImageFile(const std::string& name);

    // Destructor
    ~ImageFile() override;

    // Implementing AbstractFile interface
    unsigned int getSize() const override;
    std::string getName() const override;
    int write(const std::vector<char>& data) override;
    int append(const std::vector<char>& data) override;
    void read() const override;
    int coordToIndex(int x, int y) const;
};

#endif // IMAGE_FILE_H
