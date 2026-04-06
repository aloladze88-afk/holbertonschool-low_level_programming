#include "main.h"

/**
 * open_file_from - opens the source file for reading
 * @filename: source file name
 *
 * Return: file descriptor
 */
int open_file_from(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * open_file_to - opens/creates the destination file
 * @filename: destination file name
 *
 * Return: file descriptor
 */
int open_file_to(char *filename)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[1024];
	ssize_t letters_read, letters_written;

	letters_read = read(fd_from, buffer, 1024);
	while (letters_read > 0)
	{
		letters_written = write(fd_to, buffer, letters_read);
		if (letters_written != letters_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}

		letters_read = read(fd_from, buffer, 1024);
	}

	if (letters_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies one file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
