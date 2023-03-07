/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:37:08 by cmeng             #+#    #+#             */
/*   Updated: 2023/03/07 13:35:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/libs.h"
#include <unistd.h>
#include <signal.h>

int	main(void)
{
	int	pid;

	pid = getpid();

	ft_printf("%s %i", "Server is running. Process ID:", pid);

	while(1)
	{
		
	}


}
