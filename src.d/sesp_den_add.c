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
 * Addition for DEN                                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_den *sesp_den_add(const sesp_den *A, const sesp_den *B) {
    INT i; sesp_den *C;
    if ( (A->nrow != B->nrow) || (A->ncol != B->ncol) ) {
        printf("%s\n", "SESP: Shape mismatch in *sesp_den_add_den*");
        exit(1);
    }
    C = sesp_den_alloc(A->nrow, A->ncol);
    for (i=0; i<A->nnz; i++) C->data[i] = A->data[i] + B->data[i];
    return C;
}
