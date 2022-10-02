/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:19:56 by cleibeng          #+#    #+#             */
/*   Updated: 2022/10/02 16:20:12 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_lib.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_handler = &handler_client;
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	convert_and_send(pid, av[2]);
	convert_and_send(pid, "\n");
}
