#### Variables ####
NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

# src
SRCS =	main.c \
		sorts.c
SRC_OBJ = $(SRCS:.c=.o)

# movs
MOVS_DIR = movs/
MOVS_SRC = \
		ft_push.c \
		ft_swap.c \
		ft_rotate.c \
		ft_rev_rotate.c
MOVS_OBJ = $(MOVS_SRC:.c=.o)

# utils
UTILS_DIR = utils/
UTILS_SRC = \
		ft_add_number_to_stack.c \
		ft_exit.c \
		stack_utils.c \
		rotate_utils.c \
		assign_node_data_utils.c \
		find_utils.c
UTILS_OBJ = $(UTILS_SRC:.c=.o)

OBJS = $(SRC_OBJ) $(addprefix $(MOVS_DIR), $(MOVS_OBJ)) $(addprefix $(UTILS_DIR), $(UTILS_OBJ))

#### Rules ####
# Declares rules
.PHONY: all clean fclean re

# Compiles project
all: $(NAME)

# Compiles .o files into executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compiles .c files into .o files
$(SRC_OBJ): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(MOVS_OBJ): $(addprefix $(MOVS_DIR), $(MOVS_OBJ))
	$(CC) $(CFLAGS) -c $(addprefix $(MOVS_DIR), $(MOVS_OBJ))

$(UTILS_OBJ): $(addprefix $(UTILS_DIR), $(UTILS_OBJ))
	$(CC) $(CFLAGS) -c $(addprefix $(UTILS_DIR), $(UTILS_OBJ))

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
