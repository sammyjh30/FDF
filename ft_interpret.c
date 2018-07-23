/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpret.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 07:02:16 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/16 07:02:22 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_advance(char **f, int i, int s)
{
	while (f[i][s] && f[i][s] != ' ')
		s++;
	return (s);
}

int		ft_isnum(char **f, int i, int s)
{
	if (f[i][s] == '+' || f[i][s] == '-')
		s++;
	if (ft_isdigit(f[i][s]))
		return (1);
	return (0);
}

int		ft_transfer(char **file, int i, char ***vals)
{
	int		j;
	int		s;

	j = 0;
	s = 0;
	while (file[i][s])
	{
		if (ft_isnum(file, i, s))
		{
			(*vals)[i][j] = ft_atoi(file[i] + s);
			s = ft_advance(file, i, s);
			j++;
		}
		else if (file[i][s] == ' ' || file[i][s] == '	')
			s++;
		else
			break ;
	}
	if (file[i][s])
		return (-1);
	return (0);
}

char	**ft_interpretfile(char **file, int lc)
{
	int		wc;
	int		i;
	int		j;
	int		s;
	char	**vals;

	i = -1;
	wc = ft_wrdcnt(file[0], ' ');
	if (!(vals = (char **)ft_memalloc(sizeof(char *) * lc)))
		return (NULL);
	while (++i < lc)
	{
		if (ft_wrdcnt(file[i], ' ') != wc)
		{
			ft_putendl("Invalid Grid");
			return (NULL);
		}
		vals[i] = (char *)ft_memalloc(sizeof(int) * wc + 1);
		j = 0;
		s = 0;
		if (ft_transfer(file, i, &vals) == -1)
			return (NULL);
	}
	return (vals);
}
