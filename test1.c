// #include <stdio.h>
//#include <libft_malloc.so>

int main(){
        printf("coucou\n");

     char* tab;
    int i = 0;
    while (i < 1024)
    {
        tab = (char*) malloc(5);
        i++;
        tab[0] = 42;
    }
    // tab = (char*) malloc(100);
    return (0);
}