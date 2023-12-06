# Studio 19

1. Nate Hayman
2. Tested if file was properly written to after rewrite and if contents persisted after second read call for multiple content inputs
3. The visitor is utilized by calling the accept method of the class, which in turn calls the proper visit function and hands control over to some external class. This allows for significant extension of the base class outside of the class, with only a small entry point for initializing contact
4. TODO: discuss delegation
5. The visitor pattern must contain a definition for *every* concrete file type, and thus may not be appropriate for problems which require more generic approaches