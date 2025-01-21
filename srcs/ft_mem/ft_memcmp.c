/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:59:26 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:08:37 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int compare_four_bytes(const unsigned char *str1, const unsigned char *str2)
{
    if (str1[0] != str2[0]) return str1[0] - str2[0];
    if (str1[1] != str2[1]) return str1[1] - str2[1];
    if (str1[2] != str2[2]) return str1[2] - str2[2];
    if (str1[3] != str2[3]) return str1[3] - str2[3];
    return 0;
}

static int compare_remaining_bytes(const unsigned char *str1, const unsigned char *str2, size_t n)
{
    while (n--)
    {
        if (*str1 != *str2)
            return (*str1 - *str2);
        str1++;
        str2++;
    }
    return 0;
}

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *str1 = (const unsigned char *)s1;
    const unsigned char *str2 = (const unsigned char *)s2;
    int result;

    while (n >= 4)
    {
        result = compare_four_bytes(str1, str2);
        if (result != 0)
            return result;
        str1 += 4;
        str2 += 4;
        n -= 4;
    }
    return compare_remaining_bytes(str1, str2, n);
}
