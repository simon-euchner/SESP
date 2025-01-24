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
 * Addition for COO                                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


static void load_data(INT, INT, const sesp_coo *, sesp_coo *);


sesp_coo *sesp_coo_add(const sesp_coo *A, const sesp_coo *B) {

    // Declarations
    INT nnz, kA, kB;
    DTYPE sum;
    sesp_coo *C;

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
    C = sesp_coo_alloc(A->nrow, A->ncol, nnz);

    // Add row by row
    nnz = kB = kA = 0;
    while ((kA < A->nnz) || (kB < B->nnz)) {
        if (kA >= A->nnz) goto getB;
        if (kB >= B->nnz) goto getA;
        if (A->rowis[kA] < B->rowis[kB]) {
getA:
            load_data(nnz++, kA++, A, C); continue;
        }
        if (A->rowis[kA] > B->rowis[kB]) {
getB:
            load_data(nnz++, kB++, B, C); continue;
        }
        if (A->rowis[kA] == B->rowis[kB]) {
            if (A->colis[kA] == B->colis[kB]) {
                sum = A->data[kA] + B->data[kB++];
                if (cabsl((DTYPE_M)sum) < SMALL) { kA++; continue; }
                load_data(nnz++, kA++, A, C); continue;
            }
            if (A->colis[kA] < B->colis[kB]) {
                load_data(nnz++, kA++, A, C); continue;
            }
            if (A->colis[kA] > B->colis[kB]) {
                load_data(nnz++, kB++, B, C); continue;
            }
        }
    }
    if (!(kA || kB)) nnz--;

    // Reallocate to (hopefully) smaller size than worst case nnz
    C->nnz = nnz; C->density = (double)nnz/(double)(C->nrow*C->ncol);
    if (C->nnz) {
        C->rowis = realloc(C->rowis, sizeof(INT)*nnz);
        C->colis = realloc(C->colis, sizeof(INT)*nnz);
        C->data = realloc(C->data, sizeof(DTYPE)*nnz);
    } else {
        C->rowis = NULL;
        C->colis = NULL;
        C->data = NULL;
    }

    return C;
}

static void load_data(INT nnz, INT k, const sesp_coo *A, sesp_coo *B) {
    B->rowis[nnz] = A->rowis[k];
    B->colis[nnz] = A->colis[k];
    B->data[nnz] = A->data[k];
}
