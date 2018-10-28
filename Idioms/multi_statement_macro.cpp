#include "stdafx.h"

#define MACRO(arg1, arg2) do {  \
  /* declarations, if any */    \
  int n = arg1;                   \
  int n2 = arg2;                   \
  /* ... */                     \
  } while(0)	/* (no trailing ; ) */

void multi_statement_macro()
{
	if (true)
		MACRO(1, 2); // Note: have no figure brakets
	else
		MACRO(11, 22); // Note: have no figure brakets
}