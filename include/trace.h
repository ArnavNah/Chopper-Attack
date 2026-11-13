#ifndef TRACE_H
#define TRACE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void recomp_trace_func_entry_str(const char* name);

#define TRACE_ENTRY() recomp_trace_func_entry_str(__func__);
#define TRACE_RETURN()

#ifdef __cplusplus
}
#endif

#endif
