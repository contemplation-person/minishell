/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:42:56 by juha              #+#    #+#             */
/*   Updated: 2022/12/18 12:48:15 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include <readline/readline.h>
# include <readline/history.h>
# include "../minishell.h"


int			is_white_space(char *check_charecter);
// static void	init_list(t_env_info_list *list, char **envp);
#endif
