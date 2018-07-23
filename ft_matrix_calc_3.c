/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_calc_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:46:17 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/05 13:46:20 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ft_rot_x(double rx)
{
	double	**x_matrix;

	if ((x_matrix = ft_make_matrix(4)))
	{
		ft_id_matrix(x_matrix);
		x_matrix[1][1] = (double)cos(rx * M_PI);
		x_matrix[1][2] = (double)-sin(rx * M_PI);
		x_matrix[2][1] = (double)sin(rx * M_PI);
		x_matrix[2][2] = (double)cos(rx * M_PI);
	}
	return (x_matrix);
}

double	**ft_rot_y(double ry)
{
	double	**y_matrix;

	if ((y_matrix = ft_make_matrix(4)))
	{
		ft_id_matrix(y_matrix);
		y_matrix[0][0] = (double)cos(ry * M_PI);
		y_matrix[0][2] = (double)sin(ry * M_PI);
		y_matrix[2][0] = (double)-sin(ry * M_PI);
		y_matrix[2][2] = (double)cos(ry * M_PI);
	}
	return (y_matrix);
}

double	**ft_rot_z(double rz)
{
	double	**z_matrix;

	if ((z_matrix = ft_make_matrix(4)))
	{
		ft_id_matrix(z_matrix);
		z_matrix[0][0] = (double)cos(rz * M_PI);
		z_matrix[0][1] = (double)-sin(rz * M_PI);
		z_matrix[1][0] = (double)sin(rz * M_PI);
		z_matrix[1][1] = (double)cos(rz * M_PI);
	}
	return (z_matrix);
}
