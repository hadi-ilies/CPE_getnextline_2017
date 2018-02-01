/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#pragma once
#ifndef READ_SIZE
#define READ_SIZE 4
#endif

char *get_next_line(int fd);
char *get_next_line2(int fd);
void get_buffer(char *dest, char *buffer, int size, int len);
void insert_line(char *dest, char *buffer, int size);
char *my_mem_memory(char *ptr, int size, int *begin, char *buffer);
