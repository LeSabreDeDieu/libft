/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:52:55 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:27:13 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	min_len;
	int		result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 < len2)
		min_len = len1;
	else
		min_len = len2;
	result = ft_memcmp(s1, s2, min_len);
	if (result != 0)
		return (result);
	if (len1 == len2)
		return (0);
	return ((unsigned char)s1[min_len] - (unsigned char)s2[min_len]);
}
