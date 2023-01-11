/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:09:25 by gyim              #+#    #+#             */
/*   Updated: 2023/01/11 21:18:28 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"


int	excute_cmd_pipe_list(t_cplist *cmd_pipe_lists, t_env_info_list *env_list)
{
	pipex(cmd_pipe_lists, env_list);
	return (0);
}
