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
 * Load DEN matrix from file                                                  *
 *                                                                            *
 * -------------------------------------------------------------------------- */


#include "../inc.d/sesp.h"


sesp_den *sesp_den_load(const char *file) {

    // Open file
    FILE *fd;
    if(!(fd = fopen(file, "r"))) {
        printf("SESP: Cannot open file *%s* for reading\n", file);
        exit(1);
    }

    // Read matrix structure parameters
    INT n, nrow, ncol;
    char line[100];
    skip_lines(fd, 2);
    (void)fgets(line, sizeof(line), fd);
    (void)sscanf(line,
                 "SHAPE: %lu x %lu\n",
                 (INT_M *)&nrow,
                 (INT_M *)&ncol);

    // Allocate memory
    sesp_den *A = sesp_den_alloc((INT)nrow, (INT)ncol);

    // Load matrix data
    REAL_M a, b;
    INT_M r, c;
    skip_lines(fd, 5);
    for (n=0; n<nrow*ncol; n++) {
        (void)fgets(line, sizeof(line), fd);
        (void)sscanf(line, "%lu %lu %Lf %Lf\n", &r, &c, &a, &b);
        A->data[n] = (DTYPE)(a+b*I);
    }

    // Cleanup
    fclose(fd);

    return A;
}
