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
 * Conversion CSC to COO                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion CSC -> COO
sesp_coo *sesp_csc_tocoo(sesp_csc *A) {

    // Declarations
    sesp_csr *At;
    sesp_coo *B, *C;

    // Transpose A to get At in CSR format
    At = (sesp_csr *)malloc(sizeof(sesp_csr));
    At->nrow = A->ncol;
    At->ncol = A->nrow;
    At->nnz = A->nnz;
    At->density = A->density;
    At->rowps = A->colps;
    At->colis = A->rowis;
    At->data = A->data;
    free(A);

    // Get B = At into COO format
    B = sesp_csr_tocoo(At);

    // Transpose B
    C = (sesp_coo *)malloc(sizeof(sesp_coo));
    C->nrow = B->ncol;
    C->ncol = B->nrow;
    C->nnz = B->nnz;
    C->density = B->density;
    C->rowis = B->colis;
    C->colis = B->rowis;
    C->data = B->data;
    free(B);

    // Get ROW-MAJOR order
    sesp_csc_tocoo_worker(C);

    return C;
}

// Conversion CSC -> COO worker
void sesp_csc_tocoo_worker(sesp_coo *C) {

    // Sort
    INT k;
    if (C->nnz) {

        // Prepare data for qsort
        qsort_data *array = (qsort_data *)malloc(sizeof(qsort_data)*C->nnz);
        for (k=0; k<C->nnz; k++) {
            array[k].a = C->rowis[k];
            array[k].b = C->colis[k];
            array[k].c = C->data[k];
        }

        // Sort with Quick Sort in glib
        qsort(array, C->nnz, sizeof(qsort_data), cmp);

        // Regain data
        for (k=0; k<C->nnz; k++) {
            C->rowis[k] = array[k].a;
            C->colis[k] = array[k].b;
            C->data[k] = array[k].c;
        }
        free(array);
    }
}
