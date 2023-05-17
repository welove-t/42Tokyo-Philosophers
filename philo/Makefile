# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: terabu <terabu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 10:18:31 by terabu            #+#    #+#              #
#    Updated: 2023/05/17 12:07:04 by terabu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
DEBUG_FLAG = -fsanitize=thread
SRCS =	main.c \
		print.c \
		set_args.c \
		init.c \
		do.c \
		fork.c \
		philo_thread.c \
		timer.c


OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INC = -I include

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

debug: CFLAGS += $(DEBUG_FLAG)
debug: re

re: fclean all

.PHONY: all clean fclean re debug
