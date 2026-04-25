o ---------------------------------------------------------------------------- o
| sesp: Sparse matrix library for the C programming language by Simon Euchner  |
o ---------------------------------------------------------------------------- o


LICENSE NOTICE.

    LICENSE: GPL-3.0

    IMPORTANT: THIS IS FREE SOFTWARE WITHOUT ANY WARRANTY. THE USER IS FREE TO
               MODIFY AND REDISTRIBUTE THIS SOFTWARE UNDER THE TERMS OF THE
               LICENSE LISTED ABOVE PUBLISHED BY THE FREE SOFTWARE FOUNDATION.
               THE PUBLISHER, SIMON EUCHNER, IS NOT RESPONSIBLE FOR ANY NEGATIVE
               EFFECTS THIS SOFTWARE MAY CAUSE.


Description.

    This small library provides some basic functionality to work with sparse
    matrices within C. However, there is also support for a dense matrix type.

    Note that this is a self-contained library. There is no intention to give a
    comprehensive BLAS implementation. Functionality is added as I need it.
    However, because of this library's simplicity, the user may easily include
    desired functionality.

    The whole library is written in native C using solely standard headers with
    respect to the standard C99.

    I have decided to go with a *one-function, one-file* architecture. This may
    seem uncommon, however, I made this decision as I believe it is a nice way
    to make searching for the source code of a particular function very easy.
    This also allows to just use the source code as documentation. The idea for
    this *many-files* approach is inspired by Dr. Timothy Alden Davis' sparse
    matrix library *CXSparse*.

    For questions/suggestions feel free to contact me via electronic mail:

        <euchner.se@gmail.com>

    As a last remark, it must be stated that it does only take very little
    functionality to make a library like this one practical, because with the
    help of a basic sparse matrix suite, packages like ARPACK, LAPACK, ...
    become directly usable.

    PS: I have designed the algorithms for matrix operations myself, so I am
        sure there is room for optimization ...


Contents.

    README.txt   ---    This README file
    Makefile     ---    Makefile to build the library
    src          ---    Source code directory
    inc          ---    Header for sesp
    obj          ---    Object code
    lib          ---    Place to store final shared library
    tst          ---    Quick testing
    bin          ---    Place to store binary resulting from quick testing


Installation.

    To get started, clone the GitHub repository from
    *https://github.com/simon-euchner/sesp*. Navigate to the root directory and
    execute the Makefile to build the library. The resulting shared object
    will be stored in the *lib* folder. To use sesp in your own projects, simply
    link against *-lsesp* and include the header file *inc/sesp.h*.
