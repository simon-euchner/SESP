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
 * Matrix multiplication for CSR times CSC                                    *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_csr *sesp_csr_mmdot_csc(const sesp_csr *A, const sesp_csc *B) {

    // Declarations
    INT nnz, nnzrs, nnzcs, i, j, nr_min, nr_max, nc_min, nc_max, k, l, rp;
    DTYPE sum;
    sesp_csr *C;

    // Check dimensions
    if (A->ncol != B->nrow) {
        printf("%s\n", "SESP: Shape error in *sesp_csr_mmdot_csc*");
        exit(1);
    }
     
    // Allocate worst case memory
    nnzrs = nnzcs = 0;
    for (i=0; i<A->nrow+1; i++) { if (A->rowps[i+1]-A->rowps[i]) nnzrs++; }
    for (j=0; j<B->ncol+1; j++) { if (B->colps[j+1]-B->colps[j]) nnzcs++; }
    if ((nnz = nnzrs*nnzcs) > A->nrow*B->ncol) nnz = A->nrow*B->ncol;
    C = sesp_csr_alloc(A->nrow, B->ncol, nnz);

    // Multiply matrices
    nnz = C->rowps[0] = 0;
    for (i=0; i<A->nrow; i++) {
        rp = 0;
        nr_min = A->rowps[i];
        nr_max = A->rowps[i+1];
        for (j=0; j<B->ncol; j++) {
            nc_min = B->colps[j];
            nc_max = B->colps[j+1];
            k = nr_min; l = nc_min; sum = (DTYPE)0;
            while ((k < nr_max) && (l < nc_max)) {
                if (A->colis[k] < B->rowis[l]) { k++; continue; }
                if (A->colis[k] > B->rowis[l]) { l++; continue; }
                if (A->colis[k] == B->rowis[l]) {
                    sum += A->data[k] * B->data[l];
                    k++; l++;
                }
            }
            if (!(cabsl((DTYPE_M)sum) < SMALL)) {
                C->colis[nnz] = j;
                C->data[nnz++] = sum;
                rp++;
            }
        }
        C->rowps[i+1] = C->rowps[i] + rp;
    }

    // Reallocate to (hopefully) less than worst case size
    C->nnz = nnz; C->density = (double)nnz/(double)(C->nrow*C->ncol);
    if (nnz) {
        C->colis = (INT *)realloc(C->colis, sizeof(INT)*nnz);
        C->data = (DTYPE *)realloc(C->data, sizeof(DTYPE)*nnz);
    } else {
        C->colis = NULL;
        C->data = NULL;
    }

    return C;
}
