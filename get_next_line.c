/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char *my_mem_memory(char *ptr, int size, int *begin, char *buffer)
{
	char *str;
	int len = 0;

	if (ptr != 0)
		for (; ptr[len] != '\0'; len++);
	str = malloc(sizeof(char) * (len + size + 1));
	if (str == NULL)
		return (NULL);
	get_buffer(str, ptr, size, len);
	insert_line(str + len, buffer + *begin, size);
	if (ptr == 0)
		free(ptr);
	(*begin) += size + 1;
	return (str);
}

void get_buffer(char *dest, char *buffer, int size, int len)
{
	if (buffer != 0)
		for (int i = 0; buffer[i] != '\0' && i < len; i++)
			dest[i] = buffer[i];
	dest[len + size] = '\0';
}

void insert_line(char *dest, char *buffer, int size)
{
	int i;

	for (i = 0; buffer[i] != '\0' && i < size; i++)
		dest[i] = buffer[i];
}

char *get_next_line2(int fd)
{
	char *array = NULL;
	int size = 0;
	static int count = 0;
	static int begin = 0;
	static char buffer[(READ_SIZE < 0 ? 0 : READ_SIZE) + 1] = {0};

	for (; count != -1; size++) {
		if (count <= begin) {
			begin = 0;
			size = 0;
			if (!(count = read(fd, buffer, READ_SIZE)))
				return (array);
		} if (buffer[begin + size] == '\n') {
			array = my_mem_memory(array, size, &begin, buffer);
			return (array);
		} if (begin + size == count - 1)
			array = my_mem_memory(array, size + 1, &begin, buffer);
	}
	return (NULL);
}

char *get_next_line(int fd)
{
	return (READ_SIZE > 0 && fd >= 0 ? get_next_line2(fd) : NULL);
}
