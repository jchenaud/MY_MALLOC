#include "malloc.h"

void erno(int i)
{
    ft_putstr("malloc Error : its appear mmap cannot allocate ");
    ft_putchar(i+48);
    ft_putchar('\n');

}

void *p_erno(int i)
{
    ft_putstr("malloc Error : its apear mmap dont allocate  Code = ");
    ft_putchar(i+48);
    ft_putchar('\n');
    return  (NULL);
}

void *rea_undifined()
{
    ft_putendl("Realloc Error : its appear you tried to modify a pointer not allocated with this malloc");
    return (NULL);
}