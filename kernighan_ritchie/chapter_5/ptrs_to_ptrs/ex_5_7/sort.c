
/* swap: interchange v[i] and v[j] */
void
swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* str_cmp: return <0 if s < t, 0 if s == t, >0 if s > t */
int
str_cmp(char *s, char *t)
{
  while (*s == *t) {
    if (*s == '\0')
      return 0;
    s++, t++;
  }
  return *s - *t;
}

/* qsort: sort v[left]...v[right] into increasing order */
void
qsort(char *v[], int left, int right)
{
  int i, last;

  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (str_cmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}
