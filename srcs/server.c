/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:14:10 by cleibeng          #+#    #+#             */
/*   Updated: 2022/09/17 16:03:56 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_lib.h"

void	join(char **msg, int bit)
{
	if (bit == SIGUSR1)
		*msg = ft_strjoin((*msg), "0");
	else if (bit == SIGUSR2)
		*msg = ft_strjoin((*msg), "1");
}

void	handler(int signum)
{
	static char	*msg;
	char	*c;

	c = NULL;
	if (!msg)
		msg = NULL;
	if(ft_strlen(msg) < 8)
	{
		join(&msg, signum);
		usleep(200);
	}
	if (ft_strlen(msg) == 8)
	{
		ft_printf("%d", itoa2_from_char(msg));
		free(msg);
		msg = NULL;
	}
}

int	main(void)
{
	pid_t		PID;
	struct sigaction	act;

	PID = getpid();
	ft_printf("%d\n", PID);
	act.sa_handler = &handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
