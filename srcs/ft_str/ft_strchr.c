/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:45:26 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:25:26 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (c == '\0')
		return (char *)(str + len);
	return (char *)ft_memchr(str, c, len);
}
