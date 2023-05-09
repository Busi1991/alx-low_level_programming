#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
* error_exit - Print an error message and exit with the given exit code
* @exit_code: The exit code to be used
* @message: The error message to be printed
*/
void error_exit(int exit_code, char *message)
{
dprintf(STDERR_FILENO, "%s\n", message);
exit(exit_code);
}

/**
* main - Entry point of the program
* @argc: The number of command-line arguments
* @argv: An array containing the command-line arguments
* Return: 0 on success, or the corresponding exit code on failure
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_count, write_count;
char buffer[BUF_SIZE];
char *file_from, *file_to;
/* Check the number of arguments */
if (argc != 3)
error_exit(97, "Usage: cp file_from file_to");
file_from = argv[1];
file_to = argv[2];
/* Open the source file */
fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file");
/* Open the destination file */
fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to file");
/* Copy the content from source file to destination file */
while ((read_count = read(fd_from, buffer, BUF_SIZE)) > 0)
{
write_count = write(fd_to, buffer, read_count);
if (write_count == -1)
error_exit(99, "Error: Can't write to file");
}
/* Error handling for read and write operations */
if (read_count == -1)
error_exit(98, "Error: Can't read from file");
/* Close the file descriptors */
if (close(fd_from) == -1)
error_exit(100, "Error: Can't close file descriptor");
if (close(fd_to) == -1)
error_exit(100, "Error: Can't close file descriptor");
return (0);
}

