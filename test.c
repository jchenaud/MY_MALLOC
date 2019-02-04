#include "malloc.h"
#include <stdio.h>
int main()
{
    char *tab;
    int size = 60;
    int i = 0;

    tab = (char*) ft_malloc(size + 1);

    i = 0;
    while(i < size)
    {
        tab[i] = 'c';
        i++;
    }
    tab[size+1] = '\0';
    printf("%s\n",tab);

    // tab = (char*) malloc(size + 1);
    // size = 4095; // 4095 segfault
    // i = 0;
    // while(i < size)
    // {
    //     tab[i] = 'c';
    //     i++;
    //     // printf("%d\n",i);
    // }
    // tab[size+1] = '\0';
    // printf("%s\n",tab);


    size = 4096; // 4095 segfault
    tab = (char*) ft_malloc(size + 1);

    i = 0;
    while(i < size)
    {
        tab[i] = 'c';
        i++;
        // printf("%d\n",i);
    }
    tab[size+1] = '\0';
    printf("%s\n",tab);
    return (0);
}