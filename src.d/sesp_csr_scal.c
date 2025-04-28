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
 * Scale CSR                                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// A -> alpha * A
void sesp_csr_scal(SESP_DTYPE alpha, sesp_csr *A) {
    if (cabsl((SESP_MAXDTYPE)alpha) < SMALL) {
        free(A->colis); free(A->data); A->colis = NULL; A->data = NULL;
        for (SESP_INT k=0; k<A->nrow+1; A->rowps[k++] = (SESP_INT)0);
    } else {
        for (SESP_INT k=0; k<A->nnz; k++) A->data[k] *= alpha;
    }
}
