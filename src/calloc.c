// #include "malloc.h"

// void *calloc_l(size_t n,size_t size)
// {
//     void *r;
//     if(n == 0 || size == 0)
//         n = size = 1;
//     r = malloc_l(n * size);
//     // if(r)
//     //     ft_bzero(r,n * size);
    
//     return (r);
// }

// void *calloc(size_t n,size_t size)
// {
//     printf("calloc ,%zu , %zu\n",n,size);
//     void *r;

//     lock();
//     r = calloc_l(n,size);
//     // printf("%p\n",r);

//     unlock();
//     // printf("%p\n",r);
//     return (r);
// } 