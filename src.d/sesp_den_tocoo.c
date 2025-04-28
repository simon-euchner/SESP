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
 * Conversion DEN to COO                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion DEN -> COO
sesp_coo *sesp_den_tocoo(sesp_den *A) {
    sesp_coo *B = sesp_coo_alloc(A->nrow, A->ncol, A->nrow*A->ncol);
    SESP_INT nnz = sesp_den_tocoo_worker(A, B);
    sesp_den_free(A);
    if (nnz) {
        B->rowis = realloc(B->rowis, sizeof(SESP_INT)*nnz);
        B->colis = realloc(B->colis, sizeof(SESP_INT)*nnz);
        B->data = realloc(B->data, sizeof(SESP_DTYPE)*nnz);
    } else {
        B->rowis = NULL;
        B->colis = NULL;
        B->data = NULL;
    }
    return B;
}

// Conversion DEN to COO worker
int sesp_den_tocoo_worker(const sesp_den *A, sesp_coo *B) {
    SESP_INT i, j, k, nnz;
    k = nnz = 0;
    for (i=0; i<A->nrow; i++) {
        for (j=0; j<A->ncol; j++) {
            k = i*A->ncol;
            if (cabsl((SESP_MAXDTYPE)A->data[k+j]) > SMALL) {
                B->rowis[nnz] = i;
                B->colis[nnz] = j;
                B->data[nnz++] = A->data[k+j];
            }
        }
    }
    B->nnz = nnz;
    B->density = B->nnz/((double)(A->nrow*A->ncol));
    return nnz;
}
