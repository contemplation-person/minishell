/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/13 03:29:14 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	read_child_proccess(int *pipe_fd, char *exit_code)
{
	char	*exit_code;
	char	*str;

	close(pipe_fd[READ]);
	str = NULL;
	while (42)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		str = ft_strdup(get_next_line(STDIN_FILENO));
		write(pipe_fd[WRITE], str, ft_strlen(str));
		free(str);
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
			&& ft_strlen(exit_code) == ft_strlen(str) - 1)
		{
			str = ft_strdup("");
			write(pipe_fd[WRITE], str, ft_strlen(str));
			free(str);
			break ;
		}
	}
	exit(0);
}

char	*read_heredoc_fork(char *exit_code)
{
	int		pipe_fd[2];
	int		pid;
	char	*ret;

	pipe(pipe_fd);
	pid = fork();
	if (pid > 0)
	{
		close(pipe_fd[WRITE]);
		ret = get_next_line(pipe_fd[READ]);
		while (ret)
		{
			smart_join(&ret, get_next_line(pipe_fd[READ]));
		}
	}
	else
	{
		write_child_proccess(pipe_fd, exit_code);
	}
	close(pipe_fd[READ]);
	return (ret);
}


void	read_heredoc(t_rnode *rtemp)
{
	char	*exit_code;
	char	*str;

	if (rtemp->redirection == HEREDOC)
	{
		exit_code = rtemp->file;
		_set_signal(0);
		rtemp->file = read_heredoc_fork(exit_code);
		/*
			여기 부모 자식 확인.
		*/


	//	rtemp->file = ft_strdup("");
	//	while (42)
	//	{
	//		read_parent(exit_code);
	//		ft_putstr_fd("> ", STDOUT_FILENO);
	//		str = get_next_line(STDIN_FILENO);
	//		//if (str == NULL) //  시그널 처리부분.
	//		//	break ;
	//		//if (*str == '\0') // 의문.시그널인듯.
	//		//{
	//		//	free(str);
	//		//	break ;
	//		//}
	//		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
	//			&& ft_strlen(exit_code) == ft_strlen(str) - 1)
	//		{
	//			free(str);
	//			str = ft_strdup("");
	//			smart_join(&(rtemp->file), str);
	//			free(str);
	//			break ;
	//		}
	//		smart_join(&(rtemp->file), str);
	//		free(str);
	//	}
		free(exit_code);
	}
}

void	create_heredoc(t_cplist *cplist)
{
	t_cplist	*temp;
	t_rnode		*rtemp;

	temp = cplist;
	while (temp)
	{
		rtemp = temp->rd_head;
		while (rtemp)
		{
			read_heredoc(rtemp);
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
