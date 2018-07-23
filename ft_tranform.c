/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tranform.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:02:17 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/20 09:02:50 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_limmult(double n)
{
	if (n < 0)
		return (-1);
	else if (n > 0)
		return (1);
	else
		return (0);
}

void	ft_vect_calc(t_info *s, t_verts *v, int *x, int *y)
{
	int		l;
	int		m;
	int		n;

	l = ((v->v2)->w).x - ((v->v1)->w).x;
	m = ((v->v2)->w).y - ((v->v1)->w).y;
	n = -((v->v2)->w).z + ((v->v1)->w).z;
	*x = (s->size_x / 2) - ((-((v->v1)->w).z / n) * l - ((v->v1)->w).x);
	*y = (s->size_y / 2) - ((-((v->v1)->w).z / n) * m - ((v->v1)->w).y);
}

void	ft_limit(t_info *s, t_verts *v, int *x, int *y)
{
	ft_vect_calc(s, v, x, y);
	if (ft_limmult(((v->v1)->w).x) == 0 && ft_limmult(((v->v1)->w).y) != 0)
	{
		*x = (s->size_x / 2);
		*y = ft_limmult(((v->v1)->w).y) * (s->size_y / 2);
		*y = *y + (((((v->v1)->w).y / -((v->v1)->w).z) + *y) / 2);
	}
	else if (ft_limmult(((v->v1)->w).y) == 0 && ft_limmult(((v->v1)->w).x) != 0)
	{
		*x = ft_limmult(((v->v1)->w).x) * (s->size_x / 2);
		*x = *x + (((((v->v1)->w).x / -((v->v1)->w).z) + *x) / 2);
		*y = (s->size_y / 2);
	}
	else if (ft_limmult(((v->v1)->w).y) != 0 && ft_limmult(((v->v1)->w).x) != 0)
	{
		*x = ft_limmult(((v->v1)->w).x) * (s->size_x / 2);
		*x = *x + ((((v->v1)->w).x / -((v->v1)->w).z + s->size_x / 2) + *x) / 2;
		*y = ft_limmult(((v->v1)->w).y) * (s->size_y / 2);
		*y = *y + ((((v->v1)->w).y / -((v->v1)->w).z + s->size_y / 2) + *y) / 2;
	}
}

void	ft_draw_limit(t_info *shp, t_verts *v)
{
	if (((v->v1)->w).z < 0 && ((v->v2)->w).z >= 0)
	{
		(shp->pnt)->x1 = ((v->v1)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y1 = ((v->v1)->scrn).y + (shp->size_y / 2);
		ft_limit(shp, v, &((shp->pnt)->x2), &((shp->pnt)->y2));
	}
	else if (((v->v1)->w).z >= 0 && ((v->v2)->w).z < 0)
	{
		(shp->pnt)->x2 = ((v->v2)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y2 = ((v->v2)->scrn).y + (shp->size_y / 2);
		ft_limit(shp, v, &((shp->pnt)->x1), &((shp->pnt)->y1));
	}
	else if (((v->v1)->w).z >= 0 && ((v->v2)->w).z >= 0)
		return ;
	else
	{
		(shp->pnt)->x1 = ((v->v1)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y1 = ((v->v1)->scrn).y + (shp->size_y / 2);
		(shp->pnt)->x2 = ((v->v2)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y2 = ((v->v2)->scrn).y + (shp->size_y / 2);
	}
	ft_drawline(shp, shp->size_x, shp->size_x);
}

void	ft_transform(t_info *shp, t_verts *v)
{
	ft_worldcoords(v->v1, shp);
	ft_worldcoords(v->v2, shp);
	if (ft_project(v->v2) == 0 && 0 == ft_project(v->v1))
	{
		(shp->pnt)->x1 = ((v->v1)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y1 = ((v->v1)->scrn).y + (shp->size_y / 2);
		(shp->pnt)->x2 = ((v->v2)->scrn).x + (shp->size_x / 2);
		(shp->pnt)->y2 = ((v->v2)->scrn).y + (shp->size_y / 2);
		ft_draw_limit(shp, v);
		ft_drawline(shp, shp->size_x, shp->size_x);
	}
}
