/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 19:05:31 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_all_n_write(int fd, char **str, char **ret)
{
	write(fd, *ret, ft_strlen(*ret));
	free(*str);
	free(*ret);
}

void	write_child(t_rnode *rnode, char *exit_code)
{
	char	*str;
	int		fd;
	char	*ret;

	_set_signal(3);
	fd = open(rnode->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		str = readline("> ");
		if (!str)
		{
			unlink(rnode->file);
			rnode->file = NULL;
			break ;
		}
		if (!ft_strncmp(exit_code, str, ft_strlen(exit_code))
			&& ft_strlen(exit_code) == ft_strlen(str))
		{
			free(str);
			break ;
		}
		ret = ft_strjoin(str, "\n");
		free_all(str, ret);
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
	return (ret);
}

t_bool	fork_heredoc(t_rnode *rnode, char *exit_code)
{
	int			pid;
	int			status;
	char		*heredoc_name;

	heredoc_name = access_file();
	free(rnode->file);
	rnode->file = heredoc_name;
	pid = fork();
	if (pid == 0)
	{
		write_child(rnode, exit_code);
	}
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (status == SIGINT)
		{
			write(1, "\n", 1);
			unlink(rnode->file);
			free(rnode->file);
			rnode->file = NULL;
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
				if (fork_heredoc(rtemp, exit_code) == FALSE)
					return (free(exit_code), FALSE);
				free(exit_code);
			}
			rtemp = rtemp->next;
		}
		temp = temp->next;
	}
	return (TRUE);
}
