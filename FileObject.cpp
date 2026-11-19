#include "FileObject.h"
#include <iostream>
#include <string>
#include <chrono>

FileObject::FileObject(const string& name) : name(name), timeCreated(chrono::system_clock::now()),
timeModified(timeCreated) {

}