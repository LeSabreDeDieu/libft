/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:15:05 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:13:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*set_aligned_words(void *s, unsigned char c, size_t n)
{
	size_t	*ptr;
	size_t	word;

	ptr = (size_t *)s;
	word = c;
	word |= word << 8;
	word |= word << 16;
	if (sizeof(size_t) == 8)
		word |= word << 32;
	while (n >= sizeof(size_t))
	{
		*ptr++ = word;
		n -= sizeof(size_t);
	}
	return ((void *)ptr);
}

static void	set_remaining_bytes(unsigned char *ptr, unsigned char c, size_t n)
{
	while (n--)
		*ptr++ = c;
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n && ((size_t)ptr & (sizeof(size_t) - 1)))
	{
		*ptr++ = uc;
		n--;
	}
	ptr = (unsigned char *)set_aligned_words(ptr, uc, n);
	set_remaining_bytes(ptr, uc, n & (sizeof(size_t) - 1));
	return (s);
}
