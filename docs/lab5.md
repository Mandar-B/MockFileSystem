# Lab 5

Group members: Mandar Brahmbhatt, Nate Hayman

Notes / Disclaimers:
- The `ChmodCommand` class employs a dynamic cast to deal with the fact that the file system presents `AbstractFile`s rather than the `PermissionFile` that all files in the file system implement


Work was split evenly, with a handful of commands being developed asynchronously and the rest being developed together in person

- Testing of `touch`:
  - `-d` flag was not properly implemented intitially so we had to go back and fix it
  - extra space at the beginning of the parameter string was causing issues, `istringstream` fixed the problem

- Testing of `ls`:
  - `-m` flag was displaying the basic `ls` command output instead of the indended metadata; this was resolved by properly using an `istringstream`

- Testing of `ds`:
  - Issues with displaying image files that were resolved by tweaking the visitor call

- Testing of `cat`:
  - No major issues
  
- Testing of `remove`:
  - No major issues

- Testing of `cp`:
  - Issue with not properly adding the file extension to the end of the destination file

- Testing of `rn`:
  - Issue with deleting the `RenameParsingStrategy` pointer while it was being used by the macro command

- Testing of `gen`:
  - Issue with paramter to string vector conversion

Each of the above commands were tested in a variety of different combinations, in chains of command calls, with all available flags tested individually, and unexpected user behavior such as incorrect numbers of arguments and strange parameters / actions tested

Extra credit completion was the implementation of a `chmod` command which emulates the behavior of the classic Linux command. We chose to represent the "read" permission as the ability to call `AbstractFile->read()`, the "write" permission as `AbstractFile->write()`, and the "execute" permission as `BasicDisplayVisitor->visit_xxxxFile`