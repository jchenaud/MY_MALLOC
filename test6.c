#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

void *ptr[1000];

void *function()
{
	for (int i = 0; i < 1000; i++)
	{
		ptr[i] = malloc(1024);
		free(ptr[i]);
	}
	return NULL;
}

int main()
{
	while (1)
	{
		size_t size = 100;
		pthread_t thread[size];

		for (int i = 0; i < size; i++)
			pthread_create(&thread[i], NULL, function, NULL);

		for (int i = 0; i < size; i++)
			pthread_join(thread[i], NULL);

		ft_putendl("finish");
	}
	return (0);
}
