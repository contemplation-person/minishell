/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:56:37 by gyim              #+#    #+#             */
/*   Updated: 2022/12/05 20:03:11 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tree(t_node *node)
{
	int	i;

	if (!node->op)
	{
		i = 0;
		while (node->token[i])
		{
			printf("%s ", node->token[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		print_tree(node->left);
		printf("operator : %d\n", node->op);
		print_tree(node->right);
	}
}

void	print_token(char **token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		printf("%s ", token[i]);
		i++;
	}
	printf("\n");
}

// int	main(int argc, char *argv[])
// {
// 	t_node		*root;

// 	root = make_tree(argv + 1);
// 	print_tree(root);
// 	return (0);
// }
