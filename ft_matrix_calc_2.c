/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_calc_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 13:46:07 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/05 13:46:13 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_id_matrix(double **id_mtx)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				id_mtx[i][j] = 1;
			else
				id_mtx[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_trnsf_trans(double **m, double tx, double ty, double tz)
{
	m[3][0] = m[3][0] + tx;
	m[3][1] = m[3][1] + ty;
	m[3][2] = m[3][2] + tz;
}

void	ft_trnsf_scale(double **m, double sx, double sy, double sz)
{
	double	**s_matrix;
	double	**matrix_1;

	matrix_1 = ft_make_matrix(4);
	s_matrix = ft_make_matrix(4);
	ft_id_matrix(s_matrix);
	ft_id_matrix(matrix_1);
	s_matrix[0][0] = sx;
	s_matrix[1][1] = sy;
	s_matrix[2][2] = sz;
	ft_mult_matrix(m, s_matrix, matrix_1);
	ft_copy_matrix(m, matrix_1);
	ft_delmatrix(matrix_1, 4);
	ft_delmatrix(s_matrix, 4);
}

void	ft_trnsf_rot(double **m, double rx, double ry, double rz)
{
	double	**x_matrix;
	double	**y_matrix;
	double	**z_matrix;
	double	**matrix_1;
	double	**matrix_2;

	x_matrix = ft_rot_x(rx);
	y_matrix = ft_rot_y(ry);
	z_matrix = ft_rot_z(rz);
	matrix_1 = ft_make_matrix(4);
	matrix_2 = ft_make_matrix(4);
	ft_mult_matrix(m, y_matrix, matrix_1);
	ft_mult_matrix(matrix_1, z_matrix, matrix_2);
	ft_mult_matrix(matrix_2, x_matrix, m);
	ft_delmatrix(matrix_1, 4);
	ft_delmatrix(matrix_2, 4);
	ft_delmatrix(x_matrix, 4);
	ft_delmatrix(y_matrix, 4);
	ft_delmatrix(z_matrix, 4);
}
