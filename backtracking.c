/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <kadirialaouiayoub@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 01:39:52 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/11/16 13:09:37 by mdichkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**mapcreator(int dim)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * (dim + 1))))
		return (NULL);
	i = 0;
	while (i < dim)
	{
		tab[i] = ft_memalloc(dim + 1);
		ft_memset(tab[i], '.', dim);
		tab[i][dim] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

t_pl	init_l(int tij, int i)
{
	t_pl	l;

	l.z = tij;
	l.t = i;
	return (l);
}

t_pl	init_q(int x, int y)
{
	t_pl	l;

	l.x = x;
	l.y = y;
	return (l);
}

int		ft_backtracking(t_p *tab, int *tij,
		t_pl p, char **map)
{
	t_pl	q;
	t_pl	l;

	if (tij[0] == tij[1])
		return (1);
	l = init_l(tij[2], tij[0]);
	if (check_dispo(map, tab[tij[0]], p, &l) == 0)
		return (0);
	else
	{
		q = init_q(0, 0);
		tij[0]++;
		if (ft_backtracking(tab, tij, q, map) == 0)
		{
			ft_delete(map, --tij[0]);
			if (++l.x == tij[2] - 1)
			{
				l.x = 0;
				if (l.y++ == tij[2] - 1)
					return (0);
			}
			return (ft_backtracking(tab, tij, l, map));
		}
		return (1);
	}
}
