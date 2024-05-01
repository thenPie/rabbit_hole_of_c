#ifndef CAT_FUNC_H
#define CAT_FUNC_H

#include <stdio.h>
#include <getopt.h>

void cat(int argc, char** argv);
void cat_in_action(int argc, char** argv);

// void output(FILE* file, int argc, char** argv, struct option long_opt[], int b, int e, int n, int s, int t);

void print_args(int argc, char** argv);

#endif // !CAT_FUNC_H