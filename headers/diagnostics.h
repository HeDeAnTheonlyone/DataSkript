#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include <stdbool.h>

void compileStatus(char *_file, int _line, int _position, bool err);

void printErr(char *msg);

#endif