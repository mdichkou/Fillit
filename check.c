/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdichkou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:53:47 by mdichkou          #+#    #+#             */
/*   Updated: 2018/11/16 13:07:40 by mdichkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pl	find_center(t_p tab)
{
	int		i;
	t_pl	min;

	i = 0;
	min.x = tab.p[i].x;
	min.y = tab.p[i].y;
	while (i < 4)
	{
		if (tab.p[i].x < min.x)
			min.x = tab.p[i].x;
		if (tab.p[i].y < min.y)
			min.y = tab.p[i].y;
		i++;
	}
	return (min);
}

void	ft_add(char **map, t_pl plc, int nb, t_p tab)
{
	int				i;
	t_p				pl;
	t_pl			l;
	t_pl			min;

	min = find_center(tab);
	i = 0;
	l.x = min.x - plc.x;
	l.y = min.y - plc.y;
	while (i < 4)
	{
		pl.p[i].x = tab.p[i].x - l.x;
		pl.p[i].y = tab.p[i].y - l.y;
		map[pl.p[i].y][pl.p[i].x] = nb + 65;
		i++;
	}
}

void	ft_delete(char **map, int nb)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == nb + 65)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		check_dispo_backup(char **map, t_p tab, t_pl cr, t_pl *s)
{
	t_pl			min;
	t_pl			l;
	t_p				plc;
	int				k;

	min = find_center(tab);
	k = -1;
	while (++k < 4)
	{
		l.x = min.x - cr.x;
		l.y = min.y - cr.y;
		plc.p[k].x = tab.p[k].x - l.x;
		plc.p[k].y = tab.p[k].y - l.y;
		if (plc.p[k].y >= (*s).z || plc.p[k].x >= (*s).z
				|| map[plc.p[k].y][plc.p[k].x] != '.')
			return (0);
		if (map[plc.p[k].y][plc.p[k].x] == '.' && k == 3)
		{
			ft_add(map, cr, (*s).t, tab);
			(*s).x = cr.x;
			(*s).y = cr.y;
			return (1);
		}
	}
	return (0);
}

int		check_dispo(char **map, t_p tab, t_pl cr, t_pl *s)
{
	while (map[cr.y])
	{
		while (map[cr.y][cr.x])
		{
			if (check_dispo_backup(map, tab, cr, s) == 1)
				return (1);
			cr.x++;
		}
		cr.x = 0;
		cr.y++;
	}
	return (0);
}
