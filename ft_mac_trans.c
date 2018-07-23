/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mac_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 09:06:50 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/20 09:06:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_m_o_trans(int k, t_info *shp)
{
	if (k == 13)
		(shp->ot)->t.y -= 5;
	else if (k == 1)
		(shp->ot)->t.y += 5;
	else if (k == 0)
		(shp->ot)->t.x -= 5;
	else if (k == 2)
		(shp->ot)->t.x += 5;
	else if (k == 14)
		(shp->ot)->t.z += 5;
	else if (k == 12)
		(shp->ot)->t.z -= 5;
}

void	ft_m_o_rot(int k, t_info *shp)
{
	if (k == 5)
		(shp->ot)->r.y += 0.1;
	else if (k == 4)
		(shp->ot)->r.y -= 0.1;
	else if (k == 11)
		(shp->ot)->r.x += 0.1;
	else if (k == 9)
		(shp->ot)->r.x -= 0.1;
	else if (k == 17)
		(shp->ot)->r.z += 0.1;
	else if (k == 16)
		(shp->ot)->r.z -= 0.1;
}

void	ft_m_o_scale(int k, t_info *shp)
{
	if (k == 31)
		(shp->ot)->s.y += 0.1;
	else if (k == 34)
		(shp->ot)->s.y -= 0.1;
	else if (k == 40)
		(shp->ot)->s.x += 0.1;
	else if (k == 38)
		(shp->ot)->s.x -= 0.1;
	else if (k == 45)
		(shp->ot)->s.z += 0.1;
	else if (k == 46)
		(shp->ot)->s.z -= 0.1;
}

void	ft_m_col(int k, t_info *shp)
{
	if (k == 25)
		shp->c--;
	else if (k == 29)
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

void	ft_mac_key(int k, t_info *shp)
{
	if (k == 53)
		exit(0);
	else if (k == 13 || k == 1 || k == 2 || k == 0 || k == 12 || k == 14)
		ft_m_o_trans(k, shp);
	else if (k == 4 || k == 5 || k == 11 || k == 9 || k == 16 || k == 17)
		ft_m_o_rot(k, shp);
	else if (k == 34 || k == 31 || k == 38 || k == 40 || k == 45 || k == 46)
		ft_m_o_scale(k, shp);
	else if (k == 25 || k == 29)
		ft_m_col(k, shp);
	else if (k == 48)
		ft_set_transforms(shp);
}
