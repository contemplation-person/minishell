/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:42:56 by juha              #+#    #+#             */
/*   Updated: 2022/12/30 06:34:12 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

// # include "../minishell.h"
# include "../minishell_struct.h"
# include "../builtin_list/builtin_list.h"
# include "../builtin/builtin.h"
# include "../parser/parser.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/errno.h>
# include <signal.h>

int	g_error_code;

#endif