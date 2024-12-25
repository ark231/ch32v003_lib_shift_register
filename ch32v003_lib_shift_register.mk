ch32v003_lib_shift_register?=./
ADDITIONAL_C_FILES+=$(ch32v003_lib_shift_register)/lib74HC595.c $(ch32v003_lib_shift_register)/simple.c
EXTRA_CFLAGS+=-I$(ch32v003_lib_shift_register)
