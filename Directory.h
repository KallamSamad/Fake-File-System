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
    void display(ostream& os) const;
    size_t getSize() const override;
    Directory(const string& name, TimePoint created, TimePoint modified);
    bool isDirectory() const override;
    void add(FileObject* file);
    FileObject* getFile(size_t index) const;
    size_t getCount() const;
    void clear();
private:
    FileObject** fileList = nullptr;
    size_t capacity=0;
    size_t count=0;
    void resize();
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