# Studio 18

1. Nate Hayman, Mandar Brahmbhatt
2. It would be relatively easy to implemenet a new file system by simply extending the AbstractFileSystem class and ensuring that it maintains a common interface. A concrete file type used by multiple different file systems would be implmeneted similarly, ensuring it maintains a common partition as neeeded by the file systems that utilize it
3. Yes, the same factory can be used for two different file systems which contain the same types of files since the only dependence of the file factory is on the AbstractFile class, not any file system. In the case of two file systems with different types of files, one concrete file factory could technically be used for both, so long as its `createFile()` method accounts for all types of files, from both file systems
4. TODO: give output for opening, writing, and reading a few created files
5. Only AbstractFile's interface