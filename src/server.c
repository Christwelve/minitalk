/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/08 16:29:35 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_btoa(int sig)
{
	static int bit;
	static char c;

	bit = 0;
	c = 0;
	if(sig == SIGUSR2)
		c = c | 1;
	c = c << 1;	
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}	
	
}

int	main(void)
{
	ft_printf("%s %i", "Server is running. Process ID:", getpid());
	while(1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		sleep(1);
	}
	return(0);
}
