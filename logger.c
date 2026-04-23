#include <stdio.h>
#include <time.h>
#include "logger.h"

static FILE* log_fp = NULL;

void log_init(const char* filename) {
    log_fp = fopen(filename, "a");
}

void log_event(const char* msg) {
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%H:%M:%S", t);

    printf("[%s] %s\n", timestamp, msg);
    if (log_fp) {
        fprintf(log_fp, "[%s] %s\n", timestamp, msg);
        fflush(log_fp);
    }
}

void log_close() {
    if (log_fp) fclose(log_fp);
}