#include "Rush02.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *str_dup(char *src)
{
    int     len;
    int     i;
    char    *dup_str;

    len = 0;
    while (src[len] != '\0')
        len++;
    //dup_str = (char *)malloc((len + 1) * sizeof(char));
    if (!(dup_str = (char *)malloc(sizeof(char) * (len + 1))))
    {
        write(1, "Error\n", 6);
        return (0);
    }
    i = 0;
    while (i < len)
    {
        dup_str[i] = src[i];
        i++;
    }
    dup_str[i] = '\0';
    return(dup_str);
}

int atoi_number(const char *str)
{
    int             i;
    int             negative;
    long long int   result;

    i = 0;
    negative = 1;
    result = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' 
                || str[i] == '\f' || str[i] == '\r'))
        i++;
    if (str[i] == '-')
        negative = -1;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - 48);
        i++;
    }
    return (result * negative);
}

void    put_str(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}
