/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdichkou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:00:10 by mdichkou          #+#    #+#             */
/*   Updated: 2018/11/16 13:00:27 by mdichkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	tetris_verify_form(char *tetri)
{
	int i;
	int connexion;

	i = 0;
	connexion = 0;
	while (tetri[i])
	{
		if (tetri[i] == '#')
		{
			if (tetri[i + 1] == '#')
				connexion++;
			if (tetri[i + 5] == '#')
				connexion++;
		}
		i++;
	}
	return (connexion);
}

int	tetris_verify_compos(char *tetri)
{
	int i;
	int hash;
	int point;
	int line;

	line = 0;
	point = 0;
	hash = 0;
	i = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.')
			point++;
		else if (tetri[i] == '#')
			hash++;
		else if (tetri[i] == '\n')
			line++;
		else
			return (0);
		i++;
	}
	if (point == 12 && hash == 4 && line == 4 && tetri[19] == '\n' &&
			tetri[4] == '\n' && tetri[9] == '\n' && tetri[14] == '\n')
		return (1);
	return (0);
}

int	tetris_min(int nb)
{
	int i;
	int j;

	i = 2;
	nb *= 4;
	j = 2;
	while (1)
	{
		if (i >= nb)
			return (j);
		i *= i;
		j++;
	}
	return (0);
}

int	tetris_verify_main(char **tetri)
{
	int i;

	i = 0;
	while (tetri[i])
	{
		if (tetris_verify_compos(tetri[i]) && tetris_verify_form(tetri[i]) >= 3)
			i++;
		else
			return (0);
	}
	return (1);
}
