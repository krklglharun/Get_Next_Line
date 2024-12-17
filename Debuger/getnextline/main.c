#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Dosya açılamadı\n");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("!!!!!MAİN ÇIKTISI=%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
