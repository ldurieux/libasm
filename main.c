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

#include "libasm.h"

#define TIMES 1000
#define SIZE 1000000

//NOLINTBEGIN
char	*make_str(void)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (SIZE + 1));
	if (!res)
		exit(1);
	memset(res, 'a', SIZE);
	i = 0;
	while (++i < SIZE)
		res[i] = i % (125) + 1;
	res[SIZE] = '\0';
	return (res);
}

//start_time = (float)clock()/CLOCKS_PER_SEC;
//for (int i = 0; i < TIMES; i++)
//	res = ft_strlen(str);
//end_time = (float)clock()/CLOCKS_PER_SEC;
//printf("ASM duration: %f : %lu\n", end_time - start_time, res);
int	main(void)
{
	size_t	res;
	char	*str;
	double	start_time;
	double	end_time;

	str = make_str();
	free(str);
	return (0);
}
//NOLINTEND
