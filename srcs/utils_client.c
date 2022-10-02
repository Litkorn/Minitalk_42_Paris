/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:27:19 by cleibeng          #+#    #+#             */
/*   Updated: 2022/10/02 15:36:36 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_lib.h"

static int	*itoa_bin(int c)
{
	int	*c2;
	int	j;

	c2 = malloc(sizeof(unsigned int) * 9);
	if (!c2)
		return (NULL);
	c2[8] = '\0';
	j = 7;
	while (j >= 0)
	{
		if (c % 2 == 1)
			c2[j] = '1';
		else
			c2[j] = '0';
		j--;
		c /= 2;
	}
	return (c2);
}

int	g_sig = 0;

void	handler_client(int signum)
{
	(void)signum;
	g_sig = 1;
}

void	send_g_sig(int pid, char b)
{
	if (b == '0')
		kill(pid, SIGUSR1);
	else if (b == '1')
		kill(pid, SIGUSR2);
}

void	convert_and_send(int pid, char *str)
{
	int	i;
	int	j;
	int	*bi;

	i = 0;
	bi = NULL;
	while (str && str[i])
	{
		bi = itoa_bin(str[i]);
		j = 0;
		while (bi[j])
		{
			send_g_sig(pid, bi[j]);
			while (!g_sig)
				;
			g_sig = 0;
			j++;
		}
		i++;
		free(bi);
		bi = NULL;
	}
}
