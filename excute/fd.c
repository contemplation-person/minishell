/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:02:45 by gyim              #+#    #+#             */
/*   Updated: 2023/01/17 16:29:39 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "excute.h"

void	reset_fds(t_fds *fds)
{
	fds->in_fd = dup(fds->stdin_fd);
	fds->out_fd = dup(fds->stdout_fd);
}
