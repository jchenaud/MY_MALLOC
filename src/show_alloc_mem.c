#include "malloc.h"
// #include "ft_printf.h"
void *glob;

size_t print_mem_zone(t_zone *first)
{
    t_zone *tmp;
    size_t octes;

    octes = 0;
    tmp = first;
    while (tmp->next != NULL)
    {
        if (tmp->used == true)
        {
            ft_puthexa(tmp);
            ft_putstr(" -> ");
            ft_puthexa(tmp->mem);
            ft_putstr(" : ");
            ft_putnbr(tmp->size);
            ft_putstr("\n\t");
            octes += tmp->size;
        }
        tmp =  tmp->next;
    }
    ft_putchar('\n');
    return (octes);
}

void show_alloc_mem()
{
    t_env *e;
    size_t octes;

    e = (t_env*)glob;
    int k = 13;
    char *stradd = (char*) &k;
    
    // printf("%s , %p\n",stradd,e);
    // ft_puthexa((uint64_t)&e);
    ft_putstr("\n");
    ft_putstr("TINY : "); ft_puthexa(e->tiny); ft_putstr("\n\t");
    octes = print_mem_zone(e->tiny);
    ft_putstr("SMALL : "); ft_puthexa(e->small); ft_putstr("\n\t");;
    octes += print_mem_zone(e->small);
    ft_putstr("LARGE : ");ft_puthexa(e->large); ft_putstr("\n\t");;
    octes += print_mem_zone(e->large);    
    ft_putstr("Total : ");
    ft_putnbr(octes);
    ft_putstr(" octets\n");
}