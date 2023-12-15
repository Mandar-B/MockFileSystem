enum codes {
    // universal error codes
    OK   ,  // 200
    QUIT ,  // program exited
    NARGS,  // incorrect arguments
    SFAIL,  // string extraction failure
    NFLAG,  // unrecognized flag
    NFILE,  // could not create a file
    UFILE,  // undefined file / no file found
    PXWRT,  // proxy write failure
    PXAPP,  // proxy append failure
    FCLSD,  // could not open file
    NODEL,  // could not delete file
    UEXTN,  // unsupported file extension
    UFLFM,  // unrecognized file format
    FLEXI,  // file already exists; cannot create
    FLOPN,  // file open during deltion
    COPFL,  // file copy failure
    CMDIN,  // command insertion failure
    NDATA,  // no provided data to write
    UPIXL,  // unsupported pixel type
    DEP  ,  // deprecated
    NWRIT,  // write permission failure
    NEXEC,  // execute permission failure

};

const int FNAME_WIDTH = 20;