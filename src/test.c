#include "malloc.h"
#include <stdio.h>
int main()
{
    char *tab;
    int size = 60;
    int i = 0;

    //tab = (char*) ft_malloc(4096);
    // tab = (char*) ft_malloc(4096);
tab = (char*) ft_malloc(0);
my_free(tab);
my_free(tab);


    // i = 0;
    // while(i < size)
    // {
    //     tab[i] = 'c';
    //     i++;
    // }
    // tab[size+1] = '\0';
    // show_alloc_mem();
    // printf("%s\n",tab);
    // my_free(tab);
    // show_alloc_mem();
    

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

  int k = 0;
//  tab = (char*) ft_malloc(1);
 //tab = (char*) ft_malloc(4096 + 1);

  // show_alloc_mem();
    while (k < 90000 )
    {
        // printf("%d\n",k);
        size = k; // 4095 segfault
        tab = (char*) ft_malloc(size+1);
        // printf("%p tab\n",tab);


        // if(k % 2 == 0)
        // {
            my_free(tab);
        // }
        k = k + 1;

    }
    my_free(tab);
    printf("______________________________SMALLLL OK____________\n");
//  show_alloc_mem();
 k = 0;
    while (k < 0)
    {
        printf("%d\n",k);
        size = k; // 4095 segfault
        tab = (char*) ft_malloc(size);
        // printf("%p tab\n",tab);

        // i = 0;
        // while(i < 10)
        // {
        //      tab[i] = 'c';
        //      i++;
        // //     // printf("%d\n",i);
        // }
        // tab[11] = '\0';
        // // printf("%s\n",tab);
        // show_alloc_mem();

        // printf("%d\n",k);
        // printf("%s\n",tab);
        // if(size < 4095 * 40)
        // {
            //  printf("tab p =%p\n",tab);

            // size_t lst_count(t_zone *lst)
            my_free(tab);
            // tab = NULL;

        // }
        // else{
        //     printf("????????????????????????????????????????????????????????????????");
        //     return 1;
        // }
        // printf("tab p =%p\n",tab);
        // show_alloc_mem();
        k = k + 1;


    }
    show_alloc_mem();
   // show_alloc_mem();
    // char *tab;
    // printf("p tab_init = %p\n",tab);
    // tab =  (char*) ft_malloc(8);
    // printf("p tab_alloc = %p\n",tab);

    // tab[0] = 's';
    // tab[1] = 'a';

    // printf("p tab = %p\n",tab);
    // printf("%s\n",tab);
    // show_alloc_mem();
    // my_free(tab);
    // printf("%s\n",tab);
    // show_alloc_mem();

    // tab =  (char*) ft_malloc(8);
    // show_alloc_mem();
    

    return (0);
}