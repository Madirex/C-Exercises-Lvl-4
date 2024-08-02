#include <unistd.h>

int is_separator_char(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

void    print_str(char *str, int start, int end)
{
    while(start <= end)
    {
        write(1, &str[start], 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int end = 0;
        int start = 0;
        while(argv[1][end])
            end++;
        end--;
        while(end >= 0)
        {
            start = end;
            while(argv[1][start] && !is_separator_char(argv[1][start]))
                start--;
            print_str(argv[1], start + 1, end);

            end = start - 1;

            if (end > 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}