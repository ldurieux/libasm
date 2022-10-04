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

#include "libasm.h"

#define TIMES 10000000
#define SIZE 1

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
	size_t	res;
	char	*str;
	char	*dst;
	double	start_time;
	double	end_time;

	dst = malloc(sizeof(char) * SIZE);
	str = make_str();
	start_time = (float)clock()/CLOCKS_PER_SEC;
	for (int i = 0; i < TIMES; i++)
		dst = ft_strcpy(dst, str);
	end_time = (float)clock()/CLOCKS_PER_SEC;
	printf("ASM duration: %f : %s\n", end_time - start_time, dst);
	start_time = (float)clock()/CLOCKS_PER_SEC;
	for (int i = 0; i < TIMES; i++)
		dst = strcpy(dst, str);
	end_time = (float)clock()/CLOCKS_PER_SEC;
	printf("C duration:   %f : %s\n", end_time - start_time, dst);
	free(str);
	return (0);
}
//NOLINTEND
