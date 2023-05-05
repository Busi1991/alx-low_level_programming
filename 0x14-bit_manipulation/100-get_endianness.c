#include "main.h"

/**
 * get_endianness - check system endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
uint16_t num = 0x1234;
uint8_t *ptr = (uint8_t *)&num;
return (*ptr == 0x34);
}
