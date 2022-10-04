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
		res[i] = i % (125) + 'a';
	res[SIZE] = '\0';
	return (res);
}

int	main(void)
{
	char	*res;
	char	*s1;
	char	*s2;
	double	start_time;
	double	end_time;

	s1 = make_str();
	res = ft_strdup(s1);
	if (!res)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	if (ft_write(1, s1, SIZE - 1) == -1)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	return (0);
}
//NOLINTEND
