o ---------------------------------------------------------------------------- o
| SESP (Simon Euchner Sparse): A sparse matrix library for the C programming   |
| language.                                                                    |
|                                                                              |
| This small library provides some basic functionality to work with sparse     |
| matrices within C. However, there is also support for a dense matrix type.   |
|                                                                              |
| Note that this is a self-contained library. There is no intention to give a  |
| comprehensive BLAS implementation. Functionality is added as I need it.      |
| However, because of this libraries simplicity, the user may easily include   |
| desired functionability.                                                     |
|                                                                              |
| The whole library is written in native C using solely standard headers with  |
| respect to the standard C99.                                                 |
|                                                                              |
| I have decided to go with a *one-function, one-file* architecture. This may  |
| seem uncommon, however, I made this decision as I believe it is a nice way   |
| to make searching for the source code of a particular function very easy.    |
| This also allows to just use the source code as documentation. The idea for  |
| this *many-files* approach is inspired by Dr. Timothy Alden Davis' sparse    |
| matrix library *CXSparse*.                                                   |
|                                                                              |
| For questions/suggestions feel free to contanct me via electronic mail:      |
|                                                                              |
|     <euchner.se@gmail.com>                                                   |
|                                                                              |
| As a last remark, it must be stated that it does only take very little       |
| functionality to make a library like this one practial, becuase              |
| with the help of a basic sparse matrix suite, packages like ARPACK, LAPACK,  |
| ... become directly usable.                                                  |
|                                                                              |
| PS: I have designed the algorithms for matrix operations myself, so I am     |
|     sure there is room for optimization ...                                  |
o ---------------------------------------------------------------------------- o


LICENSE NOTICE.

    LICENSE: GPL-3.0

    IMPORTANT: THIS IS FREE SOFTWARE WITHOUT ANY WARRANTY. THE USER IS FREE TO
               MODIFY AND REDISTRIBUTE THIS SOFTWARE UNDER THE TERMS OF THE
               LICENSE LISTED ABOVE PUBLISHED BY THE FREE SOFTWARE FOUNDATION.
               THE PUBLISHER, SIMON EUCHNER, IS NOT RESPONSIBLE FOR ANY NEGATIVE
               EFFECTS THIS SOFTWARE MAY CAUSE.


Contents.

    README.txt   ---    This README file
    Makefile     ---    Makefile to build library
    src.d        ---    Sorce code directory
    inc.d        ---    Header for SESP
    obj.d        ---    Object code
    lib.d        ---    Place to store final shared library
    tst.d        ---    Quick testing
        main.c   ------ File for testing
    bin.d        ---    Place to store binary resulting from quick testing


Installation.

    Get the latest release of *https://github.com/simon-euchner/sesp* and unpack
    the archive.

    Now run the Makefile in the main directory. The shared object is saved in
    *lib.d*. If you link against *-lsesp* and include the single header
    file *inc.d/sesp.h*, you are good to go.
