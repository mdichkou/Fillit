/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:16:48 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/17 00:10:00 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;
	unsigned char c_copy;

	c_copy = (unsigned char)c;
	str = (unsigned char *)b;
	while (len > 0)
	{
		*str = c_copy;
		str++;
		len--;
	}
	return (b);
}
