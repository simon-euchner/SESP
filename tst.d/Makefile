# ---------------------------------------------------------------------------- #
#                                                                              #
# LICENSE NOTICE.                                                              #
#                                                                              #
#     LICENSES: GPL-3.0                                                        #
#                                                                              #
#     IMPORTANT: THIS IS FREE SOFTWARE WITHOUT ANY WARRANTY. THE USER IS FREE  #
#                TO MODIFY AND REDISTRIBUTE THIS SOFTWARE UNDER THE TERMS OF   #
#                THE LICENSE LISTED ABOVE PUBLISHED BY THE FREE SOFTWARE       #
#                FOUNDATION. THE PUBLISHER, SIMON EUCHNER, IS NOT RESPONSIBLE  #
#                FOR ANY NEGATIVE EFFECTS THIS SOFTWARE MAY CAUSE.             #
#                                                                              #
# ---------------------------------------------------------------------------- #
#                                                                              #
# Makefile for quick tests.                                                    #
#                                                                              #
# ---------------------------------------------------------------------------- #


### Variables

# Compiler and Linker (GNU C compiler/linker)
CC = gcc
LD = gcc -Wl,-R,../lib.d -Wl,--enable-new-dtags
FLAGS = -Wall -Wextra -pedantic -std=c99
OLVL = -O1

# Paths
SRC = .
OBJ = ../obj.d
LIB = ../lib.d
BIN = ../bin.d

# Target (binary *calendar*)
TARGET = ${BIN}/main

# Define file name
F = main

### Print info
all: ${TARGET}
	@echo -e "\nBuilding process completed successfully."
	@echo -e "\nRunning now the test.\n\n\n"
	@${TARGET}.out


### Link
${TARGET}: ${OBJ}/${F}.o
	${LD} ${OLVL} -o ${TARGET}.out ${OBJ}/${F}.o -L${LIB} -lsesp


### Compile

# main.c
${OBJ}/${F}.o: ${SRC}/${F}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F}.o -c ${SRC}/${F}.c


### Cleanup

clean:
	rm ${TARGET}.out
	rm ${OBJ}/${F}.o

.PHONY: clean
