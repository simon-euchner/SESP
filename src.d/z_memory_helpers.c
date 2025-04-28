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
 * Helper functions for memory management                                     *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


// Check input validity
int check_valid(SESP_INT nrow, SESP_INT ncol, SESP_INT nnz) {
    if (!(nrow && ncol)) return 1;
    if (nnz > nrow*ncol) return 1;
    return 0;
}
