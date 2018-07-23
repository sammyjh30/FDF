/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 07:14:24 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/11 07:14:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*ft_set_point(void)
{
	t_point	*c;

	if (!(c = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	c->x1 = 0;
	c->y1 = 0;
	c->x2 = 0;
	c->y2 = 0;
	return (c);
}

t_drawline	*ft_setline(int dx, int dy)
{
	t_drawline	*c;

	if (!(c = (t_drawline *)malloc(sizeof(t_drawline))))
		return (NULL);
	c->dx = dx;
	c->dy = dy;
	c->sx = 1;
	c->sy = 1;
	c->e = dx + dy;
	c->m = 0;
	return (c);
}

t_3d		*ft_set_3d(int x, int y, int z)
{
	t_3d *c;

	if (!(c = (t_3d *)malloc(sizeof(t_3d))))
		return (NULL);
	c->x = x;
	c->y = y;
	c->z = z;
	return (c);
}

t_2d		*ft_set_2d(void)
{
	t_2d *c;

	if (!(c = (t_2d *)malloc(sizeof(t_2d))))
		return (NULL);
	c->x = 0;
	c->y = 0;
	return (c);
}
