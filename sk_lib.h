/* ************************************************************************** */
#ifndef SK_LIB_H
# define SK_LIB_H
# include "sk_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* ************************************************************************** */

void 		sk_printmem(void *ptr, size_t size);
int         sk_isset(char c, const char *set);
int         sk_ischar(char c);
//int         sk_ischar(char c_in, char c_cmp);

/* ************************************************************************** */
#endif
