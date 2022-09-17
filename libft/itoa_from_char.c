/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_from_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:36:18 by cleibeng          #+#    #+#             */
/*   Updated: 2022/09/17 16:22:54 by cleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	new_len(int nb, int len)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i < len)
	{
		result *= nb;
		i++;
	}
	return (result);
}

int	itoa2_from_char(char *to_convert)
{
	int	nb;
	int	len;
	int	i;

	nb = 0;
	len = ft_strlen(to_convert);
	len = new_len(2, len);
	i = 0;
	while (to_convert[i])
	{
		if (to_convert[i] == '1')
			nb += len;
		len /= 2;
		i++;
	}
	return (nb);
}
