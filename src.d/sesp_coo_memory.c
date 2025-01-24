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
 * Memory management for COO                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Allocator for COO
sesp_coo *sesp_coo_alloc(INT nrow, INT ncol, INT nnz) {

    // Input sanity check
    if (check_valid(nrow, ncol, nnz)) {
        printf("%s\n", "SESP: Invalid input to *sesp_coo_alloc*");
        exit(1);
    }

    // Allocate memory for result
    sesp_coo *A = (sesp_coo *)malloc(sizeof(sesp_coo));

    // Fill in info
    A->nrow = nrow;
    A->ncol = ncol;
    A->nnz = nnz;
    A->density = (double)nnz/(double)(nrow*ncol);

    // Allocate memory
    INT *rowis;
    INT *colis;
    DTYPE *data;
    if (nnz > 0) {
        rowis = (INT *)malloc(sizeof(INT)*A->nnz);
        colis = (INT *)malloc(sizeof(INT)*A->nnz);
        data = (DTYPE *)malloc(sizeof(DTYPE)*A->nnz);
        if (!(rowis && colis && data)) {
            printf("%s\n", "SESP: Requested memory cannot be allocated");
            exit(1);
        }
    } else {
        data = NULL;
        colis = NULL;
        rowis = NULL;
    }
    A->rowis = rowis;
    A->colis = colis;
    A->data = data;

    return A;
}

// Free for COO
void sesp_coo_free(sesp_coo *A) {
    free(A->rowis); A->rowis = NULL;
    free(A->colis);A->colis = NULL;
    free(A->data); A->data = NULL;
    free(A);
}
