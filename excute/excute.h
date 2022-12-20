/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:14:07 by gyim              #+#    #+#             */
/*   Updated: 2022/12/20 18:14:19 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCUTE_H
# define EXCUTE_H
# include "../builtin_list/builtin_list.h"
# include "../minishell.h"

int		excute_leaf(t_tnode *cmd_list, t_env_info_list *env_list);
int		excute_cmd(char **cmd, t_env_info_list *env_list);

char	**get_path(t_env_info_list *env_list);
void	free_path(char **path);

char	**get_cmd(t_tnode *head);
int		get_cmd_list_len(t_tnode *head);
void	free_cmd(char **cmd);

#endif