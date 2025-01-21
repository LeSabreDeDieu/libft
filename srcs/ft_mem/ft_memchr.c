/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:14:56 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:04:47 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str = (const unsigned char *)s;
	unsigned char		uc;

	uc = (unsigned char)c;
	while (n >= 4)
	{
		if (str[0] == uc)
			return (void *)(str);
		if (str[1] == uc)
			return (void *)(str + 1);
		if (str[2] == uc)
			return (void *)(str + 2);
		if (str[3] == uc)
			return (void *)(str + 3);
		str += 4;
		n -= 4;
	}
	while (n--)
	{
		if (*str == uc)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
