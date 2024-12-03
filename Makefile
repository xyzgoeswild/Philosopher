# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhsen- <amuhsen-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 14:19:21 by druina            #+#    #+#              #
#    Updated: 2024/12/03 23:48:18 by amuhsen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c init.c threads.c monitor.c routine_actions.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror -O3 -pthread

HEADER = ./includes/philo.h

# SANITIZER = -fsanitize=thread

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug