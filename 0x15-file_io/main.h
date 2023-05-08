#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/* Function prototypes */

/* Read 'letters' number of characters from a text file 'filename'
   and print them to standard output. Return the number of characters read. */
ssize_t read_textfile(const char *filename, size_t letters);

/* Create a new file with the given 'filename' and write 'text_content' to it.
   If the file already exists, truncate it and overwrite the content.
   Return 1 on success, or -1 on failure. */
int create_file(const char *filename, char *text_content);

/* Append 'text_content' to an existing file with the given 'filename'.
   If the file does not exist, create it.
   Return 1 on success, or -1 on failure. */
int append_text_to_file(const char *filename, char *text_content);

/* Copy the contents of 'file_from' to 'file_to'.
   Return 1 on success, or -1 on failure. */
int cp(const char *file_from, const char *file_to);

/* Extract the ELF header information from the file 'elf_filename'
   and print it to standard output. */
void elf_header(const char *elf_filename);

/* Print a single character to standard output. */
int _putchar(char c);

#endif /* MAIN_H */
