NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_split.c \
      ft_printf.c print.c \
      op_p.c op_r.c op_rr.c op_s.c \
      push_swap.c \
      stack_functions.c stack_functions2.c stack_holder_functions.c \
      bubble_sort.c chunk_sort.c \
	  edge_cases_sort.c sort_util.c \
      operations.c args.c \
      parse_numbers.c  print_bench.c \
      util.c radix_sort.c keywords.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus