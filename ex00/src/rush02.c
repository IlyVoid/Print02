#include "Rush02.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char    *find_number(int fd)
{
    int     i;
    char    c[1];
    char    *str;

    str = (char *)malloc(sizeof(char) * 128);
    if (!str)
        exit(1);
    i = 0;
    read(fd, c, 1);
    while (c[0] == '\n')
        read(fd, c, 1);
    while (c[0] >= '0' && c[0] <= '9')
    {
        str[i] = c[0];
        read(fd, c, 1);
        i++;
    }
    return (str);
}

char    *find_value(int fd, char *c)
{
    int     i;
    char    *str;

    str = (char *)malloc(sizeof(char) * 128);
    if (!str)
        exit(1);

    i = 0;
    while (c[0] != '\n')
    {
        str[i] = c[0];
        read(fd, c, 1);
        i++;
    }
    return (str);
}

t_list  *operate(char *file)
{
    int     i;
    int     fd;
    char    c[1];
    char    *temp;
    t_list  *tab;

    fd = open(file, O_RDONLY);
    tab = malloc(sizeof(t_list) * 33);
    if (fd == -1 || !tab)
        exit(1);
    i = 0;
    while (i < 32)
    {
        tab[i].n = atoi_number(find_number(fd));
        read(fd, c, 1);
        while (c[0] == ' ')
            read(fd, c, 1);
        if (c[0] == ':')
            read(fd, c, 1);
        while (c[0] == ' ')
            read(fd, c, 1);
        temp = find_value(fd, c);
        tab[i].value = str_dup(temp);
        free(temp);
        i++;
    }
    close(fd);
    return (tab);
}
