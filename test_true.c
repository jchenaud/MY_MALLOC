#include "malloc.h"
//  #include <libft_malloc.so>
// #include <stdlib>
#include <stdio.h>

int main(){
        printf("coucou\n");

    char** tab = (char**) malloc(sizeof(char*) * 1025) ;
    int i = 0;
    while (i < 1024)
    {
         printf("%d\n",i);

         tab[i] = (char*) malloc(sizeof(char)*10);
         i++;
    }
    tab[i] = NULL;
    // tab = (char*) malloc(100);
    // return (0);
    i = 0;
    while(tab[i])
    {
        printf("%d\n",i);
        i++;
    }
     return (0);
}

    // test 1
//     printf("coucou\n");
//     char **spam;
//        spam =  (char**) malloc((sizeof(char*)*(1024+1)));
//     printf("coucou\n");
// spam[1024] =NULL;
//     char* addr;
//     int i = 0;
//     while (i < 1024)
//     {
//         printf("i = %d\n",i);

//        addr =  (char*) malloc(i);
//        addr[0] = 42;
//        addr[1] = i %42 +22;
//     //    addr[3] ='\0';

//         // printf("%s\n",addr);

//         spam[i] = addr;

//         i += 1;
//         // if (spam[i])
//     }
//     printf("%c\n",addr[0]);
//     int k = 0;
//     while(k < 100)
//     {
//         printf("spam [%d] = %s\n",k,spam[k]);
//         spam[k] = "Yolo";
//         printf("spam [%d] = %s\n",k,spam[k]);
//         k++;
//     }
//     free(addr);
//     printf("TEST1 PASS\n");

//     return (0);

    // test02
    //  printf("TEST1 PASS\n");
    
    // char* addr2;
    // addr2 =  (char*) malloc(1024);
    // int j = 0;
    // while (j < 1024)
    // {
    //    addr2 =  (char*) realloc(addr2,j);
    //    addr2[0] = 42;
    //    j++;
    //     printf("adr = %p\n",addr2);
    // }
    // return (0);
//}


// int main()
// {
//     char *tab;
//     int size = 60;
//     int i = 0;

//     //tab = (char*) ft_malloc(4096);
//     // tab = (char*) ft_malloc(4096);
// tab = (char*) malloc(0);
// // free(tab);
// free(tab);


//     // i = 0;
//     // while(i < size)
//     // {
//     //     tab[i] = 'c';
//     //     i++;
//     // }
//     // tab[size+1] = '\0';
//     // show_alloc_mem();
//     // // printf("%s\n",tab);
//     // my_free(tab);
//     // show_alloc_mem();
    

//     // int k = 0;
//     // while (k < 10000)
//     // {
//     //     size = 200 + k*100; // 4095 segfault
//     //     tab = (char*) ft_malloc(size + 1);

//     //     i = 0;
//     //     while(i < size)
//     //     {
//     //         tab[i] = 'c';
//     //         i++;
//     //         // // printf("%d\n",i);
//     //     }
//     //     tab[size+1] = '\0';
//     //     // // printf("%s\n",tab);
//     //     k++;
//     //     // // printf("%d\n",k);
//     //     show_alloc_mem();

//     // }
//     // show_alloc_mem();

//   int k = 0;
// //  tab = (char*) ft_malloc(1);
//  //tab = (char*) ft_malloc(4096 + 1);

//   // show_alloc_mem();
//     while (k < 90000 )
//     {
//         // // printf("%d\n",k);
//         size = k; // 4095 segfault
//         tab = (char*) malloc(size+1);
//         // // printf("%p tab\n",tab);


//         // if(k % 2 == 0)
//         // {
//             free(tab);
//         // }
//         k = k + 1;

//     }
//     // free(tab);
//     // printf("______________________________SMALLLL OK____________\n");
// //  show_alloc_mem();
//  k = 0;
//     while (k < 0)
//     {
//         // printf("%d\n",k);
//         size = k; // 4095 segfault
//         tab = (char*) malloc(size);
//         // // printf("%p tab\n",tab);

//         // i = 0;
//         // while(i < 10)
//         // {
//         //      tab[i] = 'c';
//         //      i++;
//         // //     // // printf("%d\n",i);
//         // }
//         // tab[11] = '\0';
//         // // // printf("%s\n",tab);
//         // show_alloc_mem();

//         // // printf("%d\n",k);
//         // // printf("%s\n",tab);
//         // if(size < 4095 * 40)
//         // {
//             //  // printf("tab p =%p\n",tab);

//             // size_t lst_count(t_zone *lst)
//             free(tab);
//             // tab = NULL;

//         // }
//         // else{
//         //     // printf("????????????????????????????????????????????????????????????????");
//         //     return 1;
//         // }
//         // // printf("tab p =%p\n",tab);
//         // show_alloc_mem();
//         k = k + 1;


//     }
//     // show_alloc_mem();
//    // show_alloc_mem();
//     // char *tab;
//     // // printf("p tab_init = %p\n",tab);
//     // tab =  (char*) ft_malloc(8);
//     // // printf("p tab_alloc = %p\n",tab);

//     // tab[0] = 's';
//     // tab[1] = 'a';

//     // // printf("p tab = %p\n",tab);
//     // // printf("%s\n",tab);
//     // show_alloc_mem();
//     // my_free(tab);
//     // // printf("%s\n",tab);
//     // show_alloc_mem();

//     // tab =  (char*) ft_malloc(8);
//     // show_alloc_mem();
    

//     return (0);
// }