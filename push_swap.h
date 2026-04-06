#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include "ft_printf.h"
# include <limits.h>

# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3
# define ADAPTIVE 4

void	print_error(void);
char	**ft_split(char const *s, char c);
int		count_words(char const *s, char c);
int		ft_atoi(const char *nptr);
int		*parse_numbers(char **s_numbers, int size);

typedef struct stack
{
	int		content;
	struct stack	*next;
}	t_stack;

typedef struct operation
{
	char *content;
	struct operation *next;
} t_operation;

typedef struct stack_holder
{
	int		total;
	int		a_count;
	int		b_count;
	t_stack	*a;
	t_stack	*b;
	t_operation *operations;
}	t_stack_holder;
void	st_add_back(t_stack **lst, t_stack *new);
void	st_add_front(t_stack **lst, t_stack *new);
t_stack	*st_new(int content);
t_stack	*st_last(t_stack *lst);
void	st_clear(t_stack **lst);
t_stack	*st_pop_head(t_stack **stack);
t_stack	*st_pop_tail(t_stack **stack);
void	sa(t_stack_holder *stack);
void	sb(t_stack_holder *stack);
void	ss(t_stack_holder *stack_holder);
void	pa(t_stack_holder *stack);
void	pb(t_stack_holder *stack);
void	ra(t_stack_holder *stack);
void	rb(t_stack_holder *stack);
void	rr(t_stack_holder *stack_holder);
void	rra(t_stack_holder *sh);
void	rrb(t_stack_holder *sh);
void	rrr(t_stack_holder *sh);

t_stack_holder	*bubble_sort(t_stack_holder *holder);
//=======================================================================
//==================== OPERATIONS =======================================
//=======================================================================
t_operation	*op_new(char *content);
void	op_clear(t_operation **lst);
void	op_add_back(t_operation **lst, t_operation *new);
int		get_op_count(t_operation *lst, char *op);

//=======================================================================
//========================= ERROR =======================================
//=======================================================================
int	error();

//=======================================================================
//========================= TESTS =======================================
//=======================================================================

t_stack_holder *init_stack_holder(t_stack_holder *sh, int *args, int count);
void	print_stack_holder(t_stack_holder *sh);
void test_sa(t_stack_holder	*stack);

//========================= INPUT =======================================
int	get_strategy(int argc, char *argv[]);
int	get_bench(int argc, char *argv[]);
//========================= STRINGS =====================================
int	strcmp(const char *s1, const char *s2);
//========================= BENCH ++=====================================
void print_bench(t_stack_holder *sh);

#endif