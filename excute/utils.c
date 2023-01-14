/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:27:17 by gyim              #+#    #+#             */
/*   Updated: 2023/01/14 16:37:29 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	free_cmd_pipe_list(t_cplist **cmd_pipe_lists)
{
	t_cplist	*curr;
	t_cplist	*next;

	curr = *cmd_pipe_lists;
	while (curr)
	{
		next = curr->next;
		free(curr->cmd);
		free_red(curr->rd_head);
		free(curr);
		curr = next;
	}
	*cmd_pipe_lists = NULL;
}

char	*merge_token(t_tnode *head)
{
	t_tnode	*curr;
	char	*ret;
	char	*temp1;
	char	*temp2;

	ret = ft_strdup(head->token);
	curr = head->next;
	while (curr)
	{
		if (curr->next && is_redirection(curr->token))
		{
			curr = curr->next->next;
			continue ;
		}
		temp1 = ft_strjoin(" ", curr->token);
		temp2 = ft_strjoin(ret, temp1);
		free(ret);
		free(temp1);
		ret = temp2;
		curr = curr->next;
	}
	return (ret);
}

void	print_error(char *cmd, char *msg)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, msg, ft_strlen(msg));
}

int	cmd_builtin_check1(char **cmd, t_env_info_list *envp_list)
{
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
	{
		builtin_cd(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
	{
		builtin_export(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
	{
		builtin_unset(envp_list, cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
	{
		g_error_code = builtin_exit(cmd);
		return (1);
	}
	else
		return (0);
}

int	cmd_builtin_check2(char **cmd, t_env_info_list *envp_list)
{
	if (ft_strncmp(cmd[0], "echo", 5) == 0)
	{
		echo(cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
	{
		builtin_pwd(cmd);
		return (1);
	}
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
	{
		builtin_env(envp_list, cmd);
		return (1);
	}
	else
		return (0);
}