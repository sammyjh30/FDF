/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:34:45 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/16 07:34:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_abs(double n)
{
	if (n >= 0)
		return (n);
	else
		return ((-1) * n);
}

void	ft_draw(t_info *s, int size_x, int size_y, t_drawline *a)
{
	while (1)
	{
		if ((s->pnt)->x1 < 0 && (s->pnt)->x1 >= size_x)
		{
			if ((s->pnt)->y1 < 0 && (s->pnt)->y1 >= size_y)
				break ;
		}
		else
			mlx_pixel_put(s->mlx, s->win, (s->pnt)->x1, (s->pnt)->y1, s->clr);
		if ((s->pnt)->x1 == (s->pnt)->x2 && (s->pnt)->y1 == (s->pnt)->y2)
			break ;
		a->m = 2 * a->e;
		if (a->m >= a->dy)
		{
			a->e += a->dy;
			(s->pnt)->x1 += a->sx;
		}
		if (a->m <= a->dx)
		{
			a->e += a->dx;
			(s->pnt)->y1 += a->sy;
		}
	}
}

void	ft_drawline(t_info *s, int size_x, int size_y)
{
	t_drawline	*a;
	double		dx;
	double		dy;

	dx = ft_abs((s->pnt)->x2 - (s->pnt)->x1);
	dy = -(ft_abs((s->pnt)->y2 - (s->pnt)->y1));
	a = ft_setline(dx, dy);
	if ((s->pnt)->x1 >= (s->pnt)->x2)
		a->sx = -1;
	if ((s->pnt)->y1 >= (s->pnt)->y2)
		a->sy = -1;
	ft_draw(s, size_x, size_y, a);
}
