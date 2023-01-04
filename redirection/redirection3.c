/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:53:14 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 17:01:13 by gyim             ###   ########seoul.kr  */
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
		free(curr->file);
		free(curr);
		curr = next;
	}
}