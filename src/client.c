/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:00 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/09 12:27:38 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_atob(int pid, char c);
int		invalid_pid(char *str);
int		process_exists(int pid);

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (!(argc == 3))
		return (ft_printf("%s\n", "Wrong input! Use: ./client <pid> <str> "));
	if (invalid_pid(argv[1]))
		return (ft_printf("%s\n", "Invalid PID"));
	pid = atoi(argv[1]);
	if (!process_exists(pid))
		return (ft_printf("%s\n", "Process doesn't exists"));
	i = 0;
	while (argv[2][i])
	{
		ft_atob(pid, argv[2][i]);
		i++;
	}
	return (0);
}

void	ft_atob(int pid, char c)
{
	int		bit;
	char	signal;

	bit = 0;
	while (bit < 7)
	{
		signal = c & (0b1000000 >> bit);
		if (signal)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(100);
	}
}

int	invalid_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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
