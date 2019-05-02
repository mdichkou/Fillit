/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcustomtrim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 23:26:12 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/19 15:00:32 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcustomtrim(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = NULL;
	if (s)
	{
		j = ft_strlen(s) - 1;
		while (s[i] == c)
			i++;
		while (s[j] == c)
			j--;
		str = ft_strnew(j - i + 1);
		if (i >= j)
			return ("");
		if (str == NULL)
			return (NULL);
		ft_strncpy(str, s + i, j - i + 1);
	}
	return (str);
}
