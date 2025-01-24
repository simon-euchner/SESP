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
 * Addition for CSR                                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_csr *sesp_csr_add(const sesp_csr *A, const sesp_csr *B) {

    // Declarations
    INT nnz, i, j, k, l, m, n, lA, lB, wrm, wcn, nnzcpy;
    REAL_M x;
    int nonzero;
    sesp_csr *C;

    // Check dimensions
    if ( (A->nrow != B->nrow) || (A->ncol != B->ncol) ) {
        printf("%s\n", "SESP: Shape mismatch in *sesp_csr_add_csr*");
        exit(1);
    }

    // Worst case min(A->nnz + B->nnz, A->nrow*A->ncol) many entries
    if (A->nrow*A->ncol >= A->nnz+B->nnz) {
        nnz = A->nnz+B->nnz;
    } else {
        nnz = A->nrow*A->ncol;
    }

    // Allocate worst case memory of result
    C = sesp_csr_alloc(A->nrow, A->ncol, nnz);

    // Allocate memory for working row-vector
    sesp_coo *w = sesp_coo_alloc(A->ncol, A->ncol, A->ncol);
    for (i=0; i<A->ncol; w->data[i++] = (DTYPE)0.);
    for (i=0; i<A->ncol; i++) w->rowis[i] = w->colis[i] = 0;

    // Fill arrays of C adding row by row
    nnz = 0; C->rowps[0] = 0;
    for (i=0; i<A->nrow; i++) {
        lA = sesp_csr_xpAi(A, w->data, i, &nnz, w->rowis);
        lB = sesp_csr_xpAi(B, w->data, i, &nnz, w->colis);
        nnzcpy = nnz; l = j = C->rowps[i]; m = n = 0;
        while (j < nnzcpy) {
            nonzero = 1; wrm = w->rowis[m]; wcn = w->colis[n];
            if ((m < lA) && (n < lB)) {
                if (wrm < wcn) { C->colis[l] = wrm; wrm = 0; m++; goto end;}
                if (wrm > wcn) { C->colis[l] = wcn; wcn = 0; n++; goto end;}
                if (wrm == wcn) { // Here it may happen that the entry is zero
                    x = cabsl((DTYPE_M)w->data[wrm]);
                    if (x < SMALL) {
                        nonzero = 0; nnz--;
                    } else {
                      C->colis[l] = wrm;
                    }
                    wrm = wcn = 0; m++; n++;
                }
            } else {
                if (m < lA) {
                    C->colis[l] = wrm; wrm = 0; m++;
                } else {
                    C->colis[l] = wcn; wcn = 0; n++;
                }
            }
end:
            if (nonzero) { C->data[l] = w->data[C->colis[l]]; l++; }
            j++;
        }

        // Set row pointer
        C->rowps[i+1] = nnz;

        // Load data into C
        for (j=C->rowps[i]; j<nnz; j++) {
            k = C->colis[j]; C->data[j] = w->data[k]; w->data[k] = (DTYPE)0.;
        }
    }
    C->nnz = nnz; sesp_coo_free(w);

    // Reallocate to (hopefully) less than worst case size of C
    if (nnz) {
        C->colis = (INT *)realloc(C->colis, sizeof(INT)*nnz);
        C->data = (DTYPE *)realloc(C->data, sizeof(DTYPE)*nnz);
    } else {
        C->colis = NULL;
        C->data = NULL;
    }

    return C;
}
