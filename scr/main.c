#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "diagnostics.h"
#include "tokenfunc.h"

//TODO (Make Dynamic token_t array for the returned tokens, Fix why the pogram crahes, Finc potential memory leaks)

void lex(char *line, char *projPath, char *filePath);



int main() {
    system("color 0A");
    printf("Input DataSkript Project Path: ");

    char *projPath = malloc(2048 * sizeof(char));
    if (projPath == NULL)
        error("Input pointer memory allocation failed!");

    fgets(projPath, 2048, stdin);
    projPath[strcspn(projPath, "\n")] = '\0';

    if (strlen(projPath) < 1)
        error("No project folder path given!");
    
    if (strlen(projPath) + 1 > 2048 - (strlen("/main.ds") + 1))
        error("Path to project is too long!");

    char *filePath = strdup(projPath);
    strcat(filePath, "/main.ds");

    FILE *file;
    file = fopen(filePath, "r");
    size_t lnBuffer = 2048;
    char *line = malloc(lnBuffer * sizeof(char));

    if (file == NULL)
        error("Directory with the give path or main file does not exist!");

    while (fgets(line, lnBuffer, file) != NULL)
    {
        lex(line, projPath, filePath);

        // TODO
    }

    printf("test");

    free(line);
    line = NULL;

    free(filePath);
    filePath = NULL;
    
    free(projPath);
    projPath = NULL;
    fclose(file);

    printf("\n\n\nPress ENTER to exit...");
    getchar();

    return 0;
}



void lex(char *line, char *projPath, char *filePath) {
    
    token_t *token = NULL;
    int position = 0;
    bool endLoop = false; 
    do {
        compileStatus(NULL, 1, 0, false);
        
        if (token != NULL)
            destroyToken(token);
        
        token = nextToken(line, &position);
        if (token == NULL)
            compileStatus(filePath, 0, 0, true);

        printf("TOKEN ===> %d | %s | %s\n", token->pos, *token->context, *getTypeName(token->type));

    } while (token->type != ENDOFLINE);

    destroyToken(token);
}



// int parse(token_t *tokens) {
//     //TODO
//     return 0;
// }
