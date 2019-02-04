#include "malloc.h"

#include <stdio.h>
#include <unistd.h>

// void **ZONE_AL = NULL;
static bool init =  false;
void *glob;
void *alloc(size_t size)
{
    // printf("%d",size);
    return((void *)mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
}

// void *save_zone(void *)
void *ft_malloc(size_t size)
{

    printf("%p/\n",glob);
    // if(glob == NULL)
    if(init == false)
        {
            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            e->tiny = new_lst(TINY_LS,100);
            e->small = new_lst(TINY_LS,1000);
            printf("%p/ %p\n",e,e->tiny);
            init = true;
            glob = e;
        }
    
    // int i;
    // int page_size = getpagesize();
    // printf("%d\n",page_size);
    // if(ZONE_AL == NULL)
    //     ZONE_AL =  (void**)alloc(3);
    //     i = 0;
    //     while(i < 3)
    //     {
    //         ZONE_AL[i] = alloc(page_size*(i+1));
    //         i++;
    //     }
    
    //  if (size < page_size/100)
    //     return(alloc(page_size/100));   
    // else if(size < 1000)
    //     return(alloc(100));
    // else
    //     return(alloc(size));
    return(alloc(size));   
    
    // if (size < page_size)
    //     return(alloc(page_size));   
    // else if(size < 1000)
    //     return(alloc(100));
    // else
    //     return(alloc(size));
// switch(size) {

//    case size < 100 :
//       return(alloc(100));
//    case size < 1000 :
//       return(alloc(1000));
//    default :
//       return(alloc(size));
//    statement(s);
// }
}



