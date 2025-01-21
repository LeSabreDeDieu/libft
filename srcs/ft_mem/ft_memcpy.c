/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:39:50 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:10:10 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_aligned_words(void *dest, const void *src, size_t n)
{
	size_t			*d;
	const size_t	*s = (const size_t *)src;

	d = (size_t *)dest;
	while (n >= sizeof(size_t))
	{
		*d++ = *s++;
		n -= sizeof(size_t);
	}
	return ((void *)d);
}

static void	copy_remaining_bytes(unsigned char *d, const unsigned char *s,
		size_t n)
{
	while (n--)
		*d++ = *s++;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	d = (unsigned char *)dest;
	while (n && ((size_t)d & (sizeof(size_t) - 1)))
	{
		*d++ = *s++;
		n--;
	}
	d = copy_aligned_words(d, s, n);
	s += n & ~(sizeof(size_t) - 1);
	copy_remaining_bytes(d, s, n & (sizeof(size_t) - 1));
	return (dest);
}
