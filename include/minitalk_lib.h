/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_lib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:14:41 by cleibeng          #+#    #+#             */
/*   Updated: 2022/10/01 04:36:06 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_LIB_H
# define MINITALK_LIB_H

# include "../libft/libft.h"
# include <sys/signal.h>

# ifndef _POSIX_C_SOURCE
#  define _POSIX_C_SOURCE 199309L
# endif

//server.c
int		convert_bin_2_dec(char *s);
void	handler_server(int signum, siginfo_t *info, void *context);
char	*mini_join(char *s1, char *s2, size_t i, size_t j);

//client.c
void	convert_and_send(int pid, char *str);
void	handler_client(int signum);
void	send_sig(int pid, char b);

#endif
