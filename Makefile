# ---------------------------------------------------------------------------- #
#                                                                              #
# LICENSE NOTICE.                                                              #
#                                                                              #
#     LICENSE: GPL-3.0                                                         #
#                                                                              #
#     IMPORTANT: THIS IS FREE SOFTWARE WITHOUT ANY WARRANTY. THE USER IS FREE  #
#                TO MODIFY AND REDISTRIBUTE THIS SOFTWARE UNDER THE TERMS OF   #
#                THE LICENSE LISTED ABOVE PUBLISHED BY THE FREE SOFTWARE       #
#                FOUNDATION. THE PUBLISHER, SIMON EUCHNER, IS NOT RESPONSIBLE  #
#                FOR ANY NEGATIVE EFFECTS THIS SOFTWARE MAY CAUSE.             #
#                                                                              #
# ---------------------------------------------------------------------------- #
#                                                                              #
# Makefile for the SESP C-libary                                               #
#                                                                              #
# ---------------------------------------------------------------------------- #


### Variables

# Compiler and Linker (GNU C compiler/linker)
CC = gcc
LD = gcc -shared
FLAGS = -Wall -Wextra -pedantic -std=c99 -fPIC
OLVL = -O1

# Paths
SRC = ./src.d
OBJ = ./obj.d
LIB = ./lib.d

# Target (binary *calendar*)
TARGET = ${LIB}/libsesp.so

# Define file names
F01 = sesp_den_tocoo
F02 = sesp_coo_tocsr
F03 = sesp_csr_tocoo
F04 = sesp_coo_toden
F05 = sesp_csc_tocoo
F06 = sesp_csc_tocsr
F07 = sesp_coo_tocsc
F08 = sesp_csr_tocsc
F09 = sesp_den_tocsr
F10 = sesp_csr_toden
F11 = sesp_den_tocsc
F12 = sesp_csc_toden
F13 = z_print_helpers
F14 = sesp_den_print
F15 = sesp_coo_print
F16 = sesp_csr_print
F17 = sesp_csc_print
F18 = z_memory_helpers
F19 = sesp_den_memory
F20 = sesp_coo_memory
F21 = sesp_csr_memory
F22 = sesp_csc_memory
F23 = sesp_den_copy
F24 = sesp_coo_copy
F25 = sesp_csr_copy
F26 = sesp_csc_copy
F27 = sesp_den_save
F28 = sesp_coo_save
F29 = sesp_csr_save
F30 = sesp_csc_save
F31 = z_save_helper
F32 = sesp_den_scal
F33 = sesp_coo_scal
F34 = sesp_csr_scal
F35 = sesp_csc_scal
F36 = sesp_den_cc
F37 = sesp_coo_cc
F38 = sesp_csr_cc
F39 = sesp_csc_cc
F40 = sesp_den_t
F41 = sesp_coo_t
F42 = sesp_csr_t
F43 = sesp_csc_t
F44 = sesp_den_mvdot_arr
F45 = sesp_csr_mvdot_arr
F46 = sesp_den_add
F47 = sesp_coo_add
F48 = sesp_csr_add
F49 = sesp_csc_add
F50 = sesp_den_mmdot_den
F51 = sesp_csr_mmdot_csc
F52 = sesp_den_kron
F53 = sesp_coo_kron
F54 = z_operations_helpers
F55 = z_comparer
F56 = sesp_den_load
F57 = sesp_coo_load
F58 = sesp_csr_load
F59 = sesp_csc_load
F60 = z_load_helper
F61 = sesp_coo_clean
F62 = sesp_csr_clean
F63 = sesp_csc_clean

# Specify object code files
OBJ_FILENAMES = ${F01}.o ${F02}.o ${F03}.o ${F04}.o ${F05}.o ${F06}.o ${F07}.o \
				${F08}.o ${F09}.o ${F10}.o ${F11}.o ${F12}.o ${F13}.o ${F14}.o \
				${F15}.o ${F16}.o ${F17}.o ${F18}.o ${F19}.o ${F20}.o ${F21}.o \
				${F22}.o ${F23}.o ${F24}.o ${F25}.o ${F26}.o ${F27}.o ${F28}.o \
				${F29}.o ${F30}.o ${F31}.o ${F32}.o ${F33}.o ${F34}.o ${F35}.o \
				${F36}.o ${F37}.o ${F38}.o ${F39}.o ${F39}.o ${F40}.o ${F41}.o \
				${F42}.o ${F43}.o ${F44}.o ${F45}.o ${F46}.o ${F47}.o ${F48}.o \
				${F49}.o ${F50}.o ${F51}.o ${F52}.o ${F53}.o ${F54}.o ${F55}.o \
				${F56}.o ${F57}.o ${F58}.o ${F59}.o ${F60}.o ${F61}.o ${F62}.o \
				${F63}.o
