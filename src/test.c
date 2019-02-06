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


    // int k = 0;
    // while (k < 10000)
    // {
    //     size = 200 + k*100; // 4095 segfault
    //     tab = (char*) ft_malloc(size + 1);

    //     i = 0;
    //     while(i < size)
    //     {
    //         tab[i] = 'c';
    //         i++;
    //         // printf("%d\n",i);
    //     }
    //     tab[size+1] = '\0';
    //     // printf("%s\n",tab);
    //     k++;
    //     // printf("%d\n",k);
    //     show_alloc_mem();

    // }
    // show_alloc_mem();

 int k = 1;
    while (k < 10000000)
    {
        size = k; // 4095 segfault
        tab = (char*) ft_malloc(size + 1);

        i = 0;
        while(i < size)
        {
             tab[i] = 'c';
             i++;
        //     // printf("%d\n",i);
        }
        tab[size] = '\0';
        // printf("%s\n",tab);
        k = k + 5000;
        printf("%d\n",k);
        // show_alloc_mem();

    }
    show_alloc_mem();
    return (0);
}