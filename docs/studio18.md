# Studio 18

1. Nate Hayman, Mandar Brahmbhatt
2. It would be relatively easy to implemenet a new file system by simply extending the AbstractFileSystem class and ensuring that it maintains a common interface. A concrete file type used by multiple different file systems would be implmeneted similarly, ensuring it maintains a common partition as neeeded by the file systems that utilize it
3. Yes, the same factory can be used for two different file systems which contain the same types of files since the only dependence of the file factory is on the AbstractFile class, not any file system. In the case of two file systems with different types of files, one concrete file factory could technically be used for both, so long as its `createFile()` method accounts for all types of files, from both file systems
4. In the test we create  a new SimpleFileSystem and dynamically allocate an AbstractFileSystem pointer 
pointing to it. We then run various tests. We create and add a text file and added a cout statmetn if it was successful.
We then create an invalid file to make sure we get an error. We then open the file and cout a statement of successful. 
We also open a file that does not exist to make sure we get an error there. We then close the file, using a similar cout
statment if the program was successful. We also close a nonexsistent file and make sure we get an error.
5. Only AbstractFile's interface