OBJ_FILES = ${foreach file, ${OBJ_FILENAMES}, ${OBJ}/${file}}


### Print info
all: ${TARGET}
	@echo -e "\nBuilding process completed successfully.\n"


### Link
${TARGET}: ${OBJ_FILES}
	${LD} ${OLVL} -o ${LIB}/libsesp.so \
	                    ${OBJ}/${F01}.o \
	                    ${OBJ}/${F02}.o \
	                    ${OBJ}/${F03}.o \
	                    ${OBJ}/${F04}.o \
	                    ${OBJ}/${F05}.o \
	                    ${OBJ}/${F06}.o \
	                    ${OBJ}/${F07}.o \
	                    ${OBJ}/${F08}.o \
	                    ${OBJ}/${F09}.o \
	                    ${OBJ}/${F10}.o \
	                    ${OBJ}/${F11}.o \
	                    ${OBJ}/${F12}.o \
	                    ${OBJ}/${F13}.o \
	                    ${OBJ}/${F14}.o \
	                    ${OBJ}/${F15}.o \
	                    ${OBJ}/${F16}.o \
	                    ${OBJ}/${F17}.o \
	                    ${OBJ}/${F18}.o \
	                    ${OBJ}/${F19}.o \
	                    ${OBJ}/${F20}.o \
	                    ${OBJ}/${F21}.o \
	                    ${OBJ}/${F22}.o \
	                    ${OBJ}/${F23}.o \
	                    ${OBJ}/${F24}.o \
	                    ${OBJ}/${F25}.o \
	                    ${OBJ}/${F26}.o \
	                    ${OBJ}/${F27}.o \
	                    ${OBJ}/${F28}.o \
	                    ${OBJ}/${F29}.o \
						${OBJ}/${F30}.o \
						${OBJ}/${F31}.o \
	                    ${OBJ}/${F32}.o \
	                    ${OBJ}/${F33}.o \
	                    ${OBJ}/${F34}.o \
	                    ${OBJ}/${F35}.o \
	                    ${OBJ}/${F36}.o \
	                    ${OBJ}/${F37}.o \
	                    ${OBJ}/${F38}.o \
	                    ${OBJ}/${F39}.o \
	                    ${OBJ}/${F40}.o \
	                    ${OBJ}/${F41}.o \
	                    ${OBJ}/${F42}.o \
	                    ${OBJ}/${F43}.o \
	                    ${OBJ}/${F44}.o \
	                    ${OBJ}/${F45}.o \
	                    ${OBJ}/${F46}.o \
	                    ${OBJ}/${F47}.o \
	                    ${OBJ}/${F48}.o \
	                    ${OBJ}/${F49}.o \
	                    ${OBJ}/${F50}.o \
	                    ${OBJ}/${F51}.o \
	                    ${OBJ}/${F52}.o \
	                    ${OBJ}/${F53}.o \
	                    ${OBJ}/${F54}.o \
	                    ${OBJ}/${F55}.o \
	                    ${OBJ}/${F56}.o \
	                    ${OBJ}/${F57}.o \
	                    ${OBJ}/${F58}.o \
	                    ${OBJ}/${F59}.o \
	                    ${OBJ}/${F60}.o \
	                    ${OBJ}/${F61}.o \
	                    ${OBJ}/${F62}.o \
	                    ${OBJ}/${F63}.o \
			    -lm


### Compile

# sesp_den_tocoo.c
${OBJ}/${F01}.o: ${SRC}/${F01}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F01}.o -c ${SRC}/${F01}.c

# sesp_coo_tocsr.c
${OBJ}/${F02}.o: ${SRC}/${F02}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F02}.o -c ${SRC}/${F02}.c

# sesp_csr_tocoo.c
${OBJ}/${F03}.o: ${SRC}/${F03}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F03}.o -c ${SRC}/${F03}.c

# sesp_coo_toden.c
${OBJ}/${F04}.o: ${SRC}/${F04}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F04}.o -c ${SRC}/${F04}.c

# sesp_csc_tocoo.c
${OBJ}/${F05}.o: ${SRC}/${F05}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F05}.o -c ${SRC}/${F05}.c

