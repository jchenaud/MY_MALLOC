#include <stddef.h>
#include <stdio.h>
// #include <stdlib.h>

#define TINY  50
#define SMALL 1024
#define FAT 8096

#define FREE 0

void my_test_1()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*TINY);
    str[0] = 't';
    str[1] = 'y';
    str[2] = '\0';

    printf("%s",str);
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
    // str[0] = 's';
    // str[1] = 'a';
    // str[2] = '\0';

    printf("%s",str);
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
       // printf("Caall\n");

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
    // str[1] = 'a';
    // str[2] = '\0';
    // printf("%s",str);
    
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
    void *ad1;
    void *ad2;

    ad1 = malloc(0);
    ad2 = realloc(ad1,1);

    free(ad1);
    free(ad2);

    ad1 = malloc(1);

    size_t i = 1;

    while (i < FAT * 1.5)
    {
        ad2 =  realloc(ad2,i);
        i++;
    }
    ad2 = realloc(ad2,0);
}

int main(){

    void *prout;
    prout = malloc(1024*1024*1024);
    my_test_1();
    printf("\n__________________TEST1____PASS\n");
    my_test1_multy(103);
    printf("\n__________________TEST1_MULTY____PASS\n");
    my_test_2();
    printf("\n__________________TEST2_____PASS\n");
    my_test2_multy(203);
    printf("\n__________________TEST2_MULTY____PASS\n");
    my_fat_test();
    printf("\n__________________FAT_____PASS\n");
  //  my_multy_test((*my_fat_test),110);
    my_multy_Fat(44110);
    printf("\n__________________FAT_Multy___PASS\n");

    // printf(sizeof(t_zone));
    my_realoc_test();

    show_alloc_mem();
    //show_alloc_mem_content();
    //prin




//printf("coucou\n");

}