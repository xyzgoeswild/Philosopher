# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhsen- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 23:15:49 by amuhsen-          #+#    #+#              #
#    Updated: 2024/12/02 23:30:08 by amuhsen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= src/main.c src/utils src/actions \
	  	  src/initialize src/monitor src/threads

NAME		= philo

OBJ		= $(SRC:.c=.o)

CC		= cc

CFLAGS		= -Wall -Wextra -Werror -O3 -pthread

# FSANITIZE	= fsanitize=thread 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