# sesp_csc_tocsr.c
${OBJ}/${F06}.o: ${SRC}/${F06}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F06}.o -c ${SRC}/${F06}.c

# sesp_coo_tocsc.c
${OBJ}/${F07}.o: ${SRC}/${F07}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F07}.o -c ${SRC}/${F07}.c

# sesp_csr_tocsc.c
${OBJ}/${F08}.o: ${SRC}/${F08}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F08}.o -c ${SRC}/${F08}.c

# sesp_den_tocsr.c
${OBJ}/${F09}.o: ${SRC}/${F09}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F09}.o -c ${SRC}/${F09}.c

# sesp_csr_toden.c
${OBJ}/${F10}.o: ${SRC}/${F10}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F10}.o -c ${SRC}/${F10}.c

# sesp_den_tocsc.c
${OBJ}/${F11}.o: ${SRC}/${F11}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F11}.o -c ${SRC}/${F11}.c

# sesp_csc_toden.c
${OBJ}/${F12}.o: ${SRC}/${F12}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F12}.o -c ${SRC}/${F12}.c

# z_print_helpers.c
${OBJ}/${F13}.o: ${SRC}/${F13}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F13}.o -c ${SRC}/${F13}.c

# sesp_den_print.c
${OBJ}/${F14}.o: ${SRC}/${F14}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F14}.o -c ${SRC}/${F14}.c

# sesp_coo_print.c
${OBJ}/${F15}.o: ${SRC}/${F15}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F15}.o -c ${SRC}/${F15}.c

# sesp_csr_print.c
${OBJ}/${F16}.o: ${SRC}/${F16}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F16}.o -c ${SRC}/${F16}.c

# sesp_csc_print.c
${OBJ}/${F17}.o: ${SRC}/${F17}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F17}.o -c ${SRC}/${F17}.c

# sesp_memory_helpers.c
${OBJ}/${F18}.o: ${SRC}/${F18}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F18}.o -c ${SRC}/${F18}.c

# sesp_den_memory.c
${OBJ}/${F19}.o: ${SRC}/${F19}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F19}.o -c ${SRC}/${F19}.c

# sesp_coo_memory.c
${OBJ}/${F20}.o: ${SRC}/${F20}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F20}.o -c ${SRC}/${F20}.c

# sesp_csr_memory.c
${OBJ}/${F21}.o: ${SRC}/${F21}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F21}.o -c ${SRC}/${F21}.c

# sesp_csc_memory.c
${OBJ}/${F22}.o: ${SRC}/${F22}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F22}.o -c ${SRC}/${F22}.c

# sesp_den_copy.c
${OBJ}/${F23}.o: ${SRC}/${F23}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F23}.o -c ${SRC}/${F23}.c

# sesp_coo_copy.c
${OBJ}/${F24}.o: ${SRC}/${F24}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F24}.o -c ${SRC}/${F24}.c

# sesp_csr_copy.c
${OBJ}/${F25}.o: ${SRC}/${F25}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F25}.o -c ${SRC}/${F25}.c

# sesp_csc_copy.c
${OBJ}/${F26}.o: ${SRC}/${F26}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F26}.o -c ${SRC}/${F26}.c

# sesp_den_save.c
${OBJ}/${F27}.o: ${SRC}/${F27}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F27}.o -c ${SRC}/${F27}.c

# sesp_coo_save.c
${OBJ}/${F28}.o: ${SRC}/${F28}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F28}.o -c ${SRC}/${F28}.c

# sesp_csr_save.c
${OBJ}/${F29}.o: ${SRC}/${F29}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F29}.o -c ${SRC}/${F29}.c

# sesp_csc_save.c
${OBJ}/${F30}.o: ${SRC}/${F30}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F30}.o -c ${SRC}/${F30}.c

# z_save_helper.c
${OBJ}/${F31}.o: ${SRC}/${F31}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F31}.o -c ${SRC}/${F31}.c

# sesp_den_scal.c
${OBJ}/${F32}.o: ${SRC}/${F32}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F32}.o -c ${SRC}/${F32}.c

# sesp_coo_scal.c
${OBJ}/${F33}.o: ${SRC}/${F33}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F33}.o -c ${SRC}/${F33}.c

# sesp_csr_scal.c
${OBJ}/${F34}.o: ${SRC}/${F34}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F34}.o -c ${SRC}/${F34}.c

