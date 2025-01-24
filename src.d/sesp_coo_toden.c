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
 * Conversion COO to DEN                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion COO -> DEN
sesp_den *sesp_coo_toden(sesp_coo *A) {
    sesp_den *B = sesp_den_alloc(A->nrow, A->ncol);
    sesp_coo_toden_worker(A, B); sesp_coo_free(A);
    return B;
}

// Conversion COO to DEN worker
void sesp_coo_toden_worker(const sesp_coo *A, sesp_den *B) {
    INT k;
    for (k=0; k<A->nrow*A->ncol; B->data[k++] = 0.+0.*I);
    for (k=0; k<A->nnz; k++)
        B->data[A->rowis[k]*A->ncol+A->colis[k]] = A->data[k];
}
