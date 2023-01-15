/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:25:16 by gyim              #+#    #+#             */
/*   Updated: 2023/01/16 05:02:11 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H
# include "../minishell.h"

void	get_redirection(t_rnode **r_list, t_tnode *cmd_list);
int		is_redirection(char *token);
void	add_redirection(t_rnode	**r_list, t_tnode *node);
t_rnode	*set_redirection(t_tnode *node);
void	change_fds(t_fds *fds, t_fds *temp);
int		set_fds(t_fds *fds, t_rnode *node, t_env_info_list *envp_list);
t_bool	create_heredoc(t_cplist *cplist);

int		set_outfile(t_fds *fds, t_rnode *node);
int		set_addfile(t_fds *fds, t_rnode *node);
int		set_infile(t_fds *fds, t_rnode *node);
int		set_here_doc(t_rnode *node, t_fds *fds, t_env_info_list *envp_list);
void	free_red(t_rnode *rd_head);

int		check_redirection(t_rnode *head);
void	free_rlist(t_rnode *head);
int		renewal_fds(t_rnode *node, t_fds *fds, t_env_info_list *envp_list);
int		set_fds(t_fds *fds, t_rnode *node, t_env_info_list *envp_list);
int		redirection(t_fds *fds, t_rnode *rd_head, t_env_info_list *envp_list);

int		read_lines(int here_doc_fd, t_fds *fds, char *limiter,
			t_env_info_list *envp_list);
void	delete_here_doc(void);
#endif