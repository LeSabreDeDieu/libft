/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:54:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/10/23 18:02:17 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long	num;
	int			neg;

	neg = 1;
	num = 0;
	while (*str && ft_isspace(*str))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		++str;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		num = num * 10 + (*str - '0');
		++str;
	}
	return (num * neg);
}

unsigned long long	ft_atoull(const char *str)
{
	unsigned long long	num;

	num = 0;
	while (*str && ft_isspace(*str) && (*str == '+' || *str == '-'))
		++str;
	while ((*str >= '0' && *str <= '9') && *str)
	{
		num = num * 10 + (*str - '0');
		++str;
	}
	return (num);
}
