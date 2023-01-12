/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:53:14 by gyim              #+#    #+#             */
/*   Updated: 2023/01/13 03:50:48 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"

int	check_redirection(t_rnode *head)
{
	t_rnode	*curr;

	curr = head;
	while (curr)
	{
		if (is_redirection(curr->file))
		{
			write(2, "unexpected token near \'", 23);
			write(2, curr->file, ft_strlen(curr->file));
			write(2, "'\n", 2);
			g_error_code = 2;
			return (-1);
		}
		curr = curr->next;
	}
	return (0);
}

void	free_rlist(t_rnode *head)
{
	t_rnode	*curr;
	t_rnode	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		if (curr->file)
			free(curr->file);
		free(curr);
		curr = next;
	}
}

int	renewal_fds(t_rnode *node, t_fds *fds, t_env_info_list *envp_list)
{
	if (node->redirection == MAKE_FILE)
		return (set_outfile(fds, node));
	else if (node->redirection == ADD_FILE)
		return (set_addfile(fds, node));
	else if (node->redirection == INPUT_FILE)
		return (set_infile(fds, node));
	else if (node->redirection == HEREDOC)
		return (set_here_doc(node, fds, envp_list));
	return (-1);
}

int	set_fds(t_fds *fds, t_rnode *node, t_env_info_list *envp_list)
{
	t_rnode	*curr;

	curr = node;
	while (curr)
	{
		if (renewal_fds(curr, fds, envp_list) == -1)
			return (-1);
		curr = curr->next;
	}
	return (0);
}

int	redirection(t_fds *fds, t_rnode *rd_head, t_env_info_list *envp_list)
{
	t_rnode	*curr;

	curr = rd_head;
	while (curr)
	{
		/*
			if (builtin && (<< || <)
				operate ignore
		*/
		if (rd_head->redirection == HEREDOC) // !builtin
			write(STDIN_FILENO, rd_head->file, ft_strlen(rd_head->file));
		else
			set_fds(fds, rd_head, envp_list);
		curr = curr->next;
	}
	return (0);
}
