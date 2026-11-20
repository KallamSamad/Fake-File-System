#pragma once
#include <iostream>
#include <fstream>
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"
class Storage
{
public:

	void save(const Directory& root);
};

