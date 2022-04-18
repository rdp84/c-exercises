
// Code originally given in exerise fails to compile since there is
// an undefined reference to main

// including here means there is now a possibility of reaching main
#include "a_b_c.h"

#if TRUE
//    #include "a_b_c.h"
    #include <stdio.h>
    A_B_C
#endif
