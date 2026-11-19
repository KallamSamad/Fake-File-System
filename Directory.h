#pragma once
#include "FileObject.h"
#include <cstddef>
class Directory :
    public FileObject
{
public:
    Directory();
    ~Directory();
    void display() const override;
    size_t getSize() const override;
private:
    FileObject** fileList = nullptr;
    size_t capacity=0;
    size_t count=0;
};