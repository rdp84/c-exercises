#include <string.h>
#include "example4.h"

void reverse(char str[]) {
  char c;
  int i, j;

  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    c = str[i];
    str[i] = str[j];
    str[j] = c;
  }
}
