#pragma once
#include <cstddef>
#include "FileObject.h"
class IndividualFile :
    public FileObject
{
public:
    IndividualFile(size_t bytes, const std::string& name);
    friend ostream& operator<<(ostream& os, const IndividualFile& rhs);
    size_t getSize() const override { return bytes; }
    void display() const override;
    bool isDirectory() const;


private:
    size_t bytes;
 
};

inline ostream& operator<<(ostream& os, const IndividualFile& rhs)
{

    os << rhs.getName() << ":" << rhs.getSize() << " bytes\n";
    return os;
}
