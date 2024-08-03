void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;

    while(i < size - 1)
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i + 1];
            tab[i + 1] = tab[i];
            tab[i] = temp;
            i = 0;
        }
        else
            i++;
    }
}