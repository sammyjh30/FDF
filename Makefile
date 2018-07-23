# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shillebr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 12:00:34 by shillebr          #+#    #+#              #
#    Updated: 2018/07/06 12:30:26 by shillebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf

SRC =	main.c ft_make_grid.c \
		ft_matrix_calc_1.c ft_matrix_calc_2.c \
		ft_matrix_calc_3.c ft_drawline.c ft_interpret.c \
		ft_struct_initiation_1.c ft_struct_initiation_2.c \
		ft_extra.c ft_mac_trans.c ft_linux_trans.c ft_tranform.c

FLAGS = -Wall -Werror -Wextra  

OBJS = $(SRC:%.c=obj/%.o)

OBJDIR	= obj/

FT = libft/

LIBFT = $(addprefix $(FT),libft.a)

INCLUDE = -I /usr/X11/include -I libft/includes

LINK = -L /usr/X11/lib -L. $(LIBFT) -l mlx -framework OpenGL -framework AppKit

all: $(LIBFT) obj  $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C $(FT)

$(OBJDIR)%.o: %.c
	gcc $(FLAGS) $(INCLUDE)  -o $@ -c $<

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) $(INCLUDE) $(LINK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) clean
	make -C $(FT) fclean

re: fclean all
