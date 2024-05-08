#include <ctype.h>
#include <string.h>
#include "revwords.h"

void reverse_substring(char str[], int start, int end) { 
  char c;

  for (; start < end; start++, end--) {
    c = str[start];
    str[start] = str[end];
    str[end] = c;
  }
}


int find_next_start(char str[], int len, int i) { 
  int k;

  for (k = i; k < len; k++)
    if (isalpha(str[k]))
      return k;

  return -1;
}

int find_next_end(char str[], int len, int i) {
  int k;

  for(k = i; k < len; k++)
    if (isalpha(str[k]) == 0)
      return k;

  return k;
}

void reverse_words(char s[]) { 
  int start, end, len;

  start = 0;
  len = strlen(s);

  while ((start = find_next_start(s, len, start)) >= 0 && start < len) {
    end = find_next_end(s, len, start);
    reverse_substring(s, start, end-1);
    start = end;
  }
}
