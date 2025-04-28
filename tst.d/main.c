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
 * File for quick testing                                                     *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


int main(int argc, char **argv)
{
    (void)argc; (void)argv;

    sesp_den *A = sesp_den_alloc(2, 3);
    for (SESP_INT k=0; k<6; A->data[k++] = (SESP_DTYPE)0.);
    A->data[1] = .0001;
    sesp_csc *B = sesp_den_tocsc(A);
    sesp_csc_print(B);
    sesp_csc *C = sesp_csc_clean(B, .0001);
    sesp_csc_print(C);
    sesp_csc_free(C);

    return 0;
}
