/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:56:37 by gyim              #+#    #+#             */
/*   Updated: 2022/11/25 20:30:09 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_tree(t_node *node)
{
	int	i;

	if (!node->op)
	{
		i = 0;
		while (node->tokens[i])
		{
			printf("%s ", node->tokens[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		print_tree(node->left);
		print_tree(node->right);
	}
}

int	main(int argc, char *argv[])
{
	t_node		*root;

	root = parse_tree(argv + 1);
	print_tree(root);
	return (0);
}
