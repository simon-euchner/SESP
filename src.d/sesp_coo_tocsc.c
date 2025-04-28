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
 * Conversion COO to CSC                                                      *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Conversion COO -> CSC
sesp_csc *sesp_coo_tocsc(sesp_coo *A) {

    // Prepare result
    sesp_csc *B = (sesp_csc *)malloc(sizeof(sesp_csc));
    B->nrow = A->nrow;
    B->ncol = A->ncol;
    B->nnz = A->nnz;
    B->density = A->density;
    B->rowis = A->rowis;
    B->data = A->data;
    B->colps = (SESP_INT *)malloc(sizeof(SESP_INT)*(B->ncol+1));
    if (!(B->colps))
        printf("%s\n", "SESP: Requested memory cannot be allocated");

    // Do conversion
    sesp_coo_tocsc_worker(A, B);

    // Clean up
    free(A->colis); A->colis = NULL;
    free(A);

    return B;
}

// Conversion COO -> CSC worker
void sesp_coo_tocsc_worker(const sesp_coo *A, sesp_csc *B) {

    // Declarations
    SESP_INT k, l;

    // Convert data of A to Column-Major
    if (A->nnz) {

        // Prepare data for qsort
        qsort_data *array = (qsort_data *)malloc(sizeof(qsort_data)*A->nnz);
        for (k=0; k<A->nnz; k++) {
            array[k].a = A->colis[k];
            array[k].b = A->rowis[k];
            array[k].c = A->data[k];
        }

        // Sort with Quick Sort in glib
        qsort(array, A->nnz, sizeof(qsort_data), cmp);

        // Regain data
        for (k=0; k<A->nnz; k++) {
            A->colis[k] = array[k].a;
            A->rowis[k] = array[k].b;
            A->data[k] = array[k].c;
        }
        free(array);
    }

    // Obtain column pointers
    l = k = 0;
    B->colps[0] = 0;
    if (A->nnz > 0) {
        while (k < B->ncol) {
            while ( (A->colis[l] == k) && (l < B->nnz) ) l++;
            B->colps[++k] = l;
        }
    } else {
        for (k=1; k<B->ncol+1; B->colps[k++] = 0);
    }
}
