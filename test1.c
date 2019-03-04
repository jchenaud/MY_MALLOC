// #include <stdio.h>
//#include <libft_malloc.so>

int main(){
    char* addr;
    int i = 0;
    while (i < 1024)
    {
       addr =  (char*) malloc(1024);
       addr[0] = 42;
         i++;
        // printf("coucou\n");
    }
    // tab = (char*) malloc(100);
    return (0);
}