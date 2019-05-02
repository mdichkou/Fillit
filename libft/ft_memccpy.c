/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:04:08 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/17 00:11:30 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*c_dst;
	unsigned const char	*c_src;
	unsigned char		c_copy;
	size_t				i;

	i = 0;
	c_copy = (unsigned char)c;
	c_dst = (unsigned char *)dst;
	c_src = (unsigned const char *)src;
	while (n > 0)
	{
		c_dst[i] = c_src[i];
		if (c_dst[i] == c_copy)
			return (dst + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
