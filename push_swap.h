#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include "ft_printf.h"

void	print_error(void);
int		ft_atoi(const char *nptr);

typedef struct stack
{
	int		content;
	struct stack	*next;
}	t_stack;

typedef struct stack_holder
{
	int		total;
	int		a_count;
	int		b_count;
	t_stack	*a;
	t_stack	*b;
	char	**operations;
}	t_stack_holder;
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst);
t_stack *pop_head(t_stack **stack);
void	sa(t_stack_holder *stack);
void	sb(t_stack_holder *stack);
void	pa(t_stack_holder *stack);
void	pb(t_stack_holder *stack);
void	ra(t_stack_holder *stack);
void	rb(t_stack_holder *stack);

//=======================================================================
//========================= TESTS =======================================
//=======================================================================

t_stack_holder *init_stack_holder(t_stack_holder *sh, int *args, int count);
void	print_stack_holder(t_stack_holder *sh);
void	test_sa();


#endif