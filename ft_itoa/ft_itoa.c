#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int len = 0;
    int sign = 0;

    if (nbr == -2147483648)
        return ("-2147483648\0");
    if (nbr == 0)
        len++;
    if (nbr < 0)
    {
        sign = 1;
        nbr *= -1;
        len++;
    }
    int n = nbr;
    while(n)
    {
        n /= 10;
        len++;
    }
    char *res = malloc((len + 1) * sizeof(char));
    if (!res)
        return (NULL);
    int i = 0;
    res[len] = '\0';
    if (sign)
    {
        res[i] = '-';
        i++;
    }
    if (nbr == 0)
        res[0] = 0 + '0';
    while(nbr)
    {
        len--;
        res[len] = (nbr % 10) + '0';
        nbr /= 10;
    }
    return (res);
}