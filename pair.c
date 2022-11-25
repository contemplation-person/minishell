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
t_linked_stack	*input_a_pair_stack(t_linked_stack *in_stack, char c)
{
	t_linked_stack	*stack;
	int				check;

	check = FALSE;
	stack = in_stack;
	if (!stack)
		stack = create_linked_stack();
	if (c == '(')
		check = push_linked_stack(stack, BACKTICK);
	else if (c == '[')
		check = push_linked_stack(stack, SQUARE_BRACKET);
	else if (c == '\"')
		check = push_linked_stack(stack, DOUBLE_SQUOTE);
	else if (c == '\'')
		check = push_linked_stack(stack, SINGLE_SQUOTE);
	if (check == FALSE)
		return (NULL);
	if (!(stack->cnt))
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

/*
	핵심!
	1. 스택이 비어있으면 false 반환,
	2. stack->cnt가 0이면 false반환.
	3. 오류 false 반환
	4. 정상 들어오면 pop후에 enum 반환,
*/
int	is_a_pair_stack(t_linked_stack *stack, char c)
{
	if (!stack)
		return (FALSE);
	if (stack->cnt == 0)
		return (FALSE);
	if (c == ')')
	{
		if (stack->head->data == BRACKET)
			return (pop_linked_stack(stack)->data);
	}
	else if (c == ']')
	{
		if (stack->head->data == SQUARE_BRACKET)
			return (pop_linked_stack(stack)->data);
	}
	else if (c == '\"')
	{
		if (stack->head->data == DOUBLE_SQUOTE)
			return (pop_linked_stack(stack)->data);
	}
	else if (c == '\'')
	{
		if (stack->head->data == SINGLE_SQUOTE)
			return (pop_linked_stack(stack)->data);
	}
	return (FALSE);
}

/*
	테스트중
*/
int	main()
{
	t_linked_stack	*stack;

	// check NULL
	stack = input_a_pair_stack(NULL, 'i');
	printf("stack = %p\n", stack);
	// check braket
	stack = input_a_pair_stack(NULL, '(');
	printf("stack = %p, %d\n", stack, stack->head->data);
	// check single
	stack = input_a_pair_stack(NULL, '\'');
	printf("stack = %p, %d\n", stack, stack->head->data);
	printf("is a pair%d\n", is_a_pair_stack(stack, '\'');
	printf("stack = %p, %d\n", stack, stack->head->data);

}