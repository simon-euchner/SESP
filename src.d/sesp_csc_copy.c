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
 * Copy for CSC                                                               *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_csc *sesp_csc_copy(const sesp_csc *A) {
    sesp_csc *B; SESP_INT k; B = sesp_csc_alloc(A->nrow, A->ncol, A->nnz);
    for (k=0; k<A->ncol+1; k++) B->colps[k] = A->colps[k];
    for (k=0; k<A->nnz; k++) {
        B->rowis[k] = A->rowis[k];
        B->data[k] = A->data[k];
    }
    return B;
}
