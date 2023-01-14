/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:02:45 by gyim              #+#    #+#             */
/*   Updated: 2023/01/12 11:06:55 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	reset_fds(t_fds *fds)
{
	fds->in_fd = dup(fds->stdin_fd);
	fds->out_fd = dup(fds->stdout_fd);
}

void	init_fds(t_fds *fds)
{
	dup2(fds->in_fd, STDIN_FILENO);
	dup2(fds->out_fd, STDOUT_FILENO);
	close(fds->in_fd);
	close(fds->out_fd);
}
