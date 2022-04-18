
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

short create_employee_data(int, int, char);
void print_employee(short);

int main(void)
{

  int id_no = 412;   /* 00000000 00000000 00000001 10011100 */
  int job_type = 53; /* 00000000 00000000 00000000 10110101 */
  char gender = 'm';

  short employee = create_employee_data(id_no, job_type, gender); /* 0 01101010 */
  print_employee(employee);

  return EXIT_SUCCESS;
}

short create_employee_data(int id_no, int job_type, char gender)
{
  short employee = 0; /* start with all the bits off */

  employee |= (gender == 'm' || gender == 'M') ? 0 : 1; /* 00000000 00000000 */
  employee |= job_type << 1; /* 00000000 00000000 | 00000000 01101010 = 00000000 01101010 */
  employee |= id_no << 7; /* 00000000 01101010 | 11001110 00000000 = 11001110 01101010 */

  return employee; /* 11001110 01101010 */
}

void print_employee(short e)
{
  short i;
  short n = sizeof(short) * CHAR_BIT;
  short mask = 1 << (n - 1);

  for(i = 1; i <= n; ++i) {
    putchar((e & mask) ? '1' : '0');
    e <<= 1;
    if (i % CHAR_BIT == 0 && i < n)
      putchar(' ');
  }
  putchar('\n');  
}
