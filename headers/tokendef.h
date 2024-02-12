#ifndef TOKENDEF_H
#define TOKENDEF_H

typedef enum {
    ENDOFLINE,
    WHITESPACE,
    DIGIT,
    LITERAL,
    FUNCTION
} type_t;

typedef struct {
    int pos;
    char *context;
    type_t type;
} token_t;

#endif