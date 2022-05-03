#include <stdio.h>
#include <stdlib.h>

int  calculate_length(char s[]);
void unescape(char s[], char t[]);

int
main(void)
{
  char t[] = "\\thello\\n\\t\\tworld!\\nI've dr\\n\\nopped\\t\\t off the end\\nit would seem";
  int  s_length;

  s_length = calculate_length(t);

  char s[s_length];
  unescape(s, t);
  printf("%s\n", s);

  return EXIT_SUCCESS;
}

/* calculate_length: calculates the length for a reverse escaped string if s was copied */
int
calculate_length(char s[]) {

  int i, count;

  for (i = count = 0; s[i] != '\0'; ++i) {
    switch (s[i]) {
    case '\\':
      switch (s[++i]) {
      case 't': case 'n':
        count++;
        break;
      default:
        count += 2;
        break;
      }
      break;
    default:
      count++;
      break;
    }
  }
  return count + 1;
}

/* unescape: copies t to s, converting escaped tabs and newlines into real characters */
void
unescape(char s[], char t[])
{
  int i, j;

  for (i = j = 0; t[i] != '\0'; ++i) {
    switch (t[i]) {
    case '\\':
      switch (t[++i]) {
      case 't':
        s[j++] = '\t';
        break;
      case 'n':
        s[j++] = '\n';
        break;
      default:
        s[j++] = '\\';
        s[j++] = t[i];
        break;
      }
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j] = '\0';
}
