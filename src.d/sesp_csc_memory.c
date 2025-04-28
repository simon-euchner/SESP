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
 * Memory management for CSC                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Allocator for CSC
sesp_csc *sesp_csc_alloc(SESP_INT nrow, SESP_INT ncol, SESP_INT nnz) {

    // Input sanity check
    if (check_valid(nrow, ncol, nnz)) {
        printf("%s\n", "SESP: Invalid input to *sesp_csr_alloc*");
        exit(1);
    }

    // Allocate memory for result
    sesp_csc *A = (sesp_csc *)malloc(sizeof(sesp_csc));

    // Fill in info
    A->nrow = nrow;
    A->ncol = ncol;
    A->nnz = nnz;
    A->density = (double)nnz/(double)(nrow*ncol);

    // Allocate memory
    SESP_INT *rowis;
    SESP_INT *colps = (SESP_INT *)malloc(sizeof(SESP_INT)*(A->ncol+1));
    SESP_DTYPE *data;
    if (nnz) {
        rowis = (SESP_INT *)malloc(sizeof(SESP_INT)*A->nnz);
        data = (SESP_DTYPE *)malloc(sizeof(SESP_DTYPE)*A->nnz);
        if (!(rowis && colps && data)) {
            printf("%s\n", "SESP: Requested memory cannot be allocated");
            exit(1);
        }
    } else {
        data = NULL;
        rowis = NULL;
    }
    A->rowis = rowis;
    A->colps = colps;
    A->data = data;

    return A;
}

// Free for CSC
void sesp_csc_free(sesp_csc *A) {
    free(A->rowis); A->rowis = NULL;
    free(A->colps); A->colps = NULL;
    free(A->data);  A->data = NULL;
    free(A);
}
