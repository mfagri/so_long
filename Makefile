# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/20 13:55:29 by mfagri            #+#    #+#              #
#    Updated: 2022/03/21 17:48:58 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror
CC = gcc
MLX = -lmlx -framework OpenGL -framework Appkit

SRC = mandatory/so_long.c\
		mandatory/ft_split.c \
		mandatory/ft_strjoin.c \
		mandatory/ft_strlcpy.c \
		mandatory/ft_strlen.c \
		mandatory/map_draw.c \
		mandatory/read_map.c\
		mandatory/so_long_utls1.c\
		mandatory/so_long_utls2.c\
		mandatory/take_keys.c\

SRCB = bonus/so_long_bonus.c\
		bonus/ft_split.c \
		bonus/ft_strjoin.c \
		bonus/ft_strlcpy.c \
		bonus/ft_strlen.c \
		bonus/map_draw_bonus.c \
		bonus/read_map_bonus.c\
		bonus/so_long_bonus_utls1.c\
		bonus/so_long_bonus_utls2.c\
		bonus/take_keys_bonus.c\
		bonus/mouve_enemy.c\
		bonus/mouves_in_win.c
	
INC = mandatory/so_long.h
INCB = bonus/so_long_bonus.h

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(MLX) $(SRC) -o $(NAME)

bonus: $(BONUS)

$(BONUS) : $(OBJB) $(INCB)
	$(CC) $(CFLAGS) $(MLX) $(SRCB) -o $(BONUS)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJB)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re: fclean all bonus
	