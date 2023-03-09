/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/09 11:25:38 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void ft_btoa(int signal);

int	main(void)
{
	ft_printf("Server is running. PID: %i\n", getpid());
	signal(SIGUSR1, ft_btoa);
	signal(SIGUSR2, ft_btoa);
	
	while(1);	
	return(0);
}

void ft_btoa(int signal)
{
	static int bit = 0;
	static char c = 0;
	
	c = c << 1;	
	if(signal == SIGUSR2)
		c = c | 1;
	bit++;
	if (bit == 7)
	{			
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}	
}
