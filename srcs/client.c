/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:19:56 by cleibeng          #+#    #+#             */
/*   Updated: 2022/09/16 17:40:28 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_lib.h"
#include "../libft/libft.h"

void	send_sig(int pid, int b)
{
	if (b == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	convert_and_send(int pid, char *str)
{
	int		i;
	int		j;
	char	*bi;

	i = 0;
	bi = NULL;
	while (str && str[i])
	{
		bi = ft_itoa(str[i], "01");
		j = 0;
		while (bi[j] && j++ + ft_strlen(bi) < 8)
			send_sig(pid, 0);
		j = 0;
		while (bi[j++])
			send_sig(pid, bi[j]);
		free(bi);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	convert_and_send(pid, av[2]);
}
