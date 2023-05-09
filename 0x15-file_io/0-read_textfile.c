#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
* read_textfile - Reads a text file and prints it to the POSIX standard output.
* @filename: The name of the file to read.
* @letters: The number of letters to read and printsss
* Return: The actual number of letters read and printed.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t bytesRead, bytesWritten;
char *buffer;
if (filename == NULL)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buffer = malloc((letters + 1) * sizeof(char));
if (buffer == NULL)
{
close(fd);
return (0);
}
bytesRead = read(fd, buffer, letters);
if (bytesRead == -1)
{
free(buffer);
close(fd);
return (0);
}
buffer[bytesRead] = '\0'; /* Add null terminator at the end of the read text */
bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
if (bytesWritten == -1 || bytesWritten != bytesRead)
{
free(buffer);
close(fd);
return (0);
}
free(buffer);
close(fd);
return (bytesRead);
}
