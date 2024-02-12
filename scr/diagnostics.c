#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void compileStatus(char *_file, int _line, int _position, bool err) {
    static char *file;
    static int line = 0;
    static int position = 0;

    if (_file != NULL)
        file = _file;

    line += _line;
    position += _position;

    if (err) {
        system("color 0C");
        printf("Compile Error in %s, at %d:%d", file, line, position);
        system("color CA");
        exit(1);
    }
}



void error(char *msg) {
        system("color 0C");
        printf("%s", msg);
        system("color 0A");
        exit(1);
    }