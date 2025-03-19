#### Variables ####
NAME = push_swap
CC = cc
FLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		ft_push.c \
		ft_swap.c \
		ft_rotate.c \
		ft_rev_rotate.c \
		ft_atoi.c \
		ft_exit.c \
		ft_split.c \
		node_utils.c \
		rotate_utils.c \
		short_sorts.c \
		ft_sort.c

OBJS = $(SRCS:.c=.o)

#### Rules ####
# Declares rules
.PHONY: all clean fclean re

# Compiles project
all: $(NAME)

# Compiles .o files into executable
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

# Compiles .c files into .o files
$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

# Cleans .o files
clean:
	rm -f $(OBJS)

# Cleans all generated files
fclean: clean
	rm -f $(NAME)

# Cleans all and recompiles project
re: fclean all
