/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/07 21:30:29 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();

	ft_printf("%s %i", "Server is running. Process ID:", pid);

	while(1)
	{
		
	}


}
