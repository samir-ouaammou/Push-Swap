FILES = push_swap.c  push_swap_utils1.c  push_swap_utils2.c  push_swap_utils3.c  push_swap_utils4.c \
		push_swap_utils5.c	push_swap_utils6.c	push_swap_utils7.c

OBJS = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address 

NAME = push_swap

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
