
void my_test_1()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*3);
    str[0] = 's';
    str[1] = 'a';
    str[2] = '\0';

    printf("%s",str);
}

void my_test_2()
{

    char *str;
    str  =  (char *)malloc(sizeof(char)*30);
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

int main(){

    my_test_1();
    printf("__________________TEST1____PASS");
    my_test1_multy(103);
    printf("__________________TEST1_MULTY____PASS");
    my_test_2();
    printf("__________________TEST2_____PASS");
    my_test2_multy(203);
    printf("__________________TEST2_MULTY____PASS");






//printf("coucou\n");

}