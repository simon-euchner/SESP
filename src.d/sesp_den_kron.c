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
 * Kronecker product for DEN                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_den *sesp_den_kron(const sesp_den *A, const sesp_den *B) {
    INT iA, jA, iB, jB, k;
    sesp_den *C, *Bcpy = NULL;
    C = sesp_den_alloc(A->nrow*B->nrow, A->ncol*B->ncol);
    for (iA=0; iA<A->nrow; iA++) {
        for (jA=0; jA<A->ncol; jA++) {
            Bcpy = sesp_den_copy(B);
            sesp_den_scal(A->data[A->ncol*iA+jA], Bcpy);
            for (iB=0; iB<B->nrow; iB++) {
                for (jB=0; jB<B->ncol; jB++) {
                    k = C->ncol*(iA*B->nrow+iB)+B->ncol*jA+jB;
                    C->data[k] = Bcpy->data[B->ncol*iB+jB];
                }
            }
            sesp_den_free(Bcpy);
        }
    }
    return C;
}
