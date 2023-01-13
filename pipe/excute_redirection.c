/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:35 by juha              #+#    #+#             */
/*   Updated: 2023/01/13 15:44:51 by gyim             ###   ########seoul.kr  */
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

int	_set_open_flag(t_rnode *target_cmd)
{
	int		flag;

	flag = 0;
	if (target_cmd->redirection == MAKE_FILE)
		flag = O_WRONLY | O_CREAT | O_TRUNC;
	else if (target_cmd->redirection == ADD_FILE)
		flag = O_WRONLY | O_CREAT | O_APPEND;
	else if (target_cmd->redirection == INPUT_FILE)
	{
		flag = O_RDONLY;
		access(target_cmd->file, F_OK | R_OK);
		perror(target_cmd->file);
		g_error_code = 1;
		return (-1);

	}
	return (flag);
}

int	check_redirection_builtin(char **cmd)
{
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "echo", 5) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
		return (1);
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		return (1);
	else
		return (0);
}

void	is_redirection_dup2(int fd, int redirection, t_pipe *p, t_cplist *cp)
{
	int			check_error_code;
	int			i;
	char		*cmd;
	t_cplist	*temp;

	i = 0;
	temp = cp;
	while (i++ < p->operator_cmd)
		cp = cp->next;
	cmd = cp->cmd;
	check_error_code = 0;
	if (redirection == MAKE_FILE \
	|| redirection == ADD_FILE)
		check_error_code = dup2(fd, STDOUT_FILENO);
	else if (!check_redirection_builtin(&cmd))
		check_error_code = dup2(fd, STDIN_FILENO);
	if (check_error_code == -1)
	{
		close(fd);
		exit (check_error_code);
	}
	close(fd);
}

int	excute_redirection(t_pipe *p, t_cplist *cmd)
{
	t_rnode		*rd_node;
	int			fd;
	int			flag;

	rd_node = get_rd_node(p, cmd);
	if (!rd_node)
		return (TRUE);
	while (rd_node)
	{
		flag = _set_open_flag(rd_node);
		if (flag == -1)
		{
			rd_node = rd_node->next;
			return (FALSE);
		}
		if (rd_node->redirection != HEREDOC)
			fd = open(rd_node->file, flag, 0644);
		else
			fd = get_heredoc_fd(rd_node);
		is_redirection_dup2(fd, rd_node->redirection, p, cmd);
		rd_node = rd_node->next;
	}
	return (TRUE);
}
