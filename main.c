/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:18:09 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/13 18:32:01 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_arradd(char ***file, char *line, int size)
{
	char	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return ;
	tmp[size] = NULL;
	while (i < size - 1)
	{
		tmp[i] = ft_strdup((*file)[i]);
		i++;
	}
	tmp[i] = ft_strdup(line);
	free(*file);
	*file = tmp;
}

int		ft_readfile(char ***f, char *av)
{
	char	*line;
	int		i;
	int		fd;
	int		c;

	if (!(*f = (char **)ft_memalloc(sizeof(char *))))
		return (-1);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	**f = NULL;
	i = 1;
	c = 1;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
		{
			ft_arradd(f, line, c++);
			ft_strdel(&line);
		}
	}
	return (c - 1);
}

void	ft_set_transforms(t_info *shp)
{
	shp->c = 0;
	shp->clr = WHITE;
	shp->ot = ft_set_transf();
	(shp->ot)->t.x = 0;
	(shp->ot)->t.y = 0;
	if (shp->wc > shp->lc)
		(shp->ot)->t.z = -(shp->wc * 10);
	else
		(shp->ot)->t.z = -(shp->lc * 10);
	(shp->ot)->r.x = -0.2;
	(shp->ot)->r.y = 0.1;
	(shp->ot)->r.z = -0.2;
	(shp->ot)->s.x = 5;
	(shp->ot)->s.y = 5;
	(shp->ot)->s.z = 0.5;
}

int		ft_fdf(char *str)
{
	char *f_ext;

	f_ext = ft_strstr(str, ".fdf");
	if (!f_ext)
		return (0);
	else if (ft_strlen(f_ext) == 4)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_info	*shp;

	if (ac != 2 || !(ft_fdf(av[1])))
	{
		write(1, "Input Error\n", 12);
		return (0);
	}
	shp = ft_set_info(1280, 720);
	shp->mlx = mlx_init();
	shp->lc = ft_readfile(&(shp->file), av[1]);
	if (shp->lc == -1)
		return (0);
	shp->wc = ft_wrdcnt((shp->file)[0], ' ');
	ft_set_transforms(shp);
	if (!(shp->vals = ft_interpretfile(shp->file, shp->lc)))
		return (0);
	shp->win = mlx_new_window(shp->mlx, shp->size_x, shp->size_y, "FDF");
	ft_print_key();
	mlx_loop_hook((shp->mlx), &(ft_mapsetup), (void *)shp);
	mlx_key_hook(shp->win, ft_key_hook, shp);
	mlx_loop(shp->mlx);
	return (0);
}
