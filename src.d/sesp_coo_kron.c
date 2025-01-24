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
 * Kronecker product for COO                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_coo *sesp_coo_kron(const sesp_coo *A, const sesp_coo *B) {
    INT nnz, k, l, m;
    sesp_coo *C, *Bcpy;
    nnz = A->nnz*B->nnz;
    C = sesp_coo_alloc(A->nrow*B->nrow, A->ncol*B->ncol, nnz);
    m = 0;
    for (k=0; k<A->nnz; k++) {
        Bcpy = sesp_coo_copy(B); sesp_coo_scal(A->data[k], Bcpy);
        for (l=0; l<B->nnz; l++) {
            C->rowis[m] = A->rowis[k]*B->nrow+B->rowis[l];
            C->colis[m] = A->colis[k]*B->ncol+B->colis[l];
            C->data[m++] = Bcpy->data[l];
        }
        sesp_coo_free(Bcpy);
    }
    if (nnz) {
        qsort_data *array = (qsort_data *)malloc(sizeof(qsort_data)*nnz);
        for (k=0; k<A->nnz; k++) {
            array[k].a = A->rowis[k];
            array[k].b = A->colis[k];
            array[k].c = A->data[k];
        }
        qsort(array, nnz, sizeof(qsort_data), cmp);
        for (k=0; k<nnz; k++) {
            A->rowis[k] = array[k].a;
            A->colis[k] = array[k].b;
            A->data[k] = array[k].c;
        }
        free(array);
    }
    return C;
}
