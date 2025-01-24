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
 * Save COO matrix                                                            *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Save COO
void sesp_coo_save(const char *file, const sesp_coo *A) {
    FILE *fd; INT k;
    if (!(fd = fopen(file, "w"))) {
        printf("SESP: Cannot open file *%s* for writing\n", file);
        exit(1);
    }
    filetop(fd, "COO", A->nrow, A->ncol, A->nnz, A->density);
    fprintf(fd,
            "%s %s %s %s\n\n",
            "ROW                ",
            "COL                ",
            "RE               ",
            "IM");
    for (k=0; k<A->nnz; k++) {
        fprintf(fd,
                "%19lu %19lu %+1.10E %+1.10E\n",
                (INT_M)A->rowis[k],
                (INT_M)A->colis[k],
                creal(A->data[k]),
                cimag(A->data[k]));
    }
    fprintf(fd, "%c", '\n');
    fclose(fd);
}
