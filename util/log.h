#ifndef _UTIL_LOG_H_
#define _UTIL_LOG_H_

#include <stdio.h>
#include <string.h>

/* Get the string of the C file that the log came from */
#define LOG_C_FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/* When this is defined, logging is turned on */
#define MOBA_SYSTEM_LOGS_ENABLED

/* Log formatting */
#ifdef MOBA_SYSTEM_LOGS_ENABLED
/* Debug logging that can be enabled/disabled on a per-file basis */
#define debug_log(format, ...) printf ("\033[1;34m%14s\033[;0m in \033[22;33m%s():\033[;0m " format "\n", LOG_C_FILE, __func__, ##__VA_ARGS__)
#else //MOBA_SYSTEM_LOGS_ENABLED
#define debug_log(...) do { } while (0)
#endif

#endif // _UTIL_LOG_H_
