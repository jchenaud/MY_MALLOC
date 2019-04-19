// #include <stdio.h>
//#include <libft_malloc.so>

int main(){
        printf("coucou\n");

     char* tab;
    int i = 0;
    while (i < 1024)
    {
        tab = (char*) malloc(1024);
        i++;
        tab[0] = 42;
        free(tab);
    }
    // tab = (char*) malloc(100);
    return (0);
}