/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 12:49:59 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/18 04:02:28 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_copy;
	int		i;

	i = 0;
	s_copy = (char *)s;
	if (s)
	{
		s_copy = ft_strnew(ft_strlen(s));
		if (s_copy == NULL)
			return (NULL);
		while (s[i])
		{
			s_copy[i] = (*f)(s[i]);
			i++;
		}
		s_copy[i] = '\0';
	}
	return (s_copy);
}
