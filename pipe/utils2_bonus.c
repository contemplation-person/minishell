/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:32:25 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 14:33:27 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	pipex_error_code(t_pipe *p)
{
	if (WIFEXITED(p->status))
		g_error_code = WEXITSTATUS(p->status);
	else if (WIFSIGNALED(p->status))
	{
		g_error_code = WTERMSIG(p->status);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	free_t_pipe(p);
	return (g_error_code);
}
