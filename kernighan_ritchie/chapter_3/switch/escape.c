#include <stdio.h>
#include <stdlib.h>

int  calculate_length(char s[]);
void escape(char s[], char t[]);

int
main(void)
{

  char t[] = "\thello\n\t\tworld!\nI've dr\n\nopped\t\t off the end\nit would seem";
  int  s_length;

  s_length = calculate_length(t);
  printf("%s\nescaped length: %d\n", t, s_length);

  char s[s_length];
  escape(s, t);
  printf("%s\n", s);

  return EXIT_SUCCESS;
}

/* calculate_length: calculates the length for an escaped string if s was copied */
int
calculate_length(char s[])
{
  int  i, count;

  for (i = count = 0; s[i] != '\0'; ++i) {
    switch(s[i]) {
    case '\t': case '\n':
      count += 2;
      break;
    default:
      count++;
      break;
    }
  }
  return count + 1; // +1 for the null char
}

/* escape: copies t to s, converting newlines and tabs into visible \n and \t respectively */
void
escape(char s[], char t[])
{
  int i, j;

  for (i = j = 0; t[i] != '\0'; ++i) {
    switch (t[i]) {
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j] = '\0';
}
