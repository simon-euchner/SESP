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
 * Conversion COO to CSR                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion COO -> CSR
sesp_csr *sesp_coo_tocsr(sesp_coo *A) {
    sesp_csr *B = (sesp_csr *)malloc(sizeof(sesp_csr));
    B->rowps = (SESP_INT *)malloc(sizeof(SESP_INT)*(A->nrow+1));
    if (!(B->rowps))
        printf("%s\n", "SESP: Requested memory cannot be allocated");
    sesp_coo_tocsr_worker(A, B);
    free(A->rowis); A->rowis = NULL; free(A);
    return B;
}

// Conversion COO to CSR worker
void sesp_coo_tocsr_worker(const sesp_coo *A, sesp_csr *B) {
    SESP_INT k, l;
    B->nrow = A->nrow;
    B->ncol = A->ncol;
    B->nnz = A->nnz;
    B->density = A->density;
    l = k = 0;
    B->rowps[0] = 0;
    if (A->nnz > 0) {
        while (k < A->nrow) {
            while ((A->rowis[l] == k) && (l < B->nnz)) l++;
            B->rowps[++k] = l;
        }
    } else {
        for (k=1; k<A->nrow+1; B->rowps[k++] = 0);
    }
    B->colis = A->colis;
    B->data = A->data;
}
