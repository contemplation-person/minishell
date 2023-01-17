/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 14:45:23 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	write_child(t_rnode *rnode, char *exit_code)
{
	char	*str;
	int		fd;
	char	*ret;

	_set_signal(3); // <- 자식시그널 - 자식 동작 : read 루프를 돌아 부모에게 heredoc 전달
	fd = open(rnode->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		str = readline("> ");
		if (!str)
			break ;
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
			&& ft_strlen(exit_code) == ft_strlen(str))
			break ;
		ret = ft_strjoin(str, "\n");
		write(fd, ret, ft_strlen(ret));
		free(str);
		free(ret);
	}
	exit(g_error_code);
}

static char	*access_file(void)
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
	printf("%s\n", ret);
	return (ret);
}

t_bool	fork_heredoc(t_rnode *rnode, char *exit_code)
{
	int			pid;
	int			status;

	rnode->file = access_file();
	pid = fork();
	if (pid == 0)
		write_child(rnode, exit_code);
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (status == SIGINT) // signal
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	create_heredoc(t_cplist *cplist)
{
	t_cplist	*temp;
	t_rnode		*rtemp;
	char		*exit_code;

	temp = cplist;
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
	return (TRUE); // 성공하면 실행, 실패하면 모든 노드 프리 후... 프롬프트 시작.
}

//int	get_heredoc_fd(t_rnode *rd)
//{
//	int	fd[2];

//	pipe(fd);
//	write(fd[WRITE], rd->file, ft_strlen(rd->file));
//	close(fd[WRITE]);
//	return (fd[READ]);
//}
