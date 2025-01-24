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
 * Pretty printer for type DEN                                                *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


void sesp_den_print(const sesp_den *A) {
    print_header("DEN", A->nrow, A->ncol, A->nnz, A->density);
    printf("%s\n\n", "ARRAY:");
    INT i, j, k;
    for (i=0; i<A->nrow; i++) {
        k = A->ncol*i;
        for (j=0; j<A->ncol; j++) {
            printf(" %+1.3E%+1.3E*I ",
                   creal(A->data[k+j]),
                   cimag(A->data[k+j]));
        }
        printf("%c%c", '\n', '\n');
    }
    printf("%s\n\n", "------------------------");
}
