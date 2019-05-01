#include <pthread.h>
#include <unistd.h>
#include "malloc.h"

void *f(void *tmp)
{
	void *addr;

	addr = malloc(1024);
	addr = realloc(addr, 64);
	free(addr);
}

int main()
{
	while (1)
	{
		size_t size = 100;
		pthread_t thread[size];

		for (int i = 0; i < size; i++) {
			if (pthread_create(&thread[i], NULL, f, NULL) != 0)
				return (ft_putendl("error pthread_create"), 1);
		}
		for (int i = 0; i < size; i++) {
			if (pthread_join(thread[i], NULL) != 0)
				return (ft_putendl("error pthread_join"), 1);
			ft_putstr("thread ");
			ft_putnbr(i);
			ft_putendl(" finishel normally");
		}

		if (pthread_create(&thread[0], NULL, f, NULL) != 0)
			return (ft_putendl("error pthread_create"), 1);
		if (pthread_create(&thread[1], NULL, f, NULL) != 0)
			return (ft_putendl("error pthread_create"), 1);
		if (pthread_create(&thread[2], NULL, f, NULL) != 0)
			return (ft_putendl("error pthread_create"), 1);
		if (pthread_create(&thread[3], NULL, f, NULL) != 0)
			return (ft_putendl("error pthread_create"), 1);

		if (pthread_join(thread[0], NULL) != 0)
			return (ft_putendl("error pthread_join"), 1);
		ft_putendl("join thread 0 is finished");
		if (pthread_join(thread[1], NULL) != 0)
			return (ft_putendl("error pthread_join"), 1);
		ft_putendl("join thread 1 is finished");
		if (pthread_join(thread[2], NULL) != 0)
			return (ft_putendl("error pthread_join"), 1);
		ft_putendl("join thread 2 is finished");
		if (pthread_join(thread[3], NULL) != 0)
			return (ft_putendl("error pthread_join"), 1);
		ft_putendl("join thread 3 is finished");
	}
	pthread_exit(NULL);
	return (0);
};
