
NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

LIBFT_DIR = ./libft

LINK_LIBFT = -L ./libft -lft

SOURCES =	push_swap.c\
			change_string_into_argv_with_arguments.c\
			check_for_duplicates_in_string.c\
			check_for_empty_string.c\
			check_for_only_digits_and_sign_and_whitespace.c\
			check_for_overflow.c\
			check_if_single_argument.c\
			create_list_of_numbers.c\
			find_smallest_current_value.c\
			free_functions.c\
			is_it_sorted.c\
			push_commands.c\
			radix_sort.c\
			reverse_rotate_commands.c\
			rotate_commands.c\
			sort_a_list_of_4_to_6_nodes.c\
			sort_a_list_of_two_nodes.c\
			sort_list_of_three_nodes_stack_a.c\
			sort_list_of_three_nodes_stack_b.c\
			swap_commands.c\
			swap_top_two_numbers.c\
			utils_general.c\
			utils_stack.c\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	cc $(CFLAGS) $(SOURCES) -o $(NAME) $(LINK_LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re