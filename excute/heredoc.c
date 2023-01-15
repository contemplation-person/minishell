/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/16 03:36:01 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_child(t_rnode *rnode, char *exit_code)
{
	char	*str;
	int		fd;

	_set_signal(3); // <- 자식시그널 - 자식 동작 : read 루프를 돌아 부모에게 heredoc 전달
	fd = open(rnode->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (42)
	{
		str = readline("> ");
		if (!str)
			break ;
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
			&& ft_strlen(exit_code) == ft_strlen(str))
		{
			break ;
		}
		write(fd, str, ft_strlen(str));
		free(str);
	}
	exit(g_error_code);
}

static char	*access_file()
{
	int		i;
	int		flag;
	char	*ret;

	i = 0;
	flag = 0;
	while (!flag)
	{
		ret = ft_itoa(i++);
		flag = access(ret, F_OK);
		if (flag)
			break ;
		free(ret);
	}
	return (ret);
}

void	fork_heredoc(t_rnode *rnode, char *exit_code)
{
	int			pid;
	int			status;

	rnode->file = access_file();
	pid = fork();
	if (pid == 0)
		write_child(rnode, exit_code);
	waitpid(pid, &status, 0);
	if(WIFSIGNALED(status) ) {
		if (status == SIGINT) // signal
		{
			write(STDOUT_FILENO, "adsfg\n", 6);
		}
	} else {
		if (WEXITSTATUS(status) == EXIT_FAILURE ) // exit code
		{
			// fail code.
		}
	}
}

void	create_heredoc(t_cplist *cplist)
{
	t_cplist	*temp;
	t_rnode		*rtemp;
	char		*exit_code;

	temp = cplist;
//  시그널 확인해~!!!~@!~#@!@#$%##!@~#$%^&*&%#$@!$@%^&$#@!$%^&
	//_set_signal(0);
	_set_signal(0);
	while (temp)
	{
		rtemp = temp->rd_head;
		while (rtemp)
		{
			if (rtemp->redirection == HEREDOC)
			{
				exit_code = rtemp->file;
				rtemp->file = ft_strdup("");
				fork_heredoc(rtemp, exit_code);
				free(exit_code);
			}
			rtemp = rtemp->next;
		}
		temp = temp->next;
	}
}

//int	get_heredoc_fd(t_rnode *rd)
//{
//	int	fd[2];

//	pipe(fd);
//	write(fd[WRITE], rd->file, ft_strlen(rd->file));
//	close(fd[WRITE]);
//	return (fd[READ]);
//}
