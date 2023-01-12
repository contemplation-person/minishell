/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:35 by juha              #+#    #+#             */
/*   Updated: 2023/01/12 21:42:36 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_rnode	*get_rd_node(t_pipe *p, t_cplist *cmd)
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
	return (ret);
}

char	*make_here_doc_file(char *exit_code, t_fds *fds)
{
	char	*change_name;
	int		fd;
	char	*str;

	change_name = access_heredoc_name();
	fd = open(change_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//_set_signal()
	while (42)
	{
		write(2, "test1\n\n", 7);
		ft_putstr_fd("> ", fds->stdout_fd);
		str = get_next_line(fds->stdin_fd);
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code)))//todo cmp strlen
		{
			free(str);
			break ;
		}
		ft_putstr_fd(str, fd);
		free(str);
		write(1, "\n", 1);
	}
	//_set_signal();
	close(fd);
	return (change_name);
}

int	_set_open_flag(t_rnode *target_cmd, t_fds *fds)
{
	int		flag;
	char	*heredoc_exit_code;

	flag = 0;
	if (target_cmd->redirection == MAKE_FILE)
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	else if (target_cmd->redirection == ADD_FILE)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else if (target_cmd->redirection == INPUT_FILE)
		flag = O_RDONLY;
	else if (target_cmd->redirection == HEREDOC)
	{
		heredoc_exit_code = target_cmd->file;
		target_cmd->file = NULL;
		target_cmd->file = make_here_doc_file(heredoc_exit_code, fds);
		free(heredoc_exit_code);
		flag = O_RDONLY;
	}
	return (flag);
}

void	is_redirection_dup2(int fd, int redirection)
{
	int	check;

	if (redirection == MAKE_FILE \
	|| redirection == ADD_FILE)
		check = dup2(fd, STDOUT_FILENO);
	else
		check = dup2(fd, STDIN_FILENO);
	if (check == -1)
	{
		close(fd);
		exit (check);
	}
	close(fd);
}

void	excute_redirection(t_pipe *p, t_cplist *cmd)
{
	t_rnode		*rd_node;
	int			fd;
	int			flag;

	rd_node = get_rd_node(p, cmd);
	if (!rd_node)
		return ;
	while (rd_node)
	{
		flag = _set_open_flag(rd_node, p->fds);
		fd = open(rd_node->file, flag, 0644);
		is_redirection_dup2(fd, rd_node->redirection);
		if (rd_node->redirection == HEREDOC)
			unlink(rd_node->file);
		rd_node = rd_node->next;
	}
}