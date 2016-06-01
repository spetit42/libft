/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spetit <spetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 16:21:11 by spetit            #+#    #+#             */
/*   Updated: 2015/03/21 16:21:21 by spetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcsub(char *dst, const char *src, unsigned int start, size_t len)
{
	int i;

	i = 0;
	while (len != 0)
	{
		dst[i] = src[start];
		start++;
		i++;
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = ft_strnew(len);
	if (!str || (int)len < 0)
		return (NULL);
	ft_strcsub(str, s, start, len);
	return (str);
}
