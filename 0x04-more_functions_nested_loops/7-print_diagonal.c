#include "main.h"

/**
*print_diagonal - prints a diagonal with
*@n : number of times a slash is printed
*Return:void
*/

void print_diagonal(int n)
{
int i, k;
if (n > 0)
{
for (i = 0; i < n; i++)
{
for (k = 0; k < i; k++)
{
_putchar(' ');
}
_putchar('\\');
_putchar('\n');
}
}
else
_putchar('\n');
}
