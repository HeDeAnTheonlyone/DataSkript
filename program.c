#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* getContents(FILE *file) {

}


typedef struct {
    int pos;
    char *context;
    char *type;
} Token;


Token* createToken(int pos, char *ctx, char *type) {

    Token *t = malloc(sizeof(Token));
    
    if (t != NULL) {
        t->pos = pos;
        t->context = strdup(ctx);
        t->type = strdup(type);
    }

    return t;
}


void destroyToken(Token *t) {

    free(t->context);
    free(t->type);
    free(t);
}



char* lex(char *projPath) {

    char filePath = projPath;
    strcat(filePath, "/main.ds");

    FILE *file = fopen(filePath, "r");

    //TODO

    return "";
}



int parse(Token *tokens) {

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

    printf("Parsing: %d", parse(lex(in)));

    return 0;
}