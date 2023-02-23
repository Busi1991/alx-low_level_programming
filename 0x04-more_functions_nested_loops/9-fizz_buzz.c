#include <stdio.h>
/**
* main - prints 0-100 and prints fizz if n is a multiple
* of 3 and buzz if multiple of five and fizzbuzz
* if multiple of 3 and 5
*Return:0
*/

int main(void)
{
int i;
for (i = 1; i <= 100; i++)
{
if (i % 3 == 0 && i % 5 != 0)
printf(" Fizz");
else if (i % 5 == 0 && i % 3 != 0)
printf(" Buzz");
else if (i % 3 == 0 && i % 5 == 0)
printf(" FizzBuzz");
else if (i == 1)
printf("%d", i);
else
printf(" %d", i);
}
printf("\n");
return (0);
}
