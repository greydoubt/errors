#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

bool do_something(int a, int b, char** error) {
  // ...

  if(success == false) {
    if(*error == NULL) {
      char* message = "do_something(..) failed because success == false";
      *error = malloc((strlen(message) + 1) * sizeof(**error));
      strcpy(*error, message);
    }
    return false;
  }

  // ...

  return true;
}
int main(int argc, char* argv[]) {
  char* error = NULL;
  bool do_something_succeeded = do_something(10, 11, &error);
  if(! do_something_succeeded) {
    fprintf(stderr, error);
    assert(error != NULL);
    free(error);
    return EXIT_FAILURE;
  }
  else {
    assert(error == NULL);
  }
  return EXIT_SUCCESS;
}
