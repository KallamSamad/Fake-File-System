#pragma once
#include <cstddef>
#include "FileObject.h"
class IndividualFile :
    public FileObject
{
public:
    IndividualFile(size_t bytes, const std::string& name);
    void display() const override;
    size_t getSize() const override { return bytes; }
private:
    size_t bytes;
 
};

