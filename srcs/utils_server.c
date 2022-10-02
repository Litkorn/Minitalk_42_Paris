/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:24:05 by cleibeng          #+#    #+#             */
/*   Updated: 2022/10/02 16:21:40 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_lib.h"

char	*mini_join(char *s1, char *s2, size_t i, size_t j)
{
	char	*s3;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	free (s1);
	return (s3);
}

int	convert_bin_2_dec(char *s)
{
	int	dec;

	dec = 0;
	if (s[0] == '1')
		dec += 128;
	if (s[1] == '1')
		dec += 64;
	if (s[2] == '1')
		dec += 32;
	if (s[3] == '1')
		dec += 16;
	if (s[4] == '1')
		dec += 8;
	if (s[5] == '1')
		dec += 4;
	if (s[6] == '1')
		dec += 2;
	if (s[7] == '1')
		dec += 1;
	return (dec);
}

void	handler_server(int signum, siginfo_t *info, void *context)
{
	static char	*msg;
	int			c;

	(void)context;
	if (signum == SIGUSR1)
		msg = mini_join(msg, "0", 0, 0);
	else if (signum == SIGUSR2)
		msg = mini_join(msg, "1", 0, 0);
	if (ft_strlen(msg) == 8)
	{
		c = convert_bin_2_dec(msg);
		if (c == '\n')
			ft_printf("\n");
		else
			(write(1, &c, 1));
		free(msg);
		msg = NULL;
	}
	kill(info->si_pid, SIGUSR1);
}
