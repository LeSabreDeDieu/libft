/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:43:31 by sgabsi            #+#    #+#             */
/*   Updated: 2024/10/23 17:29:14 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	char	*str;
	int		ret;

	if (!s)
		return (-1);
	str = ft_strjoin(s, "\n");
	if (!str)
		return (-1);
	ret = ft_putstr_fd(str, fd);
	free(str);
	return (ret);
}
