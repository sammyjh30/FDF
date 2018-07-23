/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:43:57 by shillebr          #+#    #+#             */
/*   Updated: 2018/07/13 11:23:13 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "os.h"
# include "get_next_line.h"
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

typedef struct		s_drawline
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				e;
	int				m;
}					t_drawline;

typedef struct		s_3d
{
	double			x;
	double			y;
	double			z;
}					t_3d;

typedef struct		s_2d
{
	int				x;
	int				y;
}					t_2d;

typedef struct		s_transf
{
	t_3d			t;
	t_3d			r;
	t_3d			s;
}					t_transf;

typedef struct		s_vertex
{
	t_3d			lcl;
	t_3d			w;
	t_2d			scrn;
}					t_vertex;

typedef struct		s_verts
{
	t_vertex		*v1;
	t_vertex		*v2;
}					t_verts;

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;

}					t_point;

typedef struct		s_info
{
	void			*mlx;
	void			*win;
	char			**vals;
	char			**file;
	int				lc;
	int				wc;
	int				size_x;
	int				size_y;
	int				c;
	int				clr;
	t_point			*pnt;
	t_transf		*ot;
}					t_info;

void				ft_print_key(void);
void				ft_set_transforms(t_info *shp);
void				ft_vect_calc(t_info *s, t_verts *v, int *x, int *y);
int					ft_limmult(double n);
void				ft_limit(t_info *s, t_verts *v, int *x, int *y);
void				ft_draw_limit(t_info *shp, t_verts *v);
void				ft_m_o_trans(int k, t_info *shp);
void				ft_m_o_rot(int k, t_info *shp);
void				ft_m_o_scale(int k, t_info *shp);
void				ft_m_col(int k, t_info *shp);
void				ft_l_col(int k, t_info *shp);
void				ft_l_o_trans(int k, t_info *shp);
void				ft_l_o_rot(int k, t_info *shp);
void				ft_l_o_scale(int k, t_info *shp);
void				ft_mac_key(int k, t_info *shp);
void				ft_linux_key(int k, t_info *shp);
int					ft_key_hook(int k, t_info *shp);
t_point				*ft_set_point(void);
t_drawline			*ft_setline(int dx, int dy);
t_3d				*ft_set_3d(int x, int y, int z);
t_2d				*ft_set_2d(void);
t_vertex			*ft_set_vertex(void);
t_verts				*ft_set_verts(void);
t_transf			*ft_set_transf(void);
t_info				*ft_set_info(int x, int y);
void				ft_make_cube(t_info *shp, t_vertex *vert1, t_vertex *vert2);
void				ft_print_matrix(double **mat);
void				ft_assign_coords(t_info *s, t_verts *v, int i, int j);
double				ft_pow(double a, double b);
double				ft_abs(double n);
void				ft_draw(t_info *s, int size_x, int size_y, t_drawline *a);
void				ft_drawline(t_info *s, int size_x, int size_y);
double				**ft_rot_x(double rx);
double				**ft_rot_y(double ry);
double				**ft_rot_z(double rz);
void				ft_id_matrix(double **id_mtx);
void				ft_trnsf_trans(double **m, double tx, double ty, double tz);
void				ft_trnsf_scale(double **m, double sx, double sy, double sz);
void				ft_trnsf_rot(double **m, double rx, double ry, double rz);
double				**ft_make_matrix(int size);
void				ft_delmatrix(double **matrix, int size);
void				ft_copy_matrix(double **dest, double **src);
void				ft_mult_matrix(double **mat1, double **mat2, double **dest);
void				ft_vect_matrix_mult(t_3d *dest, t_3d *src, double **mat);
void				ft_worldcoords(t_vertex *vert, t_info *shp);
int					ft_project(t_vertex *v);
void				ft_transform(t_info *shp, t_verts *v);
int					ft_mapsetup(t_info *shp);
int					ft_advance(char **f, int i, int s);
int					ft_isnum(char **f, int i, int s);
int					ft_transfer(char **file, int i, char ***vals);
char				**ft_interpretfile(char **file, int lc);
void				ft_arradd(char ***file, char *line, int	size);
int					ft_readfile(char ***f, char *av);
void				ft_check_transforms(t_info *shp);

#endif
