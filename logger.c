#include "logger.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

//Global variables to keep track of log files.
static int LOG_LEVEL = LOGGER_OFF;
// static bool write_to_file = false;
static p_log_func serial_write;
 static const char* log_level_strings[] = {
     "OFF",
     "[DEBUG]",
     "[INFO]",
     "[WARNING]",
     "[ERROR]",
 };
const char* colors[] = {
    "\x1B[0m",
    "\x1B[34m",
    "\x1B[32m",
    "\x1B[33m",
    "\x1B[31m",
};

char buff[2048];

void log_func(LOGGING_LEVELS level,const char *TAG, const char *frmt, ...) {
    if(LOG_LEVEL > level) {
        return;
    } 
    char *format = buff;
    sprintf(format,"%s%s%s : ",colors[level],log_level_strings[level],TAG);
    va_list argp;
    va_start(argp, frmt);
    vsprintf(format+strlen(format),frmt, argp);
    va_end(argp);
//    serial_write(colors[level]);
//    serial_write(log_level_strings[level]);
//    serial_write(TAG);
//    serial_write(" : ");
    format[strlen(format)] = '\n';
    serial_write(format);
}

void logger_init(LOGGING_LEVELS level,p_log_func p_func) {
    LOG_LEVEL = level;
    serial_write = p_func;
}
