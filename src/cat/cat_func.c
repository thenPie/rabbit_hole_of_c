#include "cat_func.h"

#include <unistd.h>
#include <stdio.h>

void cat(int argc, char** argv) {
    if (argc >= 2) {
        cat_in_action(argc, argv);
    }
}

void cat_in_action(int argc, char** argv) {
    printf("%d\n", argc);
    int valid = 0;
    FILE* file = fopen(argv[optind], "r");
    if (file == NULL) {
        valid++;
    }
    if (valid == 0) {
        char c;
        while ((c = fgetc(file)) != EOF) {
            printf("%c", c);
        }
    }
    fclose(file);
}