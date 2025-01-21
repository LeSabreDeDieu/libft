/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:33:03 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:46:26 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	for (i = 0; i + needle_len <= len && haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0] && ft_memcmp(haystack + i, needle,
				needle_len) == 0)
			return (char *)(haystack + i);
	}
	return (NULL);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	return (ft_strnstr(haystack, needle, ft_strlen(haystack)));
}
