#ifndef MAIN_H
#define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int open_file_from(char *filename);
int open_file_to(char *filename);
void close_file(int fd);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);

#endif
