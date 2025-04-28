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
 * Helper functions for operations on matrices                                *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// x -> x + A[i, :]; x: dense (helper function for csr_add_csr)
SESP_INT sesp_csr_xpAi(const sesp_csr *M,
                       SESP_DTYPE *x,
                       SESP_INT i,
                       SESP_INT *nnz,
                       SESP_INT *colis) {
    SESP_INT j, k, l = 0;
    for (j=M->rowps[i]; j<M->rowps[i+1]; j++) {
        k = M->colis[j];
        if (cabsl((SESP_MAXDTYPE)x[k]) < SMALL) (*nnz)++;
        x[k] += M->data[j];
        colis[l++] = k;
    }
    return l;
}

// Complex conjugation of array with length l
void cc(SESP_DTYPE *arr, SESP_INT n) {
    for(SESP_INT i=0; i<n; i++)
        arr[i] = (SESP_DTYPE)conjl((SESP_MAXDTYPE)arr[i]);
}
