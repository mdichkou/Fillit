/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <kadirialaouiayoub@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:30:34 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/11/16 12:49:05 by mdichkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_positions(char **tetri, t_p *tab)
{
	int i;
	int j;
	int k;

	i = 0;
	while (tetri[i])
	{
		j = 0;
		k = 0;
		while (tetri[i][j] && k <= 3)
		{
			if (tetri[i][j] == '#')
			{
				tab[i].p[k].x = j % 5;
				tab[i].p[k].y = j / 5;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	boardprint(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		tetrisreader(char **tetri, char *file)
{
	char	*s;
	int		fd;
	int		rd;
	int		j;

	j = 0;
	s = ft_strnew(21);
	fd = open(file, O_RDONLY);
	*tetri = ft_strdup("");
	while ((read(fd, s, 20)))
	{
		tetri[j++] = ft_strdup(s);
		rd = read(fd, s, 1);
		if (*s != '\n' && rd == 1)
			return (0);
		ft_strclr(s);
	}
	if (rd == 1)
		return (0);
	tetri[j] = NULL;
	return (j);
}

int		tetri_solver(t_p *tab, int *tij, char **map)
{
	t_pl p;

	p.x = 0;
	p.y = 0;
	while (1)
	{
		tij[0] = 0;
		if (!ft_backtracking(tab, tij, p, map))
		{
			tij[2]++;
			map = mapcreator(tij[2]);
		}
		else
			break ;
	}
	boardprint(map);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*tetri[27];
	t_p		tab[26];
	int		tij[3];
	char	**map;

	tij[0] = 0;
	if (argc == 2)
	{
		tij[1] = tetrisreader(tetri, argv[1]);
		if (tetris_verify_main(tetri))
		{
			if (tij[1] == 0 || tij[1] > 26)
			{
				ft_putstr("error\n");
				return (0);
			}
			tij[2] = tetris_min(tij[1]) - 1;
			map = mapcreator(tij[2]);
			find_positions(tetri, tab);
			tetri_solver(tab, tij, map);
			return (0);
		}
	}
	ft_putstr("error\n");
	return (0);
}
