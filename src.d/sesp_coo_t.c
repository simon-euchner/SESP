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
 * Transposition for COO                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


void sesp_coo_t(sesp_coo *A) {
    SESP_INT i; qsort_data *array;
    array = (qsort_data *)malloc(sizeof(qsort_data));
    for (i=0; i<A->nnz; i++) {
        array[i].a = A->colis[i];
        array[i].b = A->rowis[i];
        array[i].c = A->data[i];
    }
    qsort(array, A->nnz, sizeof(qsort_data), cmp);
    for (i=0; i<A->nnz; i++) {
        A->rowis[i] = array[i].a;
        A->colis[i] = array[i].b;
        A->data[i]  = array[i].c;
    }
    i = A->nrow; A->nrow = A->ncol; A->ncol = i;
    free(array);
}
