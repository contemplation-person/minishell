/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/Piscine/C/C05/ex06/ft_is_prime.c
/*   Created: 2022/01/27 11:29:12 by juha              #+#    #+#             */
/*   Updated: 2022/01/27 18:01:49 by juha             ###   ########.fr       */
=======
/*   Created: 2022/12/12 14:32:51 by gyim              #+#    #+#             */
/*   Updated: 2022/12/28 13:39:13 by gyim             ###   ########seoul.kr  */
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:parser/search_tree.c
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

<<<<<<< HEAD:42/Piscine/C/C05/ex06/ft_is_prime.c
	i = 1;
	while (i <= (nb / 2))
	{
		if ((i * i) == nb)
			return (i);
		if ((i * i) > nb)
			return (i);
		i++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	long int	i;

	if (1 < nb)
	{
		i = 1;
		while (i < ft_sqrt(nb))
		{
			i++;
			if (nb % i == 0)
				return (0);
		}
		return (1);
=======
int	tree_valid_check(t_tree_node *node)
{
	if (node->op != NULL)
	{
		print_list(node->op);
		if (node->left == NULL || node->right == NULL)
		{
			write(2, "error near operator\n", 20);
			return (-1);
		}
		if (tree_valid_check(node->left) == -1)
			return (-1);
		if (tree_valid_check(node->right) == -1)
			return (-1);
	}
	return (0);
}

int	search_tree(t_tree_node *node, t_fds *fd_info, t_env_info_list *env_list)
{
	if (node->op != NULL)
	{
		if (ft_strncmp(node->op->token, "|", 2) == 0)
			op_pipe(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, "<", 2) == 0)
			op_infile(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, ">", 2) == 0)
			op_outfile(node, fd_info, env_list);
		else if (ft_strncmp(node->op->token, ">>", 2) == 0)
			op_append(node, fd_info, env_list);
		// else if (ft_strncmp(node->op->token, "<<", 3) == 0)
		// 	op_here_doc(node, fd_info, env_list);
		else
			return (-1);
	}
	else
	{
		print_list(node->words);
		excute_leaf(node->words, fd_info, env_list);
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:parser/search_tree.c
	}
	return (0);
}
