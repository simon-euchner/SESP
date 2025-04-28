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
 * Clean for COO                                                              *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_coo *sesp_coo_clean(sesp_coo *A, SESP_MAXREAL epsilon) {
    if (epsilon < SMALL) epsilon = (SESP_MAXREAL)SMALL;
    sesp_coo *B = sesp_coo_alloc(A->nrow, A->ncol, A->nnz); B->nnz = 0;
    for (SESP_INT k=0; k<A->nnz; k++) {
        if (cabsl((SESP_MAXDTYPE)A->data[k]) < epsilon) continue;
        B->rowis[k] = A->rowis[k];
        B->colis[k] = A->colis[k];
        B->data[k] = A->data[k];
        B->nnz++;
    }
    sesp_coo_free(A);
    B->density = (double)B->nnz/(double)(B->nrow*B->ncol);
    if (B->nnz) {
        B->rowis = (SESP_INT *)realloc(B->rowis, sizeof(SESP_INT)*B->nnz);
        B->colis = (SESP_INT *)realloc(B->colis, sizeof(SESP_INT)*B->nnz);
        B->data = (SESP_DTYPE *)realloc(B->data, sizeof(SESP_DTYPE)*B->nnz);
    } else {
        B->rowis = NULL;
        B->colis = NULL;
        B->data = NULL;
    }
    return B;
}
