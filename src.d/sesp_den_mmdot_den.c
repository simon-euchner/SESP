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
 * Matrix multiplication for DEN                                              *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_den *sesp_den_mmdot_den(const sesp_den *A, const sesp_den *B) {
    SESP_INT i, j, k, l; sesp_den *C;
    if (A->ncol != B->nrow) {
        printf("%s\n", "SESP: Shape error in *sesp_den_mmdot_den*");
        exit(1);
    }
    C = sesp_den_alloc(A->nrow, B->ncol);
    for (i=0; i<C->nrow; i++) {
        for (j=0; j<C->ncol; j++) {
            C->data[i*C->ncol+j] = (SESP_DTYPE)0;
            l = i*A->ncol;
            for (k=0; k<A->ncol; k++) {
                C->data[i*C->ncol+j] += A->data[l+k] * B->data[k*B->ncol+j];
            }
        }
    }
    return C;
}
