// #include "malloc.h"


// void *realloc(void *ptr, size_t size)
// {
//     ft_putendl("_________________________________Realloc_call______________\n");
// // printf("ptr avant = %p\n",ptr);
//     //   if(ptr == NULL)
//     //     return NULL; 
//     // printf("ptr = %p\n",ptr);

//     t_zone *tmp;
//     t_zone *first;
//     int page_size;
//     page_size = ((t_env *)glob)->page_size;
//     // ft_putendl("_________________________________Realloc_call______________\n");


//     void	*ret;

// 	if (ptr == NULL)
//     {
//         // ft_putendl("_________________________________Realloc_NULL______________\n");

// 		return (malloc(size));
//     }
//     // ft_putendl("_________________________________Realloc_call______________\n");

// 	if (size == 0)
// 		return (ptr);
//     // ft_putendl("_________________________________Realloc_call______________\n");

//     first = ((t_env *)glob)->tiny;
//     tmp  = find_in_zone(ptr,first);
//     if( (tmp != NULL) && (size > page_size * TINY_MULTY_PAGESIZE) && (
//         size < page_size * SMALL_MULTY_PAGESIZE)) // si dans la zone et size tj inf a la limite
// 	        ret = malloc(sizeof(ptr) * (ft_strlen((char*)ptr) + size));
//     else if((tmp != NULL) && (size < page_size * TINY_MULTY_PAGESIZE))
//         return(ptr);
// 	ft_bzero(ret, ft_strlen((char*)ptr) + size);
// 	ret = ft_memcpy(ret, ptr, ft_strlen((char*)ptr));
// 	if (ret == NULL)
// 		return (ptr);
//     // ft_putendl("_________________________________Realloc_call______________\n");

// 	free(ptr);
// 	return (ret);

//     // t_zone *tmp;
//     // t_zone *first;
//     // int page_size;
//     // ft_putendl("_________________________________Realloc_call 2______________\n");

//     // page_size = ((t_env *)glob)->page_size;
//     // ft_putendl("_________________________________Realloc_call 2.5______________\n");


  
//     // ft_putendl("_________________________________Realloc_call 3______________\n");

//     // return(ft_realloc(ptr,size));
//     // ft_putendl("_________________________________Realloc_call 4______________\n");

//     // first = ((t_env *)glob)->tiny;
//     // tmp  = find_in_zone(ptr,first);
//     // if (tmp != NULL && size < page_size * TINY_MULTY_PAGESIZE) // si dans la zone et size tj inf a la limite
//     // {
//     //     // if(tmp->size < page_size * TINY_MULTY_PAGESIZE)
//     //             return(ptr);
//     // }
//     // else if (tmp != NULL) // sinon on doit le changer de zone 
//     // {
//     //     void *tmp_ptr;
//     //     tmp_ptr  = malloc(size);
//     //     tmp_ptr  =  (voidptr;
//     //     // size_t i = 0;
//     //     // while (i < tmp->size)
//     //     // {
//     //     //     tmp_ptr[i] = ptr[i];
//     //     //     i++;
//     //     // }
//     //     return (tmp_ptr);  
//     // }
//     // return(NULL);
    
// }