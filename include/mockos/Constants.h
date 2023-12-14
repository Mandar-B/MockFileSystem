enum codes {
    // universal error codes
    OK,     // 200
    NARGS,  // incorrect arguments
    SFAIL,  // string extraction failure
    NFLAG,  // unrecognized flag
    NFILE,  // could not create a file
    UFILE,  // undefined file / no file found
};

const int FNAME_WIDTH = 20;