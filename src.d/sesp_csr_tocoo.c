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
 * Conversion CSR to COO                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion CSR -> COO
sesp_coo *sesp_csr_tocoo(sesp_csr *A) {
    sesp_coo *B = (sesp_coo *)malloc(sizeof(sesp_coo));
    if (A->nnz > 0) {
        B->rowis = (INT *)malloc(sizeof(INT)*A->nnz);
        if (!(B->rowis))
            printf("%s\n", "SESP: Requested memory cannot be allocated");
    } else {
        B->rowis = NULL;
    }
    sesp_csr_tocoo_worker(A, B);
    free(A->rowps); A->rowps = NULL;
    free(A);
    return B;
}

// Conversion CSR to COO worker
void sesp_csr_tocoo_worker(const sesp_csr *A, sesp_coo *B) {
    INT k, l, m;
    B->nrow = A->nrow;
    B->ncol = A->ncol;
    B->nnz = A->nnz;
    B->density = A->density;
    m = k = 0;
    while (k<A->nrow) {
        l = 0;
        while (l++ < (A->rowps[k+1]-A->rowps[k])) B->rowis[m++] = k;
        k++;
    }
    B->colis = A->colis;
    B->data = A->data;
}
