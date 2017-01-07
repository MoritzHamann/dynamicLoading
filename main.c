#include "stdio.h"
#include "stdlib.h"
#include "dlfcn.h"

int main(int argc, char *argv[]) {

  // variable declaration
  void* handle;
  char* error;
  int (*addX)(int);


  // open version 1 of the library
  handle = dlopen("./libverison1.A.dylib", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    return 1;
  }

  // load function address
  addX = dlsym(handle, "addX");

  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    return 1;
  }

  // test the version 1 of addX (should add 4)
  printf("Version 1 (+4): addX(2)\n");
  printf("%i\n", (*addX)(2));

  dlclose(handle);

  // use now version 2
  handle = dlopen("./libverison2.A.dylib", RTLD_LAZY);
  if (!handle) {
    fputs(dlerror(), stderr);
    return 1;
  }

  addX = dlsym(handle, "addX");

  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    return 1;
  }

  // test version 2 (should add 8)
  printf("Version 2 (+8): addX(2)\n");
  printf("%i\n", (*addX)(2));

  return 0;
}
