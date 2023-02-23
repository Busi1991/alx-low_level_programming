#include "main.h"

/**
*print_triangle - print a triangle with  character
*@size: size of the triangle that will be printed
*Return:void
*/

void print_triangle(int size)
{
int i, k, n;

if (size > 0)
{
for (n = 1; n <= size; n++)
{
for (i = n; i < size; i++)
_putchar(' ');
for (k = 0; k < n; k++)
{
_putchar('#');
}
_putchar('\n');
}
}
else
_putchar('\n');
}
