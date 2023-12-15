# Studio 17
1) Mandar Brahmbhatt, Nate Hayman
2) First, we created an image file and wrote a vector<char> to it. We then made sure it returned successfully by adding
a cout statement if the writeResult returned 0. We then displayed the content to make sure it correctly printed each 
pixel. Then we gave it purposefully invalid data, such as a missing, or incorrect size value and made sure the write was
not successful.
3) Utilizing interfaces as opposed to concrete classes has many benefits in regards to flexibility. It is much easier 
to switch between different implementations of that interface, especially when you have multiple implementations of a 
feature or component. Additionally, it is much easier to add new implementations in the future without altering 
older code.

4) You would need to extend the createFile method to handle the creation of this new type. Currently, createFile() 
can create either a TextFile or an ImageFile. You would also need to add a header class, much like TextFile.h and 
ImageFile.h (it should inherit from AbstractFile). You would have to include the new header file in 
SimpleFileSystem.cpp. You would also create MusicFile.cpp and add logic for the functions in the header file. 



