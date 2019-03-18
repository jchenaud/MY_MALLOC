//faire la portection double inclusion
#include <stdlib.h>
#include <stdbool.h>
#include<sys/mman.h>
// #include<unistd.h>
#include"libft.h"
#include<stdint.h>


#include"libft.h" 
#include <stdio.h> // a enlever

#define TINY_LS 10
#define TINY_MULTY_PAGESIZE 1

#define SMALL_LS 10
#define SMALL_MULTY_PAGESIZE 2

#define NB_ADD_ZONE  75 //50

#define FAIL_ALLOC (void *) -1



typedef struct	s_plage {
    size_t    val_bigin;
    void    *ptr;
    bool    used;
    void    *next;
    size_t  size;
	
}				t_plage;

typedef struct	s_zone {
    bool    used;
    t_plage    *pla;
    void    *next;
    void    *mem;
    size_t  size;
	
}				t_zone;

// typedef struct	s_zone {
//     bool    used;
//     void    *mem;
//     void    *next;
//     size_t  size;
	
// }				t_zone;

typedef struct	s_env {
    t_zone  *tiny;
    t_zone  *small;
    t_zone  *large;
    t_plage *buff_plage;
    size_t  page_size;
	
}				t_env;

// extern int plip;
extern void *glob;


void free(void *ptr);
//void my_free(void *ptr);

void *alloc(size_t size);
// void *ft_malloc(size_t size);
void *malloc(size_t size);

//void *realloc(void *ptr, size_t size);
void show_alloc_mem();
void    ft_puthexa(void *ptr);//(uint64_t nb);

// mylst.c
t_zone  *new_lst(size_t nb_elem,size_t mem_size);
t_plage  *find_first_none_used_and_size(t_zone *first,size_t size,size_t max_size); // size tail du malloc max_size taill de la plage
t_plage *get_plage();

t_zone  *find_first_none_used(t_zone *first);
t_zone  *find_in_zone(void *ptr, t_zone *first);
size_t  find_index_in_zone(void *ptr, t_zone *first);
size_t  lst_count(t_zone *lst);


void    init_param(bool used,size_t mem_size,t_zone *p);
void    add_m_lst(size_t nb_elem,size_t mem_size,t_zone *lst);

// print_func

