/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:27:03 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/10/19 19:56:15 by aalaoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			charlen;

	nb = n;
	charlen = 0;
	if (n < 0)
	{
		nb = nb * -1;
		charlen++;
	}
	charlen += ft_charcalculator(nb);
	if (!(str = (char*)malloc(sizeof(char) * (charlen + 1))))
		return (NULL);
	str[charlen] = '\0';
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (nb)
	{
		str[--charlen] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
