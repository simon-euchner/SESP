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
 * Addition for CSC                                                           *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_csc *sesp_csc_add_csc(sesp_csc *A, sesp_csc *B) {
    sesp_csr *C, *D, *E; sesp_csc *F;
    C = (sesp_csr *)malloc(sizeof(sesp_csr));
    D = (sesp_csr *)malloc(sizeof(sesp_csr));
    F = (sesp_csc *)malloc(sizeof(sesp_csc));
    C->nrow  = A->ncol;  D->nrow  = B->ncol;
    C->ncol  = A->nrow;  D->ncol  = B->nrow;
    C->nnz   = A->nnz;   D->nnz   = B->nnz;
    C->rowps = A->colps; D->rowps = B->colps;
    C->colis = A->rowis; D->colis = B->rowis;
    C->data  = A->data;  D->data  = B->data;
    E = sesp_csr_add(C, D); free(C); free(D);
    F->nrow    = E->ncol;
    F->ncol    = E->nrow;
    F->nnz     = E->nnz;
    F->density = E->density;
    F->rowis   = E->colis;
    F->colps   = E->rowps;
    F->data    = E->data;
    free(E);
    return F;
}
