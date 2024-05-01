#include "cat_func.h"

#include <stdio.h>
#include <getopt.h>
#include <unistd.h>

void cat(int argc, char** argv) {
  if (argc >= 2) {
    cat_in_action(argc, argv);
  }
}

void cat_in_action(int argc, char** argv) {
  // print_args(argc, argv);

  int number_non_empty_lines_b = -1;  // number-nonblank
  int show_dollar_ends_e = -1;
  int number_all_lines_n = -1;      // number
  int suppress_empty_lines_s = -1;  // squeeze-blank
  int show_tabs_t = -1;

  struct option long_opt[] =
  { {"number-nonblank", 0, 0, 'b'},
    {"number", 0, 0, 'n'},
    {"squeeze-blank", 0, 0, 's'} };

  // int b_f = 1; // нумерует только непустые строки
  // int e_f = 1; // \n отображает как $
  // int n_f = 1; // нумерует все строки
  // int s_f = 1; // сжимает смежные пустые строки
  // int t_f = 1; // отображает табы как ^I

  int opt;
  while ((opt = getopt_long (argc, argv, ":benstET", long_opt, NULL)) != -1) {
    switch (opt) {
      case 'b':
        printf("%c is option\n", (char)opt);
        number_non_empty_lines_b = 0;
        break;
      case 'e':
        printf("%c is option\n", (char)opt);
        show_dollar_ends_e = 0;
        break;
      case 'n':
        printf("%c is option\n", (char)opt);
        number_all_lines_n = 0;
        break;
      case 's':
        printf("%c is option\n", (char)opt);
        suppress_empty_lines_s = 0;
        break;
      case 't':
        printf("%c is option\n", (char)opt);
        show_tabs_t = 0;
        break;
      case 'E':
        printf("%c is option\n", (char)opt);
        show_dollar_ends_e = 0;
        break;
      case 'T':
        printf("%c is option\n", (char)opt);
        show_tabs_t = 0;
        break;
      case '?':
        // printf("%c no option like this\n", (char)opt);
        break;
      default:
        break;
    }
  }

  for (int i = 1; i < argc; i++) {
    FILE* file = fopen(argv[i], "r");
    if (file != NULL) {
      char c;
      while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
      }
    }
    fclose(file);
  }
}

// void output(FILE* file, int argc, char** argv, struct option long_opt[3], int b,
//             int e, int n, int s, int t) {
//   int opt;
//   while ((opt = getopt_long(argc, argv, "benstET", long_opt, NULL)) != -1) {
//     switch (opt) {
//       case 'b':
//         printf("%s - is option\n", (char)opt);
//         break;
//       case 'e':
//         break;
//       case 'n':
//         break;
//       case 's':
//         break;
//       case 't':
//         break;
//       case 'E':
//         break;
//       case 'T':
//         break;
//     }
//   }

//   char c;
//   while ((c = fgetc(file)) != EOF) {
//     printf("%c", c);
//   }
// }

// getopt, getopt_long, getopt_long_only, optarg, optind, opterr,
// optopt - Parse command-line options

void print_args(int argc, char** argv) {
  printf("%d - is argc\n", argc - 1);
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  printf("%s - is non-argument option\n", argv[optind]);
}