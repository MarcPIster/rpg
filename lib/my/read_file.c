/*
** EPITECH PROJECT, 2021
** read_file.c
** File description:
** .
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int my_putstr(char *filepath);

// Input : Filepath of file to be read
// Description : Reads file into malloced string
// Output : File content // MUST BE FREED
// Error : Returns NULL
char *read_file_rpg(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;
    my_putstr(filepath);

    stat(filepath, &sb);
    my_putstr("test1");
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    my_putstr("test2");
    memset(buffer, 0, sizeof(char) * (sb.st_size + 1));
    my_putstr("test3");
    if (fd < 0)
        return NULL;
    read(fd, buffer, sb.st_size);
    close(fd);
    my_putstr("return buffer\n");
    return buffer;
}