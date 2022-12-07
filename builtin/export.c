/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:21:23 by juha              #+#    #+#             */
/*   Updated: 2022/12/07 20:40:58 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
/*
	같은 값이면, 덮어씀.
*/
t_bool	export(t_list **minishell_envp, char **env)
{
	ft_lstadd_back(minishell_envp, ft_lstnew(*env));
	return (TRUE);
}