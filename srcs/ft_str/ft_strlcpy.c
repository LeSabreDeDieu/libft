/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:12:59 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:33:47 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		copy_len = size - 1;
		if (copy_len > src_len)
			copy_len = src_len;
		ft_memmove(dest, src, copy_len);
		dest[copy_len] = '\0';
	}
	return (src_len);
}
