# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhan <mohkhan@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 16:08:10 by mohkhan           #+#    #+#              #
#    Updated: 2024/11/18 16:08:12 by mohkhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
SRCS	=	main.c	atof.c burning_ship.c errors.c events.c fractol.c julia.c mandelbrot.c maths.c\
			libft_utils.c

OBJS            = $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address,undefined -O3
MLX_DIR         = mlx
MLX_LIB         = $(MLX_DIR)/libmlx.a
MLX_FLAGS       = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS) $(MLX_LIB)
				@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
				@echo "Fract_ol created"

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean
	@echo "cleaned"

fclean:			clean
				$(RM) $(NAME)
				@echo "fcleaned"

re:				fclean all

bonus:			all
				@echo "bonus created"

.PHONY:			all clean fclean re bonus
