/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/15 11:54:27 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_heredoc(t_rnode *rnode, char *exit_code)
{
	char		*str;

	_set_signal(3); // <- 자식시그널 - 자식 동작 : read 루프를 돌아 부모에게 heredoc 전달
	while (42)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		str = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
			&& ft_strlen(exit_code) == ft_strlen(str) - 1)
		{
			free(str);
			str = ft_strdup("");
			smart_join(&(rnode->file), str);
			free(str);
			break ;
		}
		smart_join(&(rnode->file), str);
		free(str);
	}
}

void	create_heredoc(t_cplist *cplist)
{
	t_cplist	*temp;
	t_rnode		*rtemp;
	char		*exit_code;

	temp = cplist;
//  시그널 확인해~!!!~@!~#@!@#$%##!@~#$%^&*&%#$@!$@%^&$#@!$%^&
	while (temp)
	{
		rtemp = temp->rd_head;
		while (rtemp)
		{
			if (rtemp->redirection == HEREDOC)
			{
				exit_code = rtemp->file;
				rtemp->file = ft_strdup("");
				_set_signal(0); // <- 부모 시그널 - 부모 동작 : 부모에서만 heredoc을 gnl로 받음
				fork_heredoc(rtemp, exit_code);

				free(exit_code);
				_set_signal(0);
			}
			rtemp = rtemp->next;
		}
		temp = temp->next;
	}
}

int	get_heredoc_fd(t_rnode *rd)
{
	int	fd[2];

	pipe(fd);
	write(fd[WRITE], rd->file, ft_strlen(rd->file));
	close(fd[WRITE]);
	return (fd[READ]);
}
