#include "malloc.h"
#include <stdio.h>
int main()
{
    char *tab;
    int size = 60;
    tab = (char*) ft_malloc(size + 1);

    int i = 0;
    while(i < size)
    {
        tab[i] = 'c';
        i++;
    }
    tab[size+1] = '\0';
    printf("%s\n",tab);

    // free(tab);
    tab = (char*) ft_malloc(size + 1);
    size = 2000;
    i = 0;
    while(i < size)
    {
        tab[i] = 'c';
        i++;
    }
    tab[size+1] = '\0';
    printf("%s\n",tab);
    return (0);
}