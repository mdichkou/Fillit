/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:11:52 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/17 00:27:15 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*s_copy;

	i = 0;
	s_copy = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (&s_copy[i]);
	while (i--)
	{
		if (s_copy[i] == c)
			return (s_copy + i);
	}
	return (NULL);
}
