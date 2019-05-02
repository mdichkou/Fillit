/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalaoui- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:17:30 by aalaoui-          #+#    #+#             */
/*   Updated: 2018/11/16 13:16:33 by mdichkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef	struct	s_place
{
	int		x;
	int		y;
	int		z;
	int		t;
	int		i;
}				t_pl;

typedef	struct	s_point
{
	t_pl	p[4];
}				t_p;

int				check_dispo(char **map, t_p tab, t_pl cr, t_pl *s);
void			ft_add(char **map, struct	s_place plc, int nb, t_p tab);
void			ft_delete(char **map, int nb);
t_pl			find_center(t_p tab);
char			**mapcreator(int dim);
void			boardprint(char **map);
int				ft_backtracking(t_p *tab, int *tij, t_pl p, char **map);
int				tetris_verify_main(char **tetri);
int				tetris_min(int nb);

#endif
