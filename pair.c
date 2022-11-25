/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pair.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: juha <juha@student.42seoul.kr>			 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/25 14:47:37 by juha			  #+#	#+#			 */
/*   Updated: 2022/11/25 19:17:45 by juha			 ###   ########seoul.kr  */
/*																			*/
/* ************************************************************************** */

#include "parser.h"

t_stack_node	*pop_linked_stack(t_linked_stack*	stack)
{
	t_stack_node	*ret;

	if (!(stack->cnt))
		return (NULL);
	ret = stack->head;
	stack->head = ret->prev;
	stack->cnt--;
	return (ret);
}

int	push_linked_stack(t_linked_stack* stack, int data)
{
	t_stack_node	*next;
	t_stack_node	*temp_node;

	next = NULL;
	temp_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!temp_node)
		return (FALSE);
	ft_memset(temp_node, 0, sizeof(temp_node));
	temp_node->data = data;
	temp_node->prev = stack->head;
	stack->head = temp_node;
	stack->cnt++;
	return (TRUE);
}

t_linked_stack	*create_linked_stack(void)
{
	t_linked_stack	*new_stack;

	new_stack = (t_linked_stack *)malloc(sizeof(t_linked_stack));
	if (!new_stack)
		return (NULL);
	ft_memset(new_stack, 0, sizeof(t_linked_stack));
	return (new_stack);
}

/*
	핵심!
	1. 스택이 비어있고, 페어가 없으면 NULL 반환,
	2. 오류 NULL 반환
	3. 정상 들어오면 스택 반환.
*/
void	input_a_pair_stack(t_linked_stack **in_stack, char c)
{
	t_linked_stack	*stack;

	if (!in_stack)
		return ;
	stack = *in_stack;
	if (!stack)
		stack = create_linked_stack();
	if (c == '(')
		push_linked_stack(stack, BRACKET);
	else if (c == '[')
		push_linked_stack(stack, SQUARE_BRACKET);
	else if (c == '\"')
		push_linked_stack(stack, DOUBLE_SQUOTE);
	else if (c == '\'')
		push_linked_stack(stack, SINGLE_SQUOTE);
	else if (c == '`')
		push_linked_stack(stack, BACKTICK);
	*in_stack = stack;
	if (!(stack->cnt))
	{
		free(stack);
		*in_stack = NULL;
		return ;
	}
}

/*
	핵심!
	1. 스택이 비어있으면 false 반환,
	2. stack->cnt가 0이면 false반환.
	3. 오류 false 반환
	4. 정상 들어오면 pop후에 enum 반환,
*/

int	is_a_pair_stack(t_linked_stack **in_stack, char c)
{
	t_linked_stack	*stack;
	int				check;
	int				ret;

	check = FALSE;
	ret = FALSE;
	stack = *in_stack;
	if (!stack || !in_stack)
		return (FALSE);
	if (stack->cnt == 0)
		return (FALSE);
	if (c == ')')
		check = stack->head->data == BRACKET;
	else if (c == ']')
		check = stack->head->data == SQUARE_BRACKET;
	else if (c == '\"')
		check = stack->head->data == DOUBLE_SQUOTE;
	else if (c == '\'')
		check = stack->head->data == SINGLE_SQUOTE;
	else if (c == '`')
		check = stack->head->data == BACKTICK;
	if (check == TRUE)
		ret = pop_linked_stack(stack)->data;
	if (!stack->cnt)
		free(stack);
	return (ret);
}

/*
	테스트중
*/
int	main()
{
	static t_linked_stack	*stack;

	// check NULL
	input_a_pair_stack(NULL, 'i');
	printf("stack = %p\n", stack);
	// check stack == NULL
	input_a_pair_stack(NULL, '(');
	printf("stack = %p, %p\n", stack, stack);

	// good input
	input_a_pair_stack(&stack, '(');
	printf("stack = %p, %d, %d\n", stack, stack->cnt, stack->head->data);

	// good input 2
	input_a_pair_stack(&stack, '(');
	printf("stack = %p, %d, %d\n", stack, stack->cnt, stack->head->data);

	// good input 2
	input_a_pair_stack(&stack, '(');
	printf("stack = %p, %d, %d\n", stack, stack->cnt, stack->head->data);

	printf("stack = %p, %d, %d\n", stack, stack->cnt, is_a_pair_stack(&stack, ')'));
	printf("stack = %p, %d, %d\n", stack, stack->cnt, is_a_pair_stack(&stack, ')'));
	printf("stack = %p, %d, %d\n", stack, stack->cnt, is_a_pair_stack(&stack, ')'));
	printf("stack = %p, %d, %d\n", stack, stack->cnt, is_a_pair_stack(&stack, ')'));
	printf("stack = %p, %d, %d\n", stack, stack->cnt, is_a_pair_stack(&stack, ')'));

	//stack = input_a_pair_stack(NULL, '\'');
	//printf("stack = %p, %d\n", stack, stack->head->data);
	//printf("is a pair = %d\n", is_a_pair_stack(&stack, '\''));
	//printf("stack = %p, %d\n", stack, stack->cnt);
	//system("leaks a.out");

}