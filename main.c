/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:15:17 by ldurieux          #+#    #+#             */
/*   Updated: 2022/10/03 13:15:18 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "libasm.h"

#define TIMES 10000000
#define SIZE 10

//NOLINTBEGIN
char	*make_str(void)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (SIZE + 1));
	if (!res)
		exit(1);
	memset(res, 'a', SIZE);
	i = -1;
	while (++i < SIZE)
		res[i] = i % (125) + 1;
	res[SIZE] = '\0';
	return (res);
}

int	main(void)
{
	int		res;
	char	*s1;
	char	*s2;
	double	start_time;
	double	end_time;

	s1 = malloc(sizeof(char) * 10);
	res = ft_read(3, s1, 5);
	if (res == -1)
	{
		printf("%s\n", strerror(errno));
		return (res);
	}
	ft_write(1, s1, res);
//	s1 = make_str();
//	s2 = make_str();
//	ft_strcmp(s1, s2);
//	start_time = (float)clock()/CLOCKS_PER_SEC;
//	for (int i = 0; i < TIMES; i++)
//		res = ft_strcmp(s1, s2);
//	end_time = (float)clock()/CLOCKS_PER_SEC;
//	printf("ASM duration: %f : %d\n", end_time - start_time, res);
//	start_time = (float)clock()/CLOCKS_PER_SEC;
//	for (int i = 0; i < TIMES; i++)
//		res = strcmp(s1, s2);
//	end_time = (float)clock()/CLOCKS_PER_SEC;
//	printf("C duration:   %f : %d\n", end_time - start_time, res);
//	free(s1);
//	free(s2);
	return (0);
}
//NOLINTEND
