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
 * Include this header in youre project to use SESP.                          *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#ifndef SESP_H
#define SESP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <complex.h>
#include <math.h>


/* --- Configuration / Generalities ----------------------------------------- */

// *Small* value; should be slightly larger than machine precision
#define SMALL 1e-13

// Maximal data types for matrix entries, indices and the real part of entries
typedef long double complex SESP_MAXDTYPE;
typedef long double SESP_MAXREAL;
typedef uint64_t SESP_MAXINT;

/* Data type for matrix entries                                               *
 * Options:                                                                   *
 *     float, double, long double,                                            *
 *     float complex, double complex, long double complex                     */
typedef double complex SESP_DTYPE;

/* Data type matrix indices                                                   *
 * Options: All unsigned integers smaller or equal to uint64_t                */
typedef uint32_t SESP_INT;

// Data type for *qsort*
typedef struct _qsort_data {
    SESP_INT a;
    SESP_INT b;
    SESP_DTYPE c;
} qsort_data;
/* -------------------------------------------------------------------------- */


/* --- Matrix Formats ------------------------------------------------------- */

// Dense matrix format (DEN)
typedef struct _sesp_den {
    SESP_INT nrow;       // Number of rows
    SESP_INT ncol;       // Number of columns
    SESP_INT nnz;        // Number of non-zero elements
    double density;      // Density, number in [0, 1]
    SESP_DTYPE *data;    // Matrix entries
} sesp_den;

// Co-ordinate sparse matrix format (COO)
typedef struct _sesp_coo {
    SESP_INT nrow;
    SESP_INT ncol;
    SESP_INT nnz;
    double density;
    SESP_INT *rowis;     // Row indices
    SESP_INT *colis;     // Column indices
    SESP_DTYPE *data;
} sesp_coo;

// Compressed sparse row matrix format (CSR)
typedef struct _sesp_csr {
    SESP_INT nrow;
    SESP_INT ncol;
    SESP_INT nnz;
    double density;
    SESP_INT *rowps;     // Row pointers
    SESP_INT *colis;
    SESP_DTYPE *data;
} sesp_csr;

// Compressed sparse column matrix format (CSC)
typedef struct _sesp_csc {
    SESP_INT nrow;
    SESP_INT ncol;
    SESP_INT nnz;
    double density;
    SESP_INT *rowis;
    SESP_INT *colps; // Column pointers
    SESP_DTYPE *data;
} sesp_csc;
/* -------------------------------------------------------------------------- */


/* --- Memory Management ---------------------------------------------------- */
sesp_den *sesp_den_alloc(SESP_INT, SESP_INT);
void sesp_den_free(sesp_den *);
sesp_coo *sesp_coo_alloc(SESP_INT, SESP_INT, SESP_INT);
void sesp_coo_free(sesp_coo *);
sesp_csr *sesp_csr_alloc(SESP_INT, SESP_INT, SESP_INT);
void sesp_csr_free(sesp_csr *);
sesp_csc *sesp_csc_alloc(SESP_INT, SESP_INT, SESP_INT);
void sesp_csc_free(sesp_csc *);
/* -------------------------------------------------------------------------- */


/* --- Conversion ----------------------------------------------------------- */
sesp_coo *sesp_den_tocoo(sesp_den *);
sesp_csr *sesp_coo_tocsr(sesp_coo *);
sesp_coo *sesp_csr_tocoo(sesp_csr *);
sesp_den *sesp_coo_toden(sesp_coo *);
sesp_coo *sesp_csc_tocoo(sesp_csc *);
sesp_csr *sesp_csc_tocsr(sesp_csc *);
sesp_csc *sesp_coo_tocsc(sesp_coo *);
sesp_csc *sesp_csr_tocsc(sesp_csr *);
sesp_csr *sesp_den_tocsr(sesp_den *);
sesp_den *sesp_csr_toden(sesp_csr *);
sesp_csc *sesp_den_tocsc(sesp_den *);
sesp_den *sesp_csc_toden(sesp_csc *);
int cmp(const void *, const void *);
/* -------------------------------------------------------------------------- */


/* --- Copy ----------------------------------------------------------------- */
sesp_den *sesp_den_copy(const sesp_den *);
sesp_coo *sesp_coo_copy(const sesp_coo *);
sesp_csr *sesp_csr_copy(const sesp_csr *);
sesp_csc *sesp_csc_copy(const sesp_csc *);
/* -------------------------------------------------------------------------- */


/* --- Printing ------------------------------------------------------------- */
void sesp_den_print(const sesp_den *);
void sesp_coo_print(const sesp_coo *);
void sesp_csr_print(const sesp_csr *);
void sesp_csc_print(const sesp_csc *);
/* -------------------------------------------------------------------------- */


