
#include "flower_fruit_or_vegetable.h"

int main(void)
{
  flower rose  = {"rose", red};
  fruit  apple = {"apple", 232};
  flower_fruit_or_vegtable ffv;

  ffv.flw = rose;
  ffv.frt = apple;

  /*
    This will print apple; ffv is a union so members share storage and therefore
    there is only one piece of memory to store the char * of the 3 members.
    This means any earlier assigment into the char * will be overriden by later
    assignments
   */
  printf("ffv name: %s\n", ffv.flw.name);


  /*
    This will print 232. There is only one piece of memory to store the int
    used by fruit and vegetable.
    Even though a vegetable has not be defined, the definition of the apple
    has written its valiue to this piece of memory.
   */
  printf("ffv calories: %d\n", ffv.veg.calories);
}
