/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:41:18 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/17 00:15:05 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	t;

	d = (char *)dest;
	s = (char *)src;
	t = 0;
	if (s > d)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > t)
		{
			n--;
			d[n] = s[n];
		}
	}
	return ((void*)d);
}
