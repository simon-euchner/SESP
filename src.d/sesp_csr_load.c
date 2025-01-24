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
 * Load CSR matrix from file                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_csr *sesp_csr_load(const char *file) {

    // Open file
    FILE *fd;
    if(!(fd = fopen(file, "r"))) {
        printf("SESP: Cannot open file *%s* for reading\n", file);
        exit(1);
    }

    // Read matrix structure parameters
    INT n, nrow, ncol, nnz, nmax;
    char line[100];
    skip_lines(fd, 2);
    (void)fgets(line, sizeof(line), fd);
    n = sscanf(line, "SHAPE: %lu x %lu\n",
               (INT_M *)&nrow,
               (INT_M *)&ncol);
    (void)fgets(line, sizeof(line), fd);
    (void)sscanf(line, "NNZ: %lu\n", (INT_M *)&nnz);

    // Allocate memory
    sesp_csr *A = sesp_csr_alloc((INT)nrow, (INT)ncol, (INT)nnz);

    // Load matrix data
    REAL_M a, b;
    INT_M r, c;
    skip_lines(fd, 4);
    if (nnz > nrow+1) { nmax = nnz; } else { nmax = nrow+1; }
    for (n=0; n<nmax; n++) {
        (void)fgets(line, sizeof(line), fd);
        if (n < nrow+1) {
            if (n < nnz) {
                (void)sscanf(line, "%lu %lu %Lf %Lf\n", &r, &c, &a, &b);
                A->colis[n] = (INT)c;
                A->data[n] = (DTYPE)(a+b*I);
            } else {
                (void)sscanf(line, "%lu\n", &r);
            }
            A->rowps[n] = (INT)r;
        } else {
            (void)sscanf(line, "%lu %Lf %Lf\n", &c, &a, &b);
            A->colis[n] = (INT)c;
            A->data[n] = (DTYPE)(a+b*I);
        }
    }

    // Cleanup
    fclose(fd);

    return A;
}
