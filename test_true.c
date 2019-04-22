
#define TINY  7
#define SMALL 50
#define FAT 1024


void my_test_1()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*TINY);
    str[0] = 's';
    str[1] = 'a';
    str[2] = '\0';

    printf("%s",str);
}

void my_test_2()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*SMALL);
    str[0] = 's';
    str[1] = 'a';
    str[2] = '\0';

    printf("%s",str);
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


    char *str;
    str  =  (char *)malloc(sizeof(char)*FAT);
    str[0] = 'F';
    str[1] = 'a';
    str[2] = '\0';
    printf("%s",str);
    
}

void my_multy_Fat(int nb)
{
    while(nb > 0){
       my_fat_test();
       nb--;
    }

}

int main(){

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
    my_multy_Fat(110);
    printf("\n__________________FAT_Multy___PASS\n");


    show_alloc_mem();
    //prin




//printf("coucou\n");

}