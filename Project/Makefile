# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaammo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 10:07:55 by souaammo          #+#    #+#              #
#    Updated: 2025/01/07 10:07:57 by souaammo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = push_swap.c  push_swap_utils0.c  push_swap_utils1.c  push_swap_utils2.c \
		push_swap_utils3.c	push_swap_utils4.c	push_swap_utils5.c push_swap_utils6.c \
		push_swap_utils7.c	push_swap_utils8.c	push_swap_utils9.c

BFILES = push_swap_bonus.c  push_swap_utils0.c  push_swap_utils1.c  push_swap_utils2.c \
		push_swap_utils3.c	push_swap_utils4.c	push_swap_utils5.c push_swap_utils6.c \
		push_swap_utils7.c	push_swap_utils8.c	push_swap_utils9.c	get_next_line.c	get_next_line_utils.c

OBJS = $(FILES:.c=.o)

BOBJS = $(BFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address 

NAME = push_swap

BNAME = checker

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -o $(BNAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all

