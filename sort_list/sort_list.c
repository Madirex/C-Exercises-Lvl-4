#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int)) {
    int swapped;
    t_list *current;
    t_list *last = NULL;

    if (!lst || !lst->next)
        return lst;

    do {
        swapped = 0;
        current = lst;

        while (current->next != last) {
            if (!(*cmp)(current->data, current->next->data)) {
                int tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);

    return (lst);
}
