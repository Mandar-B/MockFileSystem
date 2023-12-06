# Studio 20
1. Nate Hayman
2. `PasswordProxy` requires a pointer to an `AbstractFile` to represent the file. If the file representation is a pointer, simply letting the pointer go out of scope is not enough to remove the data of the underlying file, instead we must explicitly delete the data associated with the pointer
3. --
4. Tested reading, writing, getting name, getting size, accepting a visitor all with correct and incorrect passwords
5. 