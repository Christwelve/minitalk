/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/09 12:29:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_btoa(int signal);

int	main(void)
{
	ft_printf("Server is running. PID: %i\n", getpid());
	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);
	while (1)
	{
	}
	return (0);
}

void	ft_btoa(int signal)
{
	static int	bit;
	static char	c;

	bit = 0;
	c = 0;
	c = c << 1;
	if (signal == SIGUSR2)
		c = c | 1;
	bit++;
	if (bit == 7)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}
