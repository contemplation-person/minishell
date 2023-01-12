/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:35 by juha              #+#    #+#             */
/*   Updated: 2023/01/12 18:34:24 by gyim             ###   ########seoul.kr  */
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

char	*make_here_doc_file(char *exit_code)
{
	int		heredoc_name;
	char	*change_name;
	int		fd;
	char	*str;

	change_name = NULL;
	heredoc_name = 0;
	change_name = ft_itoa(heredoc_name);
	while (access(change_name, F_OK))
	{
		if (change_name)
			free(change_name);
		++heredoc_name;
		change_name = ft_itoa(heredoc_name);
		if (!change_name)
			exit(1);
	}
	fd = open(change_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (42)
	{
		write(2, "> ", 2);
		str = get_next_line(STDIN_FILENO);
		if (ft_strncmp(exit_code, str, ft_strlen(exit_code) + 1))
		{
			free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		free(str);
	}
	close(fd);
	return (change_name);
}

int	_set_open_flag(t_rnode *target_cmd)
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
		target_cmd->file = make_here_doc_file(heredoc_exit_code);
		free(heredoc_exit_code);
		flag = O_RDONLY | O_CREAT | O_EXCL;
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
	while (rd_node) // todo: replace here with rdnode* next
	{
		flag = _set_open_flag(rd_node);
		fd = open(rd_node->file, flag, 0644);
		is_redirection_dup2(fd, rd_node->redirection);
		if (rd_node->redirection == HEREDOC)
			unlink(rd_node->file);
		rd_node = rd_node->next;
	}
}