#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diagnostics.h"
#include "tokenfunc.h"

//TODO (Make Dynamic token_t array for the returned tokens, Fix why the pogram crahes, Finc potential memory leaks)

void lex(char *line);



int main() {
    system("color 0A");
    printf("Input DataSkript Project Path: ");

    char *inPath = malloc(1024 * sizeof(char));
    if (inPath == NULL) {
        printErr("Input pointer memory allocation failed!");
        return 1;
    }

    fgets(inPath, 1024, stdin);
    inPath[strcspn(inPath, "\n")] = '\0';

    if (strlen(inPath) < 1) {
        printErr("No project folder path given!");
        return 1;
    }

    char *filePath = inPath;
    strcat(filePath, "/main.ds");

    FILE *file;

    file = fopen(filePath, "r");
    size_t lnBuffer = 2048;
    char *line = malloc(lnBuffer * sizeof(char));

    if (file == NULL) {
        printErr("Directory with the give path or main file does not exist!");
        return 1;
    }

    fgets(line, lnBuffer, file);
    while (line != NULL) {
        lex(line);

        // TODO

        fgets(line, lnBuffer, file);
    }

    free(line);
    line = NULL;
    
    free(inPath);
    fclose(file);

    return 0;
}



void lex(char *line) {
    
    token_t *token = NULL;
    int position = 0;
    do {
        compileStatus(NULL, 1, 0, false);
        
        if (token != NULL)
            destroyToken(token);
        
        token = nextToken(line, &position);
        if (token == NULL)
            return;

        printf("TOKEN ===> %d | %s | %s", token->pos, token->context, getTypeName(token->type));

    } while (token->type != ENDOFLINE);

    destroyToken(token);
}



// int parse(token_t *tokens) {
//     //TODO
//     return 0;
// }
