/* -------------------------------------------------------------------------- *
 *                                                                            *
 * This file is part of the SESP C-library by Simon Euchner.                  *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 *                                                                            *
 * LICENSE: GPL-3.0                                                           *
 *                                                                            *
 * IMPORTANT: THIS IS FREE SOFTWARE WITHOUT ANY WARRANTY. THE USER IS FREE TO *
 *            MODIFY AND REDISTRIBUTE THIS SOFTWARE UNDER THE TERMS OF THE    *
 *            LICENSE LISTED ABOVE PUBLISHED BY THE FREE SOFTWARE FOUNDATION. *
 *            THE PUBLISHER, SIMON EUCHNER, IS NOT RESPONSIBLE FOR ANY        *
 *            NEGATIVE EFFECTS THIS SOFTWARE MAY CAUSE.                       *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 *                                                                            *
 * Helper function for save functions                                         *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Write header to file
void filetop(FILE *fd,
             const char *fmt,
             SESP_INT nrow,
             SESP_INT ncol,
             SESP_INT nnz,
             double density) {
    fprintf(fd, "%s\n", "SESP");
    fprintf(fd, "FROMAT: %s\n", fmt);
    fprintf(fd, "SHAPE: %lu x %lu\n", (SESP_MAXINT)nrow, (SESP_MAXINT)ncol);
    fprintf(fd, "NNZ: %lu\n", (SESP_MAXINT)nnz);
    fprintf(fd, "DENSITY: %d %c\n\n", (int)(100*density), 37);
}
