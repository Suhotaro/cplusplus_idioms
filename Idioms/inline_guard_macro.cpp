#include "stdafx.h"
#include "inline_guard_macro.h" // Include header file as usual.

#ifndef MYPROJECT_INLINE_ENABLED
#define INLINE // INLINE is defined as empty string
#include "inline_guard_macro.ipp" // It is included only when MYPROJECT_INLINE_ENABLED is NOT defined, i.e. inlining is disabled.
#endif
