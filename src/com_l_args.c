#include <stdio.h>

// first argc and argv is the command that starts the App,
// so it's always 0
int main(int argc, char* argv[]) {
  // checks if there are any arguments given to it
  if (argc > 0) {
    // prints out the amount of given arguments
    printf("%d\n", argc - 1);
    // prints out all the given arguments
    for (int i = 1; i < argc; i++) {
      printf("%d - %s\n", i, argv[i]);
    }
  }
  return 0;
}