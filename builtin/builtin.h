/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:04:03 by juha              #+#    #+#             */
/*   Updated: 2022/12/08 14:26:02 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"

typedef enum e_bool
{
	FALSE,
	TRUE,
}t_bool;

int		cd(int argc, char **argv); //done
int		echo(int argc, char **argv); //done
t_bool	env(t_list *list, int argc); //done
int		builtin_exit(int argc, char **argv);
t_bool	builtin_export(t_list **minishell_envp, int argc, char *env);
int		pwd(int argc);
t_bool	unset(t_list *l, char *unset_name);

#endif