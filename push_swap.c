/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:24:17 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:24:18 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Selects a sorting algorithm based on input disorder.
 *
 * Chooses an algorithm depending on the disorder percentage:
 * - < 20%  → SIMPLE
 * - >= 50% → COMPLEX
 * - otherwise → MEDIUM
 * @param disorder Percentage of disorder in the input dataset.
 * @return Selected algorithm identifier.
 */
int	choose_algorithm(int disorder)
{
	if (disorder < 20)
		return (SIMPLE);
	if (disorder >= 50)
		return (COMPLEX);
	return (MEDIUM);
}

/**
 * @brief Frees all allocated resources and exits the program.
 *
 * Clears the stack holder and optionally prints an error message
 * before exiting.
 * @param sh          Pointer to stack holder to be cleared.
 * @param throw_error If non-zero, prints an error message before exit.
 * @return Always returns 0.
 */
static int	clear_and_exit(t_stack_holder *sh, int throw_error)
{
	if (throw_error)
		print_error();
	clear(sh);
	return (0);
}

/**
 * @brief Validates program arguments.
 *
 * Ensures that at least one argument is provided to the program.
 * @param argc Number of command-line arguments.
 * @return 1 if valid, 0 otherwise.
 */
static int	check_args(int argc)
{
	if (argc <= 1)
		return (0);
	return (1);
}

/**
 * @brief Executes sorting logic on the stack holder.
 *
 * Selects the appropriate sorting strategy based on input size,
 * disorder level, and configuration. Executes the sorting algorithm
 * and optionally prints benchmark information.
 * @param holder Pointer to stack holder containing all sorting data.
 */
void	sort(t_stack_holder *holder)
{
	if (holder->a_count == 1 || sort_check(holder))
		return ;
	if (holder->strategy == ADAPTIVE)
		holder->chosen_strategy = choose_algorithm(holder->disorder);
	else
		holder->chosen_strategy = holder->strategy;
	if (holder->chosen_strategy == SIMPLE)
		bubble_sort(holder);
	else if (holder->chosen_strategy == MEDIUM)
		chunk_sort(holder);
	else
		radix_sort(holder);
	print_all_ops(holder);
	if (holder->bench)
		print_bench(holder);
}

/**
 * @brief Program entry point for push_swap.
 *
 * Parses input arguments, initializes the stack holder, selects the
 * strategy and benchmark mode, executes sorting, and performs cleanup
 * before exit.
 * @param argc Number of command-line arguments.
 * @param argv Argument vector.
 * @return Exit status (0 on success, non-zero on error).
 */
int	main(int argc, char *argv[])
{
	t_stack_holder	*holder;
	int				*numbers;

	holder = (t_stack_holder *)malloc(sizeof(t_stack_holder));
	init_empty(holder);
	if (!holder)
		return (clear_and_exit(holder, 1));
	if (!check_args(argc))
		return (clear_and_exit(holder, 0));
	numbers = get_numbers(argc, argv, holder);
	if (!numbers)
	{
		return (clear_and_exit(holder, 1));
	}
	init_stack_holder(holder, numbers);
	free(numbers);
	holder->strategy = get_strategy(argc, argv);
	holder->bench = get_bench(argc, argv);
	sort(holder);
	return (clear_and_exit(holder, 0));
}
