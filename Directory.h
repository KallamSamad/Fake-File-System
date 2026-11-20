#pragma once
#include "FileObject.h"
#include <cstddef>
class Directory :
    public FileObject
{
public:
    Directory(const string& name, size_t capacity=2);
    ~Directory();
    friend ostream& operator<<(ostream& os, const Directory& rhs);
    void display() const override;
    size_t getSize() const override;
    void add(FileObject* file);
    void resize();
private:
    FileObject** fileList = nullptr;
    size_t capacity=0;
    size_t count=0;
};

inline ostream& operator<<(ostream& os, const Directory& rhs)
{
    os << rhs.getName() << ": " << rhs.getSize() << " bytes\n";

    for (size_t i = 0; i < rhs.count; i++)
    {
        os << *rhs.fileList[i] << '\n';
    }

    return os;
}