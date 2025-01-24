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
 * Memory management for CSR                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Allocator for CSR
sesp_csr *sesp_csr_alloc(INT nrow, INT ncol, INT nnz) {

    // Input sanity check
    if (check_valid(nrow, ncol, nnz)) {
        printf("%s\n", "SESP: Invalid input to *sesp_csr_alloc*");
        exit(1);
    }

    // Allocate memory for result
    sesp_csr *A = (sesp_csr *)malloc(sizeof(sesp_csr));

    // Fill in info
    A->nrow = nrow;
    A->ncol = ncol;
    A->nnz = nnz;
    A->density = (double)nnz/(double)(nrow*ncol);

    // Allocate memory
    INT *rowps = (INT *)malloc(sizeof(INT)*(A->nrow+1));
    INT *colis;
    DTYPE *data;
    if (nnz > 0) {
        data = (DTYPE *)malloc(sizeof(DTYPE)*A->nnz);
        colis = (INT *)malloc(sizeof(INT)*A->nnz);
        if (!(rowps && colis && data)) {
            printf("%s\n", "SESP: Requested memory cannot be allocated");
            exit(1);
        }
    } else {
        data = NULL;
        colis = NULL;
    }
    A->rowps = rowps;
    A->colis = colis;
    A->data = data;

    return A;
}

// Free for CSR
void sesp_csr_free(sesp_csr *A) {
    free(A->rowps); A->rowps = NULL;
    free(A->colis); A->colis = NULL;
    free(A->data);  A->data = NULL;
    free(A);
}
