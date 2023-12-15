#include <iostream>
#include <vector>

#include "../include/mockos/PermissionFile.h"
#include "../include/mockos/Constants.h"

using namespace std;

PermissionFile::PermissionFile(AbstractFile* fp)
  : file_ptr(fp), can_write(true), can_read(true), can_execute(true) {

}

PermissionFile::PermissionFile(AbstractFile* fp, bool cwrite, bool cread, bool cexecute)
  : file_ptr(fp), can_write(cwrite), can_read(cread), can_execute(cexecute) {

}

PermissionFile::~PermissionFile() {
    delete file_ptr;
}

unsigned int PermissionFile::getSize() const {
    return file_ptr->getSize();
}

string PermissionFile::getName() const {
    return file_ptr->getName();
}

int PermissionFile::write(const vector<char>& data) {
    if (can_write) {
        return file_ptr->write(data);
    } else {
        cout << "Permission error: you do not have permission to write to this file!" << endl;
        return NWRIT;
    }
}

int PermissionFile::append(const vector<char>& data) {
    if (can_write) {
        return file_ptr->append(data);
    } else {
        cout << "Permission error: you do not have permission to write to this file!" << endl;
        return NWRIT;
    }
}

vector<char> PermissionFile::read() const {
    if (can_read) {
        return file_ptr->read();
    } else {
        cout << "Permission error: you do not have permission to read or copy this file!" << endl;
        return vector<char>();
    }
}

void PermissionFile::accept(AbstractFileVisitor* fv) {
    if (can_execute) {
        return file_ptr->accept(fv);
    } else {
        cout << "Permission error: you do not have permission to execute this file!" << endl;
    }
}

AbstractFile* PermissionFile::copy(string dest) const {
    if (can_read) {
        AbstractFile* nf = file_ptr->copy(dest);
        PermissionFile* cp = new PermissionFile(nf, can_write, can_read, can_execute);
        return file_ptr->copy(dest);
    } else {
        cout << "Permission error: you do not have permission to read or copy this file!" << endl;
    }
}

void PermissionFile::setWrite(bool cwrite) {
    can_write = cwrite;
}

void PermissionFile::setRead(bool cread) {
    can_read = cread;
}

void PermissionFile::setExecute(bool cexecute) {
    can_execute = cexecute;
}
