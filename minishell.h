/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:52:21 by juha              #+#    #+#             */
/*   Updated: 2023/01/14 11:46:22 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include "builtin_list/builtin_list.h"
# include "minishell_struct.h"
# include "libft/libft.h"
# include "excute/excute.h"
# include "builtin/builtin.h"
# include "parser/parser.h"
# include "builtin/builtin.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"
# include "redirection/redirection.h"
# include "prompt/prompt.h"
# include "pipe/pipex_bonus.h"

#endif