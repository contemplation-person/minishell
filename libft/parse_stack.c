/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:47:37 by juha              #+#    #+#             */
/*   Updated: 2022/11/25 18:59:43 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
	check_in_braket(char *str)
	{
		stack check;
		TRUE = 괄호를 스택에 넣어놓고 1 반환 
		FALSE = 에러 케이스 확인 후, 에러 케이스 반환)
	}
	check_out_braket(char *str)
	{
		TRUE = pop후 TRUE
		FALSE = 에러 케이스 확인 후 에러 케이스 반환;
	}
*/

t_stack	*create_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	ft_memset(stack, 0, sizeof(t_stack));
	return (stack);
}

t_stack_node	*new_stack(char data)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node));
	ft_memset(node, 0, sizeof(t_stack_node));
    node->data = data;
    return (node);
}

t_stack *push(t_stack *stack, t_stack_node *new_node)
{
    t_stack_node *head;

    stack->cnt++;
    head = stack->head;
    head->prev = new_node;
    new_node->next = head;
    stack->head = new_node;
    return (stack);
}

t_stack *pop(t_stack *stack)
{
    t_stack_node *head;

    stack->cnt++;
    head = stack->head;
    head->prev = new_node;
    new_node->next = head;
    stack->head = new_node;
    return (stack);
}

int	check_in_stack(t_node *node, char str)
{
	
	while (*str)
	{
		if (ft_strncmp(str, "", 1))
			push(&stack, te)
		str++;
	}
	/*
		문자에서 괄호가 있는지 판단
		static t_stack	stack;
		if (is_zero_in(stack.cnt))
	*/

}



int main()
{
}