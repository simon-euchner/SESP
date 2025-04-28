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
 * Save DEN matrix                                                            *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Save DEN
void sesp_den_save(const char *file, const sesp_den *A) {
    FILE *fd; SESP_INT k;
    if (!(fd = fopen(file, "w"))) {
        printf("SESP: Cannot open file *%s* for writing\n", file);
        exit(1);
    }
    filetop(fd, "DEN", A->nrow, A->ncol, A->nnz, A->density);
    fprintf(fd,
            "%s %s %s %s\n\n",
            "ROW                ",
            "COL                ",
            "RE               ",
            "IM");
    for (k=0; k<A->nnz; k++) {
        fprintf(fd,
                "%19lu %19lu %+1.10E %+1.10E\n",
                (SESP_MAXINT)k/A->ncol,
                (SESP_MAXINT)k%A->ncol,
                creal(A->data[k]),
                cimag(A->data[k]));
    }
    fprintf(fd, "%c", '\n');
    fclose(fd);
}
