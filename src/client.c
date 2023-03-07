/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:00 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/07 21:30:21 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	process_exists(int pid)
{
	if (kill(pid, 0) == 0)
		return (1);
	return (0);
}

int	invalid_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 3)
		return (ft_printf("%s", "Too many arguments"));
	if (invalid_pid(argv[1]))
		return (ft_printf("%s", "Invalid PID"));
	if (process_exists(ft_atoi(argv[1])))
		return (ft_printf("%s", "Process doesn't exist"));
}

