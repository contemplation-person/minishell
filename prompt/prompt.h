/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:42:56 by juha              #+#    #+#             */
/*   Updated: 2023/01/05 08:22:44 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "../minishell.h"
# include <sys/errno.h>
# include <signal.h>

int		g_error_code;

void	signal_handler(int signal_int);
void	signal_handler2(int signal_int);
void	_set_signal(struct sigaction *sa, int flag);
int		minishell_excute(t_env_info_list *minishell_envp_list,
			struct sigaction *sa);

#endif