
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char dept_name[25];
  int  dept_no;
} dept;

typedef struct {
  int  house_no;
  char street[20];
  char town[15];
  char postcode[8];
} home_address;

typedef struct {
  char          name[25];
  int           employee_id;
  dept          department;
  home_address  *a_ptr;
  double        salary;
} employee_data;


employee_data update_dept_no_pbv(employee_data);
void          update_dept_no_ptr(employee_data *);
void          prn_employee(employee_data);
