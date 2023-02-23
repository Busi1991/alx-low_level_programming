#include "main.h"

/**
*print_square - prints a square with #
*@size: the size of the square
*Return:void
*/

void print_square(int size)
{
int k, i;
if (size > 0)
{
for (i = 0; i < size; i++)
{
for (k = 0; k < size; k++)
{
_putchar('#');
}
_putchar('\n');
}
}
else
_putchar('\n');
}
