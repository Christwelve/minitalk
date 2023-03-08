/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:00 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/08 16:03:57 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		invalid_pid(char *str);
int		process_exists(int pid);
void	ft_atob(int pid, char c);


int	main(int argc, char **argv)
{
	int pid;
	int i;

	pid = ft_atoi(argv[1]);
	i = 0;
	
	if (argc != 3)
		return (ft_printf("%s", "Wrong input! Use: ./client <pid> <str> "));
	if (invalid_pid(argv[1]))
		return (ft_printf("%s", "Invalid PID"));
	if (!process_exists(pid))
		return (ft_printf("%s", "Process doesn't exists"));
	while (argv[2][i])
	{
		ft_atob(pid, argv[2][i]);
		i++;
	}	
	return(0);
}

int	invalid_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;	
	}
	return (0);
}

int	process_exists(int pid)
{
	if (kill(pid, 0) == 0)
		return (1);
	return (0);
}

// SIGUSR1 = 0 
// SIGUSR2 = 1
void	ft_atob(int pid, char c)
{
	int bit;
	char signal;

	bit = 0;
	while (bit < 8)
	{
		signal = c & 1;
		if(signal)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		bit++;
		usleep(500);		
	}
}
