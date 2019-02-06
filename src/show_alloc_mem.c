#include "malloc.h"
// #include "ft_printf.h"
void *glob;

void print_mem_zone(t_zone *first)
{
    t_zone *tmp;
    tmp = first;
    while (tmp->next != NULL)
    {
        if (tmp->used == true)
        {
            ft_puthexa(tmp);
            ft_putstr(" -> ");
            ft_puthexa(tmp->mem);
            ft_putstr(" :  pas_encore_dispo octes\n");
        }
        tmp =  tmp->next;
    }
}

void show_alloc_mem()
{
    t_env *e;

    e = (t_env*)glob;
    int k = 13;
    char *stradd = (char*) &k;
    // printf("%s , %p\n",stradd,e);
    ft_puthexa((uint64_t)&e);
    ft_putstr("\n");
    ft_putstr("TINY : "); ft_puthexa(e->tiny); ft_putchar('\n');
    print_mem_zone(e->tiny);
    ft_putstr("SMALL : "); ft_puthexa(e->small); ft_putchar('\n');
    print_mem_zone(e->small);
    ft_putstr("LARGE : ");ft_puthexa(e->large); ft_putchar('\n');
    print_mem_zone(e->large);    
    ft_putstr("tottal octes\n");
}