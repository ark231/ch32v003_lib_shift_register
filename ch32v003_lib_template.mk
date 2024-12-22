ch32v003_lib_template?=./
ADDITIONAL_C_FILES+=$(ch32v003_lib_template)/template.c
EXTRA_CFLAGS+=-I$(ch32v003_lib_template)
