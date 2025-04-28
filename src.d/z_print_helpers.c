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
 * Helper functions for pretty printers                                       *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Header
void print_header(const char *fmt,
                   SESP_INT nrow,
                   SESP_INT ncol,
                   SESP_INT nnz,
                   double density) {
    printf("\n%s\n", "---   SESP PRINTER   ---");
    printf("FORMAT: %s\n", fmt);
    printf("SHAPE: %lu x %lu\n", (SESP_MAXINT)nrow, (SESP_MAXINT)ncol);
    printf("NNZ: %lu\n", (SESP_MAXINT)nnz);
    printf("DENSITY: %d %c\n\n", (int)(100*density), 37);
}

// Sparse formats
void print_sparse(const sesp_coo *A, const char *fmt) {
    print_header(fmt, A->nrow, A->ncol, A->nnz, A->density);
    printf(" %s        %s            %s\n\n", "ROW", "COL", "VALUE");
    for (SESP_INT k=0; k<A->nnz; k++) {
        printf(" %10lu %10lu     %+1.3E%+1.3E*I\n",
               (SESP_MAXINT)A->rowis[k],
               (SESP_MAXINT)A->colis[k],
               creal(A->data[k]),
               cimag(A->data[k]));
    }
    printf("%s\n\n", "------------------------");
}
