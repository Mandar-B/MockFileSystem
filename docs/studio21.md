# Studio 21
1. Nate Hayman, Mandar Brahmbhatt
2. If the base class did not have a destructor explicitly marked virtual, the compiler would call the default destructor of AbstractCommand whenever a command object is destroyed, which would fail to call the proper destructor of the derived class and potentially result in a memory leak
3. Since the command prompt only requires the most abstract interface of the file system and file factory (AbstractFileSystem and AbstractFileFactory), it implicitly supports any file system or file factory which inherits from those common interfaces and the simple pair used currently can be swapped without any changes to the CommandPrompt class
4. TODO: test studio 21