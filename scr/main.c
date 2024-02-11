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
    if (inPath == NULL)
        error("Input pointer memory allocation failed!");

    fgets(inPath, 1024, stdin);
    inPath[strcspn(inPath, "\n")] = '\0';

    if (strlen(inPath) < 1)
        error("No project folder path given!");

    char *filePath = inPath;
    strcat(filePath, "/main.ds");

    FILE *file;

    file = fopen(filePath, "r");
    size_t lnBuffer = 2048;
    char *line = malloc(lnBuffer * sizeof(char));

    if (file == NULL)
        error("Directory with the give path or main file does not exist!");

    while (fgets(line, lnBuffer, file) != NULL)
    {
        lex(line);

        // TODO
    }

    printf("test");

    free(line);
    line = NULL;
    
    free(inPath);
    fclose(file);

    printf("\n\n\nPress ENTER to exit...");
    getchar();

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

        printf("TOKEN ===> %d | %s | %s\n", token->pos, *token->context, getTypeName(token->type));

    } while (token->type != ENDOFLINE);

    destroyToken(token);
}



// int parse(token_t *tokens) {
//     //TODO
//     return 0;
// }
