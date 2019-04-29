#include <stddef.h>
#include <stdio.h>
// #include <stdlib.h>

#include "malloc.h"
#define TINY  50
#define SMALL 1024
#define FAT 8096

#define FREE 1

void my_test_1()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*TINY);
    str[0] = 't';
    str[1] = 'y';
    str[2] = '\0';

    if(FREE == 1)
        free(str);
}

void my_test_2()
{
    size_t i = 0;

    char *str;
    str  =  (char *)malloc(sizeof(char)*SMALL);
    while(i < SMALL -1)
    {
        str[i] = 'S';
        i++;
    }
    if(FREE == 1)
        free(str);
}

void my_test2_multy(int nb)
{
    while(nb > 0){
       my_test_2();
       nb--;
    }

}

void my_test1_multy(int nb)
{
    while(nb > 0){
       my_test_1();
       nb--;
    }

}

void my_multy_test(void *p,int nb)
{
    while(nb > 0){
       void(*p)();
       nb--;
    }

}



void my_fat_test()
{
    size_t i = 0;
    char *str;
    str  =  (char *)malloc(sizeof(char)*FAT);
    while(i < FAT-1)
    {
        str[i] = 'F';
        i++;
    }
    if(FREE == 1)
        free(str);
}

void my_multy_Fat(int nb)
{
    while(nb > 0){
       my_fat_test();
       nb--;
    }

}

void my_realoc_test()
{
    char *ad1;
    char *ad2;

    ad1 = malloc(0);
    ad2 = realloc((void*)ad1,sizeof(char));
    free(ad1);
    free(ad2);
    ad1 = malloc(sizeof(char));
    size_t i = 1;
    size_t k = 0;
    while (i < FAT * 1.5)
    {
        ad2 =  (char *) realloc((void*)ad2,sizeof(char) * i);
         while(k != 0)
         {
             ad2[k] = 'R';
             k--;
        }
        ad2[0] = 'F';
         i++;
    }
    ad2 = realloc(ad2,0);
}

void fullysize_test()
{
     char *ad1;
    char *ad2;

    ad1 = malloc(0);

    ad1 = malloc(sizeof(char));

    size_t i = 2;
    size_t k = 0;

    while (i < FAT +1)
    {
        k = i - 1;
        ad1 =  malloc(sizeof(char) * i);
        ad1[k] = '\0';
        k--;
         while(k != 0)
         {
             ad1[k] = 'c';
             k--;
        }
        ad1[0] = 'c';
         i++;
    }
    free(ad1);
}

int main(){


    void *overFlow;
    overFlow = malloc(1024*1024*1024*1024);
    my_test_1();
    printf("\n__________________TEST1____PASS\n");
    my_test1_multy(10000);
    printf("\n__________________TEST1_MULTY____PASS\n");
    my_test_2();
    printf("\n__________________TEST2_____PASS\n");
    my_test2_multy(10000);
    printf("\n__________________TEST2_MULTY____PASS\n");
    my_fat_test();
    printf("\n__________________FAT_____PASS\n");
    my_multy_Fat(4000);
    printf("\n__________________FAT_Multy___PASS\n");
    my_realoc_test();
    fullysize_test();
    show_alloc_mem();
    show_alloc_mem_content();




//printf("coucou\n");

}