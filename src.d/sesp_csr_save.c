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
 * Save CSR matrix                                                            *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Save CSR
void sesp_csr_save(const char *file, const sesp_csr *A) {
    FILE *fd; SESP_INT k, max;
    if (!(fd = fopen(file, "w"))) {
        printf("SESP: Cannot open file *%s* for writing\n", file);
        exit(1);
    }
    filetop(fd, "CSR", A->nrow, A->ncol, A->nnz, A->density);
    if (A->nnz > A->nrow+1) max = A->nnz; else max = A->nrow+1;
    fprintf(fd,
            "%s %s %s %s\n\n",
            "ROWP               ",
            "COL                ",
            "RE               ",
            "IM");
    for (k=0; k<max; k++) {
        if ((k<A->nnz) && (k<A->nrow+1)) {
            fprintf(fd,
                    "%19lu %19lu %+1.10E %+1.10E\n",
                    (SESP_MAXINT)A->rowps[k],
                    (SESP_MAXINT)A->colis[k],
                    creal(A->data[k]),
                    cimag(A->data[k]));
            continue;
        }
        if ((k>=A->nnz) && (k<A->nrow+1)) {
            fprintf(fd,
                    "%19lu\n",
                    (SESP_MAXINT)A->rowps[k]);
            continue;
        }
        if ((k<A->nnz) && (k>=A->nrow+1)) {
            fprintf(fd,
                    "                    %19lu %+1.10E %+1.10E\n",
                    (SESP_MAXINT)A->colis[k],
                    creal(A->data[k]),
                    cimag(A->data[k]));
            continue;
        }
    }
    fprintf(fd, "%c", '\n');
    fclose(fd);
}
