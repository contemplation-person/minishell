/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:47:37 by juha              #+#    #+#             */
/*   Updated: 2022/11/26 17:13:44 by gyim             ###   ########seoul.kr  */
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
    if (!stack)
        return (NULL);
	ft_memset(stack, 0, sizeof(t_stack));
	return (stack);
}

static t_stack_node	*new_stack_node(char data)
{
	t_stack_node *node;

	node = malloc(sizeof(t_stack_node));
    if (node)
        return (NULL);
	ft_memset(node, 0, sizeof(t_stack_node));
    node->data = data;
    return (node);
}

t_stack *push(t_stack *stack, char data)
{
    t_stack_node *head;
    t_stack_node *new_node;

    new_node = new_stack_node(data);
    if (new_node)
        return (NULL);
    stack->cnt++;
    head = stack->head;
    head->prev = new_node;
    new_node->next = head;
    stack->head = new_node;
    return (stack);
}

t_stack_node    *pop(t_stack *stack)
{
    t_stack_node *pop_node;

    if (stack->cnt == 0)
        return (NULL);
    stack->cnt--;
    pop_node = stack->head;
    stack->head = pop_node->next;
    stack->head->prev = NULL;
    pop_node->next = NULL;
    return (pop_node);
}

void    display_stack(t_stack *stack)
{
    t_stack_node    *node;
    while (!(stack->cnt))
    {
        node = pop(stack);
        printf("%s", );
    }
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

int	delete_stack(t_linked_stack *stack)
{
	t_stack_node	*del_node;
	t_stack_node	*next;

	del_node = stack->head;
	while (del_node)
	{
		next = del_node->next;
		free(del_node);
		del_node = next;
	}
	free(stack);
	return (0);
}


int main()
{
}