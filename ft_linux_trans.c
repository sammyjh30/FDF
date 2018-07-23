/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linux_trans.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:06:59 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/20 09:07:00 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_l_col(int k, t_info *shp)
{
	if (k == 57)
		shp->c--;
	else if (k == 48)
		shp->c++;
	if (ft_abs(shp->c % 4) == 0)
		shp->clr = WHITE;
	else if (ft_abs(shp->c % 4) == 1)
		shp->clr = RED;
	else if (ft_abs(shp->c % 4) == 2)
		shp->clr = GREEN;
	else if (ft_abs(shp->c % 4) == 3)
		shp->clr = BLUE;
}

void		ft_l_o_trans(int k, t_info *shp)
{
	if (k == 115)
		(shp->ot)->t.y += 5;
	else if (k == 119)
		(shp->ot)->t.y--;
	else if (k == 97)
		(shp->ot)->t.x--;
	else if (k == 100)
		(shp->ot)->t.x++;
	else if (k == 101)
		(shp->ot)->t.z++;
	else if (k == 113)
		(shp->ot)->t.z--;
}

void		ft_l_o_rot(int k, t_info *shp)
{
	if (k == 103)
		(shp->ot)->r.y += 0.1;
	else if (k == 104)
		(shp->ot)->r.y -= 0.1;
	else if (k == 98)
		(shp->ot)->r.x += 0.1;
	else if (k == 118)
		(shp->ot)->r.x -= 0.1;
	else if (k == 121)
		(shp->ot)->r.z -= 0.1;
	else if (k == 116)
		(shp->ot)->r.z += 0.1;
}

void		ft_l_o_scale(int k, t_info *shp)
{
	if (k == 105)
		(shp->ot)->s.y -= 0.1;
	else if (k == 111)
		(shp->ot)->s.y += 0.1;
	else if (k == 106)
		(shp->ot)->s.x -= 0.1;
	else if (k == 107)
		(shp->ot)->s.x += 0.1;
	else if (k == 110)
		(shp->ot)->s.z += 0.1;
	else if (k == 109)
		(shp->ot)->s.z -= 0.1;
}

void		ft_linux_key(int k, t_info *shp)
{
	if (k == 65307)
		exit(0);
	else if (k == 119 || k == 115 || k == 100)
		ft_l_o_trans(k, shp);
	else if (k == 97 || k == 113 || k == 101)
		ft_l_o_trans(k, shp);
	else if (k == 103 || k == 104 || k == 98)
		ft_l_o_rot(k, shp);
	else if (k == 118 || k == 121 || k == 116)
		ft_l_o_rot(k, shp);
	else if (k == 105 || k == 111 || k == 106)
		ft_l_o_scale(k, shp);
	else if (k == 107 || k == 110 || k == 109)
		ft_l_o_scale(k, shp);
	else if (k == 57 || k == 48)
		ft_l_col(k, shp);
	else if (k == 65289)
		ft_set_transforms(shp);
}
