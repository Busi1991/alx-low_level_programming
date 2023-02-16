#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 main - main function prints to stderr
 Return: 1 always
 */
int main(void)
{
    int x;

    x = strlen("and that piece of art is useful\" - Dora Korpar, 2015-10-19\n");

    write(2,
        "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
        x);
    return (1);
}
