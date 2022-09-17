/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:16:08 by cleibeng          #+#    #+#             */
/*   Updated: 2022/09/15 07:25:32 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	a;

	i = 0;
	n = 1;
	a = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + str[i] - '0';
		i++;
	}
	return (a * n);
}

static char	*rev_str(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j - 1];
		str[j - 1] = swap;
		i++;
		j--;
	}
	return (str);
}

static int	count_malloc(int n, int base)
{
	int	len_str;

	len_str = 1;
	if (n < 0)
	{
		len_str++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len_str++;
	}
	return (len_str);
}

char	*ft_itoa(int n, char *base)
{
	char			*str;
	int				len_str;
	int				base_len;
	int				m;

	base_len = ft_strlen(base);
	len_str = count_malloc(n, base_len);
	str = malloc(sizeof(char) * len_str + 1);
	if (!(str))
		exit(1);
	len_str = 0;
	m = n;
	while (m > 0)
	{
		str[len_str] = base[m % base_len];
		m /= base_len;
		len_str++;
	}
	str[len_str] = 0;
	str = rev_str(str);
	return (str);
}
