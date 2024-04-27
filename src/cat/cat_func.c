#include "cat_func.h"

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
// #include <string.h>
#include <stdlib.h>
#include <unistd.h>

void cat(int argc, char** argv) {
  int opt;
  char* name = NULL;
  int age = -1;

  // Parse command line options
  while ((opt = getopt(argc, argv, "n:a:")) != -1) {
    switch (opt) {
      case 'n':
        name = optarg;
        break;
      case 'a':
        age = atoi(optarg);
        break;
      case '?':
        if (optopt == 'n' || optopt == 'a')
          fprintf(stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint(optopt))
          fprintf(stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
        // return 1;
      default:
        abort();
    }
  }

  // Check if mandatory options are provided
  if (name == NULL || age == -1) {
    fprintf(stderr, "Usage: %s -n <name> -a <age>\n", argv[0]);
    // return 1;
  }

  // Print out the parsed options
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
}