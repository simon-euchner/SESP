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
 * Product of array and DEN matrix                                            *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// w -> w + A * v
void sesp_den_mvdot_arr(const sesp_den *A, const SESP_DTYPE *v, SESP_DTYPE *w) {
    SESP_INT i, j;
    for (i=0; i<A->nrow; i++) {
        for (j=0; j<A->ncol; j++) {
            w[i] += A->data[i*A->ncol+j] * v[j];
        }
    }
}
