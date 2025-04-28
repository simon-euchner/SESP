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
 * Transposition for DEN                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


void sesp_den_t(sesp_den *A) {
    SESP_INT i, j; SESP_DTYPE *data;
    data = (SESP_DTYPE *)malloc(sizeof(SESP_DTYPE)*A->nnz);
    for (i=0; i<A->nrow; i++) {
        for (j=0; j<A->ncol; j++) {
            data[j*A->nrow+i] = A->data[i*A->ncol+j];
        }
    }
    i = A->nrow; A->nrow = A->ncol; A->ncol = i;
    free(A->data); A->data = data;
}
