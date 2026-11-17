============================================== PLAN =============================================================



Goal - To make a fake file system; like a knock off version of command prompt







\------------------------------------------Commands needed--------------------------------------------------------





dir - "list the files and directories in the current directory and in the order they are currently held in your data structure" it "must include a summary that shows total bytes, number of files and number of directories present in that folder"



Entities Involved here  (translate them into classes):



* FileObject - An abstract class  

  * private: string name
  * public: pure virtual display (using overloaded ostream operators), pure virtual getSize (size\_t because >=0);
* IndividualFile - a polymorphic pointer array of the File object

  * Child of FileObject
  * private: size\_t bytes
  * public: Overrides display and getSize



* Directory - A single directory object, manages its children
* 

  * Child of FileObject
  * private: Directories - a Polymorphic pointer array of FileObject objects (FileObject\*\* files), because I need an array-like container that stores multiple types
  * Uses dynamic casting OR typeID to count the number of files
  * public: Overrides display, getSize - for one directory and for cumulative too, adds, removes, deletes and searches for filesystem objects using the polymorphic pointer array





Unsure how to order in data structure, unless I use something from the STL y then link DSA stuff so vector would be good, but then the issue is I wouldn't be able to use the polymorphic array. Actually I can preserve order simply by not sorting the array and leaving it.

