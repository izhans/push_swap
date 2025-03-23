#### Variables ####
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

SRCS =	main.c \
		ft_push.c \
		ft_swap.c \
		ft_rotate.c \
		ft_rev_rotate.c \
		ft_atoi.c \
		ft_exit.c \
		node_utils.c \
		rotate_utils.c \
		assign_node_data_utils.c \
		find_utils.c \
		sorts.c

OBJS = $(SRCS:.c=.o)

#### Rules ####
# Declares rules
.PHONY: all clean fclean re

# Compiles project
all: $(NAME)

# Compiles .o files into executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compiles .c files into .o files
$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

# Compiles libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Cleans .o files
clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

# Cleans all generated files
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Cleans all and recompiles project
re: fclean all
