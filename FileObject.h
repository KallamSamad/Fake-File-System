#pragma once
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
class FileObject
{
public:
	FileObject(const string& name);
	virtual ~FileObject()=default;
	void virtual display() const = 0;
	size_t virtual getSize() const = 0;
private:
	string name;
	chrono::system_clock::time_point timeCreated;
	chrono::system_clock::time_point timeModified;

};

