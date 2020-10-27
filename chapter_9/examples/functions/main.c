
#include "business.h"

int main(void)
{
  dept cs;
  strcpy(cs.dept_name, "Computer Science");
  cs.dept_no = 3;

  home_address ha;
  ha.house_no = 20;
  strcpy(ha.street, "Gladevalve Avenue");
  strcpy(ha.town, "Easingvold");
  strcpy(ha.postcode, "XX8 3YY");

  employee_data e;
  strcpy(e.name, "Joe Bloggs");
  e.employee_id = 23675;
  e.department = cs;
  e.a_ptr = &ha;
  e.salary = 23500;

  prn_employee(e);
  e = update_dept_no_pbv(e);
  prn_employee(e);

  update_dept_no_ptr(&e);
  prn_employee(e);

  home_address ha2 = {22, "Gladevale Avenue", "Easingvold", "XX8 3YY"};
  dept ai = {"AI", 4};
  employee_data e2 = {"John Smith", 23676, ai, &ha2, 23600};
  prn_employee(e2);

  return EXIT_SUCCESS;
}

employee_data update_dept_no_pbv(employee_data e)
{
  int n;

  printf("Please input new department number: ");
  scanf("%d", &n);
  e.department.dept_no = n;

  return e;
}

void update_dept_no_ptr(employee_data *p)
{
  int n;

  printf("Please input new department number: ");
  scanf("%d", &n);
  p->department.dept_no = n;
}

void prn_employee(employee_data e) {

  printf("Name: %s\nId: %d\n"
         "Department - name: %s, id: %d\n"
         "Address: %d, %s, %s, %s\n"
         "Salary: %lf\n",
         e.name, e.employee_id,
         e.department.dept_name, e.department.dept_no,
         e.a_ptr->house_no, e.a_ptr->street, e.a_ptr->town, e.a_ptr->postcode,
         e.salary);
}
