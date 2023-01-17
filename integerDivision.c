#include <stdio.h>
#include <stdlib.h>

//write a function to perform integer division without using either the "/" or " * " operator. find a fast way to do it.

void divide(int* dividend, int* divisor, int* quotient, int* remainder);

int main(void)
{
       int dividend = 10, divisor = 3, quotient, remainder;
       
       divide(&dividend, &divisor, &quotient, &remainder);
       
       printf("The Answer is %d\n", quotient);

       return 0;
}

void divide(int* dividend, int* divisor, int* quotient, int* remainder)
{
       *quotient = 0;
       *remainder = 0;
       int sign = 1;
  
       if(*divisor == 0)
       {
            *quotient = -1;
            *remainder = 0;
            return;
       }
  
       if(*dividend < 0)
       {
            sign = -sign;
            *dividend = -(*dividend);
       }

       if(*divisor < 0)
       {
            sign = -sign;
            *divisor = -(*divisor);
       }
       
       *remainder = *dividend;
       while(*remainder >= *divisor)
       {
            *remainder -= *divisor;
            (*quotient)++;
       }
       quotient *= sign;
}
