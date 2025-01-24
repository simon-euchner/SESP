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
 * Save CSC matrix                                                            *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Save CSC
void sesp_csc_save(const char *file, const sesp_csc *A) {
    FILE *fd; INT k, max;
    if (!(fd = fopen(file, "w"))) {
        printf("SESP: Cannot open file *%s* for writing\n", file);
        exit(1);
    }
    filetop(fd, "CSC", A->nrow, A->ncol, A->nnz, A->density);
    if (A->nnz > A->ncol+1) max = A->nnz; else max = A->ncol+1;
    fprintf(fd,
            "%s %s %s %s\n\n",
            "ROW                ",
            "COLP               ",
            "RE               ",
            "IM");
    for (k=0; k<max; k++) {
        if ((k<A->nnz) && (k<A->ncol+1)) {
            fprintf(fd,
                    "%19lu %19lu %+1.10E %+1.10E\n",
                    (INT_M)A->rowis[k],
                    (INT_M)A->colps[k],
                    creal(A->data[k]),
                    cimag(A->data[k]));
            continue;
        }
        if ((k>=A->nnz) && (k<A->ncol+1)) {
            fprintf(fd,
                    "                    %19lu\n",
                    (INT_M)A->colps[k]);
            continue;
        }
        if ((k<A->nnz) && (k>=A->ncol+1)) {
            fprintf(fd,
                    "%19lu                     %+1.10E %+1.10E\n",
                    (INT_M)A->rowis[k],
                    creal(A->data[k]),
                    cimag(A->data[k]));
            continue;
        }
    }
    fprintf(fd, "%c", '\n');
    fclose(fd);
}
