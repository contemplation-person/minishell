/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_solo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:09:00 by juha              #+#    #+#             */
/*   Updated: 2023/01/13 14:18:17 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex2(t_cplist *cmd_pipe_list, t_fds *fds, \
			t_env_info_list *envp_list)
{
	t_pipe				p;
	t_using_pipe		channel;

	p.fds = fds;
	init(&p, &channel, cmd_pipe_list, envp_list);
	set_collabo(&p, p.envp);
	excute_redirection(&p, cmd_pipe_list);
	excute_cmd(cmd_pipe_list, envp_list);
	free_t_pipe(&p);
	return (0);
}
