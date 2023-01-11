/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:09:25 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 13:20:37 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

// int	pipe_excute_leaf(t_tnode *cmd_list, t_fds *fd_info,
// 	t_env_info_list *envp_list)
// {
// 	char	**cmd;
// 	t_rnode	*rd_head;
// 	int		pid;

// 	expansion(cmd_list, envp_list);
// 	retokenize(cmd_list);
// 	quote_remove(cmd_list);
// 	rd_head = get_redirection(cmd_list);
// 	cmd = get_cmd(cmd_list);
// 	if (set_fds(fd_info, rd_head, envp_list) == -1)
// 	{
// 		free_red(rd_head);
// 		free_cmd(cmd);
// 		return (-1);
// 	}
// 	if (cmd[0])
// 		pid = pipe_excute_cmd(cmd, fd_info, envp_list);
// 	else
// 		pid = -999;
// 	free_red(rd_head);
// 	free_cmd(cmd);
// 	return (pid);
// }


int	excute_cmd_pipe_list(t_cplist *cmd_pipe_lists, t_env_info_list *env_list)
{
	pipex_excute_cmd(cmd_pipe_lists, env_list);
	return (0);
}
