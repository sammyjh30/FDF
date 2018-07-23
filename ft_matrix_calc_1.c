/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calc_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 09:51:21 by shillebr          #+#    #+#             */
/*   Updated: 2018/06/26 10:46:25 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ft_make_matrix(int size)
{
	double	**ret;
	int		i;
	int		j;

	i = 0;
	if (!(ret = (double **)ft_memalloc(sizeof(double *) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(ret[i] = (double *)ft_memalloc(sizeof(double) * size)))
			return (NULL);
		while (j < size)
		{
			ret[i][j] = 0;
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_delmatrix(double **matrix, int size)
{
	int		i;
	double	**tmp;

	i = 0;
	while (i < size)
	{
		tmp = &matrix[i];
		ft_memdel((void **)tmp);
		i++;
	}
}

void	ft_copy_matrix(double **dest, double **src)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	ft_mult_matrix(double **mat1, double **mat2, double **dest)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = (mat1[i][0] * mat2[0][j]) +
						(mat1[i][1] * mat2[1][j]) +
						(mat1[i][2] * mat2[2][j]) +
						(mat1[i][3] * mat2[3][j]);
			j++;
		}
		i++;
	}
}

void	ft_vect_matrix_mult(t_3d *dest, t_3d *src, double **mat)
{
	dest->x = src->x * mat[0][0] +
			(src->y * mat[1][0]) +
			(src->z * mat[2][0]) +
			mat[3][0];
	dest->y = src->x * mat[0][1] +
			(src->y * mat[1][1]) +
			(src->z * mat[2][1]) +
			mat[3][1];
	dest->z = src->x * mat[0][2] +
			(src->y * mat[1][2]) +
			src->z * mat[2][2] +
			mat[3][2];
}
