#include "../../include/my_rpg.h"

void output_error(char *message)
{
    int message_len = my_strlen(message);

    write(2, message, message_len);
}

char *read_file(char *filepath)
{
    my_putstr(filepath);
    int fd = open(filepath, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;

    stat(filepath, &sb);
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    memset(buffer, 0, sizeof(char) * (sb.st_size + 1));
    if (fd < 0) {
        output_error("File opening failed.\n");
        return NULL;
    }
    read(fd, buffer, sb.st_size);
    close(fd);
    return buffer;
}