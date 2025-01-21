/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:25:18 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:33:20 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	total_len;
	size_t	copy_len;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (size <= lendest)
		return (size + lensrc);
	total_len = lendest + lensrc;
	copy_len = size - lendest - 1;
	if (copy_len > 0)
		ft_memmove(dest + lendest, src, copy_len);
	dest[lendest + copy_len] = '\0';
	return (total_len);
}
