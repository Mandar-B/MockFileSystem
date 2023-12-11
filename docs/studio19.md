# Studio 19

1. Nate Hayman
2. Tested if file was properly written to after rewrite and if contents persisted after second read call for multiple content inputs
3. The visitor is utilized by calling the accept method of the class, which in turn calls the proper visit function and hands control over to some external class. This allows for significant extension of the base class outside of the class, with only a small entry point for initializing contact
4. Delegation is the concept of calling a method or evaluating a property with reference to a separate object. This is most obviously employed by inheritance, but the visitor pattern also utilizes it to allow a visitor method to view and control its visited class. This allows for minimization of clutter because the functionality of a visitor method, which is structurally and logically separate from the definition of the visited class, does not have to be implemented in the class itself
5. The visitor pattern must contain a definition for *every* concrete file type, and thus may not be appropriate for problems which require more generic approaches