/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorenev <skorenev@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:24:03 by skorenev          #+#    #+#             */
/*   Updated: 2026/04/21 19:24:04 by skorenev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

char					**ft_split(char const *s, char c);
char					**free_arr(int j, char **splited_words);
int						count_words(char const *s, char c);
int						*ft_atoi(const char *nptr);

typedef struct stack
{
	int					content;
	int					range;
	struct stack		*next;
}						t_stack;

typedef struct operation
{
	char				*content;
	struct operation	*next;
}						t_operation;

typedef struct stack_holder
{
	int					total;
	int					a_count;
	int					b_count;
	int					strategy;
	int					chosen_strategy;
	int					bench;
	float				disorder;
	t_stack				*a;
	t_stack				*b;
	t_operation			*operations;
}						t_stack_holder;
void					st_add_back(t_stack **lst, t_stack *new);
void					st_add_front(t_stack **lst, t_stack *new);
t_stack					*st_new(int content);
t_stack					*st_last(t_stack *lst);
void					st_clear(t_stack **lst);
t_stack					*st_pop_head(t_stack **stack);
t_stack					*st_pop_tail(t_stack **stack);
float					compute_disorder(t_stack *lst);
void					sa(t_stack_holder *holder);
void					sb(t_stack_holder *holder);
void					ss(t_stack_holder *holder);
void					pa(t_stack_holder *holder);
void					pb(t_stack_holder *holder);
void					ra(t_stack_holder *holder);
void					rb(t_stack_holder *holder);
void					rr(t_stack_holder *holder);
void					rra(t_stack_holder *holder);
void					rrb(t_stack_holder *holder);
void					rrr(t_stack_holder *holder);

t_stack_holder			*sort_two(t_stack_holder *holder);
t_stack_holder			*sort_three(t_stack_holder *holder);
t_stack_holder			*sort_five(t_stack_holder *holder);
int 					edge_casees_sort_check(t_stack_holder *holder);
void					find_rang(t_stack_holder *holder);

t_stack_holder			*bubble_sort(t_stack_holder *holder);
t_stack_holder			*chunk_sort(t_stack_holder *holder);
//==================== MERGE SORT =======================================
void					radix_sort(t_stack_holder *holder);
//=======================================================================
//==================== OPERATIONS =======================================
//=======================================================================
t_operation				*op_new(char *content);
void					op_clear(t_operation **lst);
void					op_add_back(t_operation **lst, t_operation *new);
int						get_op_count(t_operation *lst, char *op);
void					print_all_ops(t_stack_holder *holder);

//=======================================================================
//========================= ERROR =======================================
//=======================================================================
void					print_error(void);

//=======================================================================
//========================= TESTS =======================================
//=======================================================================

void					init_empty(t_stack_holder *holder);
t_stack_holder			*init_stack_holder(t_stack_holder *holder, int *args);
void					print_stack_holder(t_stack_holder *holder);
void					clear(t_stack_holder *holder);
void					sort(t_stack_holder *holder);
int						sort_check(t_stack_holder *holder);

//========================= INPUT =======================================
int						get_strategy(int argc, char *argv[]);
int						get_bench(int argc, char *argv[]);

int						validate_numbers_string(char *num_str);
int						*get_numbers(int argc, char *argv[],
							t_stack_holder *holder);
int						*parse_numbers(char **s_numbers, int size);
int						count_non_numeric_args(int argc, char *argv[]);
int						is_keyword(char *word);
int						is_bench(char *word);
int						is_strategy(char *word);
//========================= STRINGS =====================================
int						ft_strcmp(const char *s1, const char *s2);
int						validate_keywords(int non_num_count, int argc,
							char *argv[]);
int						check_uniq_keywords(int argc, char *argv[]);
//========================= BENCH ++=====================================
void					print_bench(t_stack_holder *holder);
void					print_disorder(float disorder);
int						ft_printf(int fd, const char *str, ...);

#endif