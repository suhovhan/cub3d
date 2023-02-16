#include "cub3d.h"

int check_extension(char *s1, char *s2, size_t n)
{
    int len;
    int i;

    if (!s1 || !s2 || n <= 0)
        return (-1);
    len = (int)ft_strlen((const char *)s1);
    i = 0;
    while (s1[len - n + i] && s2[i])
    {
        if (s1[len - n + i] == s2[i])
            i++;
        else
            return (-1);
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Invalid count of arguments!\n");
        return (-1);
    }
    if (check_extension(av[1], ".cub", 4) != 0)
    {
        printf("Invalid path extension!\n");
        return (-1);
    }
    return (0);
}