#include "malloc.h"

void erno(int i)
{
    ft_putstr("malloc Error : its apear mmap dont allocate  Code = ");
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