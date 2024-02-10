#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "diagnostics.h"
#include "tokendef.h"



const char* getTypeName(type_t type);

token_t* createToken(int pos, char *ctx, type_t type);

void destroyToken(token_t *t);

token_t* nextToken(char *line, int *position);

void addTokenToArr(token_t *token);



const char* getTypeName(type_t type) {
    switch (type) {
        case ENDOFLINE:
            return "ENDOFLINE";
        case WHITESPACE:
            return "WHITESPACE";
        case DIGIT:
            return "DIGIT";
        case LITERAL:
            return "LITERAL";
        case FUNCTION:
            return "FUNCTION";

        default:
            return "UNKNOWN";
    }
}



token_t* createToken(int pos, char *ctx, type_t _type) {
    token_t *t = malloc(sizeof(token_t));

    if (t != NULL) {
        t->pos = pos;
        t->context = strdup(ctx);
        t->type = _type;
    }

    return t;
}



void destroyToken(token_t *t) {
    free(t->context);
    free(t);
}



token_t* nextToken(char *line, int *position) {
    int pos = *position;
    token_t *token = NULL;

    if (pos >= strlen(line)) {
        token = createToken(pos, "", ENDOFLINE);
    }
    else if (isspace(line[pos])) {
        int start = pos;
        while (isspace(line[pos])) {
            pos++;
        }
        char *substring;
        token = createToken(start, memcpy(substring, line + start, pos - start), WHITESPACE);
    }
    else if (isdigit(line[pos])) {
        int start = pos;
        while (isdigit(line[pos])) {
            pos++;
        }
        char *subString;
        token = createToken(start, memcpy(subString, line + start, pos - start), DIGIT);
    }
    else if (isalpha(line[pos])) {
        int start = pos;
        while (isalpha(line[pos])) {
            pos++;
        }
        char *substring;
        token = createToken(start, memcpy(substring, line + start, pos - start), LITERAL);
    }

    if (token == NULL)
        compileStatus(NULL, 0, pos, true);

    *position = pos;
    return token;
}



void addTokenToArr(token_t *token) {

    // TODO
}