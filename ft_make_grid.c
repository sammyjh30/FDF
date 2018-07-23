/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:07:13 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/16 07:07:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_worldcoords(t_vertex *vert, t_info *shp)
{
	double	**glb;

	glb = ft_make_matrix(4);
	ft_id_matrix(glb);
	ft_trnsf_rot(glb, (shp->ot)->r.x, (shp->ot)->r.y, (shp->ot)->r.z);
	ft_trnsf_trans(glb, (shp->ot)->t.x, (shp->ot)->t.y, (shp->ot)->t.z);
	ft_trnsf_scale(glb, 1, 1, 0.001);
	ft_vect_matrix_mult(&vert->w, &vert->lcl, glb);
	ft_delmatrix(glb, 4);
}

int		ft_project(t_vertex *v)
{
	if ((v->w).z < 1)
	{
		(v->scrn).x = (v->w).x / -(v->w).z;
		(v->scrn).y = (v->w).y / -(v->w).z;
		return (0);
	}
	else
	{
		return (-1);
	}
}

void	ft_assign_coords(t_info *s, t_verts *v, int i, int j)
{
	(v->v1)->lcl.x = (j - (s->wc / 2)) * (s->ot)->s.x;
	(v->v1)->lcl.y = (i - (s->lc / 2)) * (s->ot)->s.y;
	if (j + 1 < s->wc)
	{
		(v->v1)->lcl.z = (((s->vals)[i][j])) * (s->ot)->s.z;
		(v->v2)->lcl.x = ((j + 1) - (s->wc / 2)) * (s->ot)->s.x;
		(v->v2)->lcl.y = (i - (s->lc / 2)) * (s->ot)->s.y;
		(v->v2)->lcl.z = (((s->vals)[i][j + 1])) * (s->ot)->s.z;
		ft_transform(s, v);
	}
	if (i + 1 < s->lc && j <= s->wc)
	{
		(v->v1)->lcl.z = (((s->vals)[i][j])) * (s->ot)->s.z;
		(v->v2)->lcl.x = (j - (s->wc / 2)) * (s->ot)->s.x;
		(v->v2)->lcl.y = ((i + 1) - (s->lc / 2)) * (s->ot)->s.y;
		(v->v2)->lcl.z = (((s->vals)[i + 1][j])) * (s->ot)->s.z;
		ft_transform(s, v);
	}
}

int		ft_mapsetup(t_info *shp)
{
	int			i;
	int			j;
	t_verts		*v;

	v = ft_set_verts();
	i = 0;
	mlx_clear_window(shp->mlx, shp->win);
	while (i < shp->lc)
	{
		j = 0;
		while (j < shp->wc)
		{
			ft_assign_coords(shp, v, i, j);
			j++;
		}
		i++;
	}
	free(v);
	return (0);
}
