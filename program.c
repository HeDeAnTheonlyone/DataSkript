#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



char* getContents(FILE *file) {

    char *contents = malloc(200 * sizeof(char));
    fgets(contents, sizeof(200 * sizeof(char)), file);

    return contents;
}


typedef struct {
    int pos;
    char *context;
    Type type;
} Token;


Token* createToken(int pos, char *ctx, Type type) {

    Token *t = malloc(sizeof(Token));
    
    if (t != NULL) {
        t->pos = pos;
        t->context = strdup(ctx);
    }

    return t;
}


void destroyToken(Token *t) {

    free(t->context);
    free(t);
}



typedef enum {
    ENDOFLINE,
    WHITESPACE,
    DIGIT,
    LITERAL,
    FUNCTION
} Type;



Token* lex(char *line) {

    int position = 0;

    if (position >= strlen(line))
        return createToken(position, "", ENDOFLINE);

    if (isspace(*(line + position))) {
        int start = position;
        while (isspace(*(line + position))) {
            position++;
        }
        char *substring;
        return createToken(start, memcpy(substring, *(line - start), position - start), WHITESPACE);
    }

    if (isdigit(*(line + position))) {
        int start = position;
        while (isdigit(*(line + position))) {
            position++;
        }
        char *subString;
        return createToken(start, memcpy(subString, *(line + start), position - start), DIGIT);
    }

    if (isalpha(*(line + position))) {
        int start = position;
        while (isalpha(*(line + position))) {
            position++;
        }
        char *substring;
        return createToken(start, memcpy(substring, *(line + start), position - start), LITERAL);
    }
}



void addTokenToArr(Toke) {
    //TODO
}



int parse(Token *tokens) {
    //TODO
    return 0;
}



int main() {

    system("color 0A");
    printf("Please input the path to your DataSkript Project: ");

    char in[200];
    fgets(in, sizeof(in), stdin);
    in[strcspn(in, "\n")] = '\0';

    if (strlen(in) < 1) {
        printf("No project folder path given!");
        return 0;
    }

    char filePath = in;
    strcat(filePath, "/main.ds");

    FILE *file = fopen(filePath, "r");

    char *line;
    while (line = getContents(file) != NULL) {

        parse(lex(line));

        //TODO
    }

    fclose(file);

    return 0;
}