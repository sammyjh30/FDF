/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:34:37 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/16 07:34:39 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_matrix(double **mat)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

double	ft_pow(double a, double b)
{
	double	c;
	int		i;

	i = 0;
	c = 1;
	while (i < b)
	{
		c *= a;
		i++;
	}
	return (c);
}

void	ft_print_key(void)
{
	ft_putendl("_________________________\n|          KEY          |");
	ft_putendl("| translate x+   =   D  |\n| translate x-   =   A  |");
	ft_putendl("| translate y+   =   W  |\n| translate y-   =   S  |");
	ft_putendl("| translate z+   =   E  |\n| translate z-   =   Q  |");
	ft_putendl("|                       |");
	ft_putendl("| rotate    x+   =   B  |\n| rotate    x-   =   V  |");
	ft_putendl("| rotate    y+   =   H  |\n| rotate    y-   =   G  |");
	ft_putendl("| rotate    z+   =   Y  |");
	ft_putendl("| rotate    z-   =   T  |");
	ft_putendl("|                       |");
	ft_putendl("| scale     x+   =   K  |");
	ft_putendl("| scale     x-   =   J  |");
	ft_putendl("| scale     y+   =   O  |");
	ft_putendl("| scale     y-   =   I  |");
	ft_putendl("| scale     z+   =   N  |");
	ft_putendl("| scale     z-   =   M  |");
	ft_putendl("|                       |");
	ft_putendl("| colour     +  =    0  |");
	ft_putendl("| colour     -  =    9  |");
	ft_putendl("|                       |");
	ft_putendl("| reset         =   TAB |\n|_______________________|");
}

int		ft_key_hook(int k, t_info *shp)
{
	if (!shp)
		return (0);
	if (OS == 1)
		ft_linux_key(k, shp);
	else
		ft_mac_key(k, shp);
	return (0);
}