/* --- Save / Load ---------------------------------------------------------- */
void sesp_den_save(const char *, const sesp_den *);
void sesp_coo_save(const char *, const sesp_coo *);
void sesp_csr_save(const char *, const sesp_csr *);
void sesp_csc_save(const char *, const sesp_csc *);
sesp_den *sesp_den_load(const char *);
sesp_coo *sesp_coo_load(const char *);
sesp_csr *sesp_csr_load(const char *);
sesp_csc *sesp_csc_load(const char *);
/* -------------------------------------------------------------------------- */


/* --- Operations ----------------------------------------------------------- */
void sesp_den_scal(SESP_DTYPE, sesp_den *);
void sesp_coo_scal(SESP_DTYPE, sesp_coo *);
void sesp_csr_scal(SESP_DTYPE, sesp_csr *);
void sesp_csc_scal(SESP_DTYPE, sesp_csc *);
void sesp_den_mvdot_arr(const sesp_den *, const SESP_DTYPE *, SESP_DTYPE *);
void sesp_csr_mvdot_arr(const sesp_csr *, const SESP_DTYPE *, SESP_DTYPE *);
sesp_den *sesp_den_add_den(const sesp_den *, const sesp_den *);
sesp_csr *sesp_csr_add_csr(const sesp_csr *, const sesp_csr *);
sesp_csc *sesp_csc_add_csc(sesp_csc *, sesp_csc *);
void sesp_den_t(sesp_den *);
void sesp_coo_t(sesp_coo *);
sesp_csc *sesp_csr_t(sesp_csr *);
sesp_csr *sesp_csc_t(sesp_csc *);
void sesp_den_cc(sesp_den *);
void sesp_coo_cc(sesp_coo *);
void sesp_csr_cc(sesp_csr *);
void sesp_csc_cc(sesp_csc *);
sesp_den *sesp_den_add(const sesp_den *, const sesp_den *);
sesp_coo *sesp_coo_add(const sesp_coo *, const sesp_coo *);
sesp_csr *sesp_csr_add(const sesp_csr *, const sesp_csr *);
sesp_csc *sesp_csc_add(const sesp_csc *, const sesp_csc *);
sesp_den *sesp_den_mmdot_den(const sesp_den *, const sesp_den *);
sesp_csr *sesp_csr_mmdot_csc(const sesp_csr *, const sesp_csc *);
sesp_den *sesp_den_kron(const sesp_den *, const sesp_den *);
sesp_coo *sesp_coo_kron(const sesp_coo *, const sesp_coo *);
sesp_csr *sesp_csr_kron(const sesp_csr *, const sesp_csr *);
/* -------------------------------------------------------------------------- */


/* --- Clean Up ------------------------------------------------------------- */
sesp_coo *sesp_coo_clean(sesp_coo *, long double);
sesp_csr *sesp_csr_clean(sesp_csr *, long double);
sesp_csc *sesp_csc_clean(sesp_csc *, long double);
/* -------------------------------------------------------------------------- */


/* --- Helper Functions ----------------------------------------------------- */

/* Note that some functions are not shared across files, so they could be     *
 * declared as static. However, I decided to make them external in order to   *
 * give more control over memory management, if needed. Sticking with the     *
 * implemented functions is fine in most cases and absolutely reasonable.     */

void print_header(const char *, SESP_INT, SESP_INT, SESP_INT, double);
void print_sparse(const sesp_coo *, const char *);
int check_valid(SESP_INT, SESP_INT, SESP_INT);
int cmp(const void *, const void *);
void filetop(FILE *,
             const char *,
             SESP_INT,
             SESP_INT,
             SESP_INT,
             double);
SESP_INT sesp_csr_xpAi(const sesp_csr *,
                        SESP_DTYPE *,
                        SESP_INT,
                        SESP_INT *,
                        SESP_INT *);
void cc(SESP_DTYPE *, SESP_INT);
int sesp_den_tocoo_worker(const sesp_den *, sesp_coo *);
void sesp_coo_tocsr_worker(const sesp_coo *, sesp_csr *);
void sesp_csr_tocoo_worker(const sesp_csr *, sesp_coo *);
void sesp_coo_toden_worker(const sesp_coo *A, sesp_den *B);
void sesp_csc_tocoo_worker(sesp_coo *);
void sesp_coo_tocsc_worker(const sesp_coo *, sesp_csc *);
void skip_lines(FILE *, SESP_INT);
/* -------------------------------------------------------------------------- */

#endif
