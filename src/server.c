/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/10 23:02:08 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	dynamic_arr(char **res, char c)
{
	char		*tmp;
	static int	i = 0;
	static int	size = 1;

	if (i == size)
	{
		if (ft_calloc2(size * 2, sizeof(char), (void **) &tmp))
			return (1);
		ft_memcpy(tmp, *res, size);
		free(*res);
		*res = tmp;
		size = size * 2;
	}
	(*res)[i++] = c;
	if (c == '\0')
	{
		write(1, *res, i);
		free(*res);
		*res = NULL;
		i = 0;
		size = 1;
	}
	return (0);
}

static void	ft_btoa(int signal)
{
	static int	bit = 0;
	static char	c = 0;
	static char	*res = NULL;

	if (res == NULL && ft_calloc2(1, sizeof(char), (void **) &res))
		return ;
	c = c << 1;
	if (signal == SIGUSR2)
		c = c | 1;
	if (++bit == 7)
	{
		if (dynamic_arr(&res, c))
			return ;
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server is running. PID: %i\n", getpid());
	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);
	while (1)
		;
	return (0);
}
