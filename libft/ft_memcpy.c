/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:14:15 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/18 21:16:20 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *c_dest;
	char *c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	while (n > 0)
	{
		*c_dest++ = *c_src++;
		n--;
	}
	return (dest);
}
