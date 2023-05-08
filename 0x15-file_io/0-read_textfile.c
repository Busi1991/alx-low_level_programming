#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
    if (filename == NULL)
        return 0;

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return 0;

    char *buffer = (char *)malloc((letters + 1) * sizeof(char));
    if (buffer == NULL)
    {
        close(fd);
        return 0;
    }

    ssize_t bytesRead = read(fd, buffer, letters);
    if (bytesRead == -1)
    {
        free(buffer);
        close(fd);
        return 0;
    }

    buffer[bytesRead] = '\0';  /* Add null terminator at the end of the read text */

    ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
    if (bytesWritten == -1 || bytesWritten != bytesRead)
    {
        free(buffer);
        close(fd);
        return 0;
    }

    free(buffer);
    close(fd);

    return bytesRead;
}
