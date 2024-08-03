#include <stdlib.h>

char    *ft_strncpy(char *out, char *cp, int n)
{
    int i = 0;
    while(cp[i] && i < n)
    {
        out[i] = cp[i];
        i++;
    }
    out[i] = '\0';
    return (out);
}

int is_sep_char(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

char    **ft_split(char *str)
{
    int wc = 0;
    int i = 0;
    
    while(str[i])
    {
        while(str[i] && is_sep_char(str[i]))
            i++;
        if(str[i])
            wc++;
        while(str[i] && !is_sep_char(str[i]))
            i++;
    }
    char **res = malloc((wc + 1) * sizeof(char *));
    if (!res)
        return (NULL);
    res[wc] = NULL;
    i = 0;
    int count = 0;
    int start = 0;
    while(count < wc)
    {
        while(str[i] && is_sep_char(str[i]))
            i++;
        if(str[i])
            start = i;
        while(str[i] && !is_sep_char(str[i]))
            i++;

        if (i > start)
        {
            res[count] = malloc((i - start + 1) * sizeof(char));
            if (!res[count])
                return (NULL);
            ft_strncpy(res[count], &str[start], i - start);
        }

        count++;
    }
    return (res);
}