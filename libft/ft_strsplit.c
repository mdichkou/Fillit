/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 04:09:12 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/19 20:10:48 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	char	*s_copy;

	str = NULL;
	s_copy = NULL;
	i = 0;
	j = 0;
	if (s)
	{
		s_copy = (char *)s;
		if (!(str = (char **)malloc(sizeof(char *) * (ft_cw(s_copy, c) + 1))))
			return (NULL);
		while (s_copy[i] && j < ft_cw(s_copy, c))
		{
			while (s_copy[i] == c)
				i++;
			str[j++] = ft_strsub(s_copy + i, 0, ft_wl(s_copy + i, c) + 1);
			i += ft_wl(s_copy + i, c) + 1;
		}
		str[j] = NULL;
	}
	return (str);
}
