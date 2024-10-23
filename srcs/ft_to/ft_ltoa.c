/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:44:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/10/23 17:47:19 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ft_fill_res(long size, long offset, long nb, char *res)
{
	while (size > offset)
	{
		res[size - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
}

char	*ft_ltoa(long n)
{
	int		offset;
	int		size;
	long	nb;
	char	*res;

	offset = 0;
	nb = n;
	size = ft_get_size(nb);
	res = (char *)malloc(size + 1);
	if (!res)
		return (0);
	if (nb < 0)
	{
		res[0] = '-';
		offset = 1;
		nb = -nb;
	}
	ft_fill_res(size, offset, nb, res);
	res[size] = '\0';
	return (res);
}
