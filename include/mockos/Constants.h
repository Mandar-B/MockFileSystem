enum codes {
    // universal error codes
    OK,     // 200
    QUIT,   // program exited
    NARGS,  // incorrect arguments
    SFAIL,  // string extraction failure
    NFLAG,  // unrecognized flag
    NFILE,  // could not create a file
    UFILE,  // undefined file / no file found
    NOCMD,  // could not add command
    PXWRT,  // proxy write failure
    PXAPP,  // proxy append failure
    FCLSD,  // could not open file
    NODEL,  // could not delete file
    UEXTN,  // unsupported file extension
    UFLFM,  // unrecognized file format
    FLEXI,  // file already exists; cannot create
};

const int FNAME_WIDTH = 20;