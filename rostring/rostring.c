#include <unistd.h>

int is_separation_char(char c)
{
    return c == ' ' || (c >= 9 && c <= 13);
}

void print_first_word(char *str)
{
    int i = 0;
    while (str[i] && is_separation_char(str[i]))
        i++;
    while (str[i] && !is_separation_char(str[i]))
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_printf_at(char *str, int i)
{
    int next_word = 0;
    
    while (str[i] && is_separation_char(str[i]))
        i++;
    while (str[i])
    {
        if (!is_separation_char(str[i]))
        {
            if (next_word)
            {
                write(1, &str[i - 1], 1);
                next_word = 0;
            }
            write(1, &str[i], 1);
        }
        else
            next_word = 1;
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
    {
        int i = 0;
        int first_word = 0;
        while (argv[1][i] && is_separation_char(argv[1][i]))
            i++;
        while (argv[1][i] && !is_separation_char(argv[1][i]))
        {
            first_word = 1;
            i++;
        }
        while (argv[1][i] && is_separation_char(argv[1][i]))
            i++;
        if (argv[1][i] && first_word)
        {
            ft_printf_at(argv[1], i);
            write(1, " ", 1);
            print_first_word(argv[1]);
        }
        else
            print_first_word(argv[1]);
    }
    write(1, "\n", 1);
    return (0);
}
