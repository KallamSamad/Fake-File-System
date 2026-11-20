#include "FileObject.h"
#include <iostream>
#include <string>
#include <chrono>

FileObject::FileObject(const string& name, TimePoint created, TimePoint modified)
    : name(name),
    timeCreated(created),
    timeModified(modified)
{
}

FileObject::FileObject(const string& name)
    : name(name),
    timeCreated(chrono::system_clock::now()),
    timeModified(timeCreated)
{
}

ostream& operator<<(ostream& os, const FileObject& rhs)
{
    rhs.display();
    return os;
}