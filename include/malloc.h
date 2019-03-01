//faire la portection double inclusion
#include <stdlib.h>
#include <stdbool.h>
#include<sys/mman.h>
#include<unistd.h>
#include"libft.h"
#include<stdint.h>

#define TINY_LS 100
#define TINY_MULTY_PAGESIZE 1

#define SMALL_LS 100
#define SMALL_MULTY_PAGESIZE 2

#define NB_ADD_ZONE  50

#define FAIL_ALLOC (void *) -1



typedef struct	s_zone {
    bool    used;
    void    *mem;
    void    *next;
    size_t  size;
	
}				t_zone;

typedef struct	s_env {
    t_zone  *tiny;
    t_zone  *small;
    t_zone  *large;
    size_t  page_size;
	
}				t_env;

// extern int plip;
extern void *glob;


void free(void *ptr);
void *alloc(size_t size);
void *ft_malloc(size_t size);
// void *realloc(void *ptr, size_t size);
void show_alloc_mem();
// mylst.c
t_zone  *new_lst(size_t nb_elem,size_t mem_size);
t_zone  *find_first_none_used(t_zone *first);
t_zone  *find_in_zone(void *ptr, t_zone *first);
size_t  find_index_in_zone(void *ptr, t_zone *first);


void    init_param(bool used,size_t mem_size,t_zone *p);
void    add_m_lst(size_t nb_elem,size_t mem_size,t_zone *lst);

// print_func

