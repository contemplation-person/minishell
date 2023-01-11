/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:35 by juha              #+#    #+#             */
/*   Updated: 2023/01/11 17:54:09 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_rnode	*get_target_cmd(t_pipe *p, t_cplist *cmd)
{
	t_rnode		*ret;
	t_cplist	*cp;
	int			i;

	cp = cmd;
	ret = NULL;
	i = 0;
	while (i < p->operator_cmd)
	{
		cp = cp->next;
		i++;
	}
	ret = cp->rd_head;
}

char	*make_here_doc_file(void)
{
	int	heredoc_name;


/*
	check access
	if (exist)
		++i;
	a_to_i
*/
}

int	_set_open_flag(t_rnode *target_cmd)
{
	int	flag;

	if (target_cmd->redirection == MAKE_FILE)
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	else if (target_cmd->redirection == ADD_FILE)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else if (target_cmd->redirection == INPUT_FILE)
		flag = O_RDONLY;
	else if (target_cmd->redirection == HEREDOC)
	{
		target_cmd->file = make_here_doc_file();
		flag = O_RDWR | O_CREAT | O_EXCL;
	}
	return (flag);
}

void	is_redirection_dup2(int fd, int redirection)
{
	int	check;

	if (redirection == MAKE_FILE \
	|| redirection == ADD_FILE)
	{
		check = dup2(fd, STDOUT_FILENO);
		if (check == -1)
			exit (check);
	}
	else
	{
		check = dup2(fd, STDIN_FILENO);
		if (check == -1)
			exit (check);
	}
	close(fd);
}


void	excute_redirection(t_pipe *p, t_cplist *cmd)
{
	t_rnode		*target_cmd;
	int			fd;
	int			flag;

	target_cmd = get_target_cmd(p, cmd);
	while (target_cmd)
	{
		flag = _set_open_flag(target_cmd);
		if (target_cmd->redirection == MAKE_FILE \
			|| target_cmd->redirection == HEREDOC)
			fd = open(target_cmd->file, flag, 644);
		else
			fd = open(target_cmd->file, flag);
		is_redirection_dup2(fd, target_cmd->redirection);
		target_cmd = target_cmd->next;
	}
}