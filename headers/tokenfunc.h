#ifndef TOKENFUNC_H
#define TOKENFUNC_H

#include "tokendef.h"

char* getTypeName(type_t type);

token_t *createToken(int pos, char *ctx, type_t type);

void destroyToken(token_t *t);

token_t *nextToken(char *line, int *position);

void addTokenToArr(token_t *token);

#endif