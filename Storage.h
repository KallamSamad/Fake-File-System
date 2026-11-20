#pragma once
#include <iostream>
#include <fstream>
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"

using namespace std;

class Storage
{
public:
    static void save(const Directory& root);
    static void load(Directory& root);
private:
   static void saveDirectory(const Directory& directory, ofstream& file);
};