# sesp_csc_scal.c
${OBJ}/${F35}.o: ${SRC}/${F35}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F35}.o -c ${SRC}/${F35}.c

# sesp_den_cc
${OBJ}/${F36}.o: ${SRC}/${F36}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F36}.o -c ${SRC}/${F36}.c

# sesp_coo_cc
${OBJ}/${F37}.o: ${SRC}/${F37}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F37}.o -c ${SRC}/${F37}.c

# sesp_csr_cc
${OBJ}/${F38}.o: ${SRC}/${F38}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F38}.o -c ${SRC}/${F38}.c

# sesp_csc_cc
${OBJ}/${F39}.o: ${SRC}/${F39}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F39}.o -c ${SRC}/${F39}.c

# sesp_den_t
${OBJ}/${F40}.o: ${SRC}/${F40}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F40}.o -c ${SRC}/${F40}.c

# sesp_coo_t
${OBJ}/${F41}.o: ${SRC}/${F41}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F41}.o -c ${SRC}/${F41}.c

# sesp_csr_t
${OBJ}/${F42}.o: ${SRC}/${F42}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F42}.o -c ${SRC}/${F42}.c

# sesp_csc_t
${OBJ}/${F43}.o: ${SRC}/${F43}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F43}.o -c ${SRC}/${F43}.c

# sesp_den_mvdot_arr
${OBJ}/${F44}.o: ${SRC}/${F44}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F44}.o -c ${SRC}/${F44}.c

# sesp_csr_mvdot_arr
${OBJ}/${F45}.o: ${SRC}/${F45}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F45}.o -c ${SRC}/${F45}.c

# sesp_den_add
${OBJ}/${F46}.o: ${SRC}/${F46}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F46}.o -c ${SRC}/${F46}.c

# sesp_coo_add
${OBJ}/${F47}.o: ${SRC}/${F47}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F47}.o -c ${SRC}/${F47}.c

# sesp_csr_add
${OBJ}/${F48}.o: ${SRC}/${F48}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F48}.o -c ${SRC}/${F48}.c

# sesp_csc_add
${OBJ}/${F49}.o: ${SRC}/${F49}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F49}.o -c ${SRC}/${F49}.c

# sesp_den_mmdot_den
${OBJ}/${F50}.o: ${SRC}/${F50}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F50}.o -c ${SRC}/${F50}.c

# sesp_csr_mmdot_csc
${OBJ}/${F51}.o: ${SRC}/${F51}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F51}.o -c ${SRC}/${F51}.c

# sesp_den_kron
${OBJ}/${F52}.o: ${SRC}/${F52}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F52}.o -c ${SRC}/${F52}.c

# sesp_coo_kron
${OBJ}/${F53}.o: ${SRC}/${F53}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F53}.o -c ${SRC}/${F53}.c

# z_operations_helpers
${OBJ}/${F54}.o: ${SRC}/${F54}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F54}.o -c ${SRC}/${F54}.c

# comparer.c
${OBJ}/${F55}.o: ${SRC}/${F55}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F55}.o -c ${SRC}/${F55}.c

# sesp_den_load.c
${OBJ}/${F56}.o: ${SRC}/${F56}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F56}.o -c ${SRC}/${F56}.c

# sesp_coo_load.c
${OBJ}/${F57}.o: ${SRC}/${F57}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F57}.o -c ${SRC}/${F57}.c

# sesp_csr_load.c
${OBJ}/${F58}.o: ${SRC}/${F58}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F58}.o -c ${SRC}/${F58}.c

# sesp_csc_load.c
${OBJ}/${F59}.o: ${SRC}/${F59}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F59}.o -c ${SRC}/${F59}.c

# z_load_helper.c
${OBJ}/${F60}.o: ${SRC}/${F60}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F60}.o -c ${SRC}/${F60}.c

# sesp_coo_clean.c
${OBJ}/${F61}.o: ${SRC}/${F61}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F61}.o -c ${SRC}/${F61}.c

# sesp_csr_clean.c
${OBJ}/${F62}.o: ${SRC}/${F62}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F62}.o -c ${SRC}/${F62}.c

# sesp_csr_clean.c
${OBJ}/${F63}.o: ${SRC}/${F63}.c
	${CC} ${FLAGS} ${OLVL} -o ${OBJ}/${F63}.o -c ${SRC}/${F63}.c


### Cleanup

clean:
	rm ${OBJ}/*.o
	rm ${LIB}/libsesp.so

.PHONY: clean
