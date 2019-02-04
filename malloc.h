//faire la portection double inclusion
#include <stdlib.h>
#include <stdbool.h>
#include<sys/mman.h>


#define TINY_LS 100
#define SMALL_LS 100


typedef struct	s_zone {
    bool    used;
    void    *mem;
    void    *next;
	
}				t_zone;

typedef struct	s_env {
    t_zone  *tiny;
    t_zone  *small;
    t_zone  *large;
	
}				t_env;

// extern int plip;
extern void *glob;


// void free(void *ptr);
void *alloc(size_t size);
void *ft_malloc(size_t size);
// void *realloc(void *ptr, size_t size);

// mylst.c
t_zone  *new_lst(size_t nb_elem,size_t mem_size);
t_zone  *find_first_none_used(t_zone *first);
void    init_param(bool used,size_t mem_size,t_zone *p);
