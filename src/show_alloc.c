#include "malloc.h"
// #include "ft_// printf.h"
void *glob;

void	ft_puthexa(void *ptr)//(uint64_t nb)
{
	uint64_t nb = (uint64_t)ptr;
	char	hex_revert[16];
	int		hex[16];
	int		i;

	ft_bzero(hex_revert, 16);
	ft_bzero(hex, 16);
	i = 0;
	while (nb)
	{
		hex[i] = nb % 16;
		if (hex[i] >= 10)
			hex_revert[i] = hex[i] + 'A' - 10;
		else
			hex_revert[i] = hex[i] + '0';
		nb /= 16;
		i++;
	}
	ft_putstr("0x");
	while (i >= 0)
	{
		ft_putchar(hex_revert[i]);
		i--;
	}
}


size_t print_mem_zone(t_zone *first)
{
    t_zone *tmp;
    size_t octes;

    octes = 0;
    tmp = first;
    if(!first)
        return(0);
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
        else if(tmp->used == -1)
        {
            ft_putstr("\n\t");
            ft_puthexa(tmp);
            ft_putstr("\n\t");

        }
        tmp =  tmp->next;
    }
    ft_putchar('\n');
    return (octes);
}

void show_alloc_mem()
{
    //t_env *e;
    size_t octes;

  //  e = (t_env*)glob;
    int k = 13;
    char *stradd = (char*) &k;
    
    // // printf("%s , %p\n",stradd,e);
    // ft_puthexa((uint64_t)&e);
    ft_putstr("\n");
    ft_putstr("TINY : "); ft_puthexa(g_e.tiny); ft_putstr("\n\t");
    octes = print_mem_zone(g_e.tiny);
    ft_putstr("SMALL : "); ft_puthexa(g_e.small); ft_putstr("\n\t");;
    octes += print_mem_zone(g_e.small);
    ft_putstr("LARGE : ");ft_puthexa(g_e.large); ft_putstr("\n\t");;
    octes += print_mem_zone(g_e.large);    
    ft_putstr("Total : ");
    ft_putnbr(octes);
    ft_putstr(" octets\n");
}