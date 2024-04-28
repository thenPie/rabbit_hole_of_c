#include "cat_func.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void cat(int argc, char** argv) {
  int opt;

  while ((opt = getopt(argc, argv, "benstv:")) != -1) {
    switch (opt) {
        case 'b':
            break;
        case 'e':
            break;
        case 'n':
            break;
        case 's':
            break;
        case 't':
            break;
        case 'v':
            break;
    }
  }
}