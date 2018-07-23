/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_initiation_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:04:17 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/20 09:04:20 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex	*ft_set_vertex(void)
{
	t_vertex *c;

	if (!(c = (t_vertex *)malloc(sizeof(t_vertex))))
		return (NULL);
	c->lcl = *ft_set_3d(0, 0, 0);
	c->w = *ft_set_3d(0, 0, 0);
	c->scrn = *ft_set_2d();
	return (c);
}

t_verts		*ft_set_verts(void)
{
	t_verts *c;

	if (!(c = (t_verts *)malloc(sizeof(t_verts))))
		return (NULL);
	c->v1 = ft_set_vertex();
	c->v2 = ft_set_vertex();
	return (c);
}

t_transf	*ft_set_transf(void)
{
	t_transf *c;

	if (!(c = (t_transf *)malloc(sizeof(t_transf))))
		return (NULL);
	c->t = *ft_set_3d(0, 0, 0);
	c->r = *ft_set_3d(0, 0, 0);
	c->s = *ft_set_3d(1, 1, 1);
	return (c);
}

t_info		*ft_set_info(int x, int y)
{
	t_info	*c;

	if (!(c = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	c->mlx = NULL;
	c->win = NULL;
	c->vals = NULL;
	c->file = NULL;
	c->lc = 0;
	c->wc = 0;
	c->size_x = x;
	c->size_y = y;
	c->c = 0;
	c->clr = WHITE;
	c->pnt = ft_set_point();
	if (!c->ot)
		c->ot = NULL;
	return (c);
}
