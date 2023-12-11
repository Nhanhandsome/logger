#ifndef LOGGER_H
#define LOGGER_H

#include <stdlib.h>
#include <stdbool.h>

#define RESET 0

typedef enum {
    OFF,
    DEBUG,
    INFO,
    WARNING,
    ERROR
} LOGGING_LEVELS;

typedef void (*p_log_func)(const char *s);

/**
 * @brief Function to initialize the logger.
 *
 * @params[in] level Log level.
 * @params[in] filename Path to the log file.
 * @params[in] to_file Boolean variable to allow writing to file or to stderr stream.
 *
 * @retval None.
 */
void logger_init(LOGGING_LEVELS,p_log_func);

/**
 * @brief Function to write the message to the log file.
 *
 * @params[in] level Log level.
 * @params[in] frmt Format message.
 * @params[in] ... Variable arguments.
 *
 * @retval None.
 */
void log_func(LOGGING_LEVELS level,const char *TAG, const char *frmt, ...);

#define log_debug(TAG,...) log_func(DEBUG,TAG,  __VA_ARGS__)
#define log_info(TAG,...)  log_func(INFO,TAG,__VA_ARGS__)
#define log_warn(TAG,...)  log_func(WARNING,TAG,__VA_ARGS__)
#define log_error(TAG,...) log_func(ERROR,TAG,__VA_ARGS__)

#endif