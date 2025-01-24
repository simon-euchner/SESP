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
 * Memory management for DEN                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Allocator for DEN
sesp_den *sesp_den_alloc(INT nrow, INT ncol) {

    // Input sanity check
    if (check_valid(nrow, ncol, 0)) {
        printf("%s\n", "SESP: Invalid input to *sesp_den_alloc*");
        exit(1);
    }

    // Allocate memory for result
    sesp_den *A = (sesp_den *)malloc(sizeof(sesp_den));

    // Fill in info
    A->nrow = nrow;
    A->ncol = ncol;
    A->nnz = nrow*ncol;
    A->density = 1.;

    // Allocate memory
    DTYPE *data = (DTYPE *)malloc(sizeof(DTYPE)*A->nnz);
    if (!data) {
        printf("%s\n", "SESP: Requested memory cannot be allocated");
        exit(1);
    }
    A->data = data;

    return A;
}

// Free for DEN
void sesp_den_free(sesp_den *A) {
    free(A->data); A->data = NULL;
    free(A);
}
