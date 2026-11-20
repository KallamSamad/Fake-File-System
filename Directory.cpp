#include "Directory.h"

Directory::Directory(const std::string& name, size_t capacity)
    : FileObject(name), capacity(capacity)
{
    fileList = new FileObject * [capacity]();
}

Directory::~Directory()
{

    for (int i = 0; i < count; i++) {
        delete fileList[i];
    }
    delete[] fileList;
}

size_t Directory::getSize() const
{
    size_t totalSize = 0;

    for (size_t i = 0; i < count; i++)
    {
        totalSize += fileList[i]->getSize();
    }

    return totalSize;
}

void Directory::display() const
{
    cout << *this;
}

void Directory::add(FileObject* file) {

    if (count == capacity) {
        resize();
    }
   

        fileList[count] = file;
        count++;
    
   
}

void Directory::resize() {
    capacity = capacity * 2;
    FileObject** newArray = new FileObject*[capacity]();

    for (int i = 0; i < count; i++) {
        newArray[i] = fileList[i];
    }
    delete[] fileList;
    fileList = newArray;


}
