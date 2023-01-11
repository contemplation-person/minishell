/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:10:52 by juha              #+#    #+#             */
/*   Updated: 2023/01/11 13:54:02 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include "../minishell.h"

enum e_cmd
{
	READ,
	WRITE,
	EVEN = 0,
	ODD,
	START = 0,
	END,
	FIRST = 0,
	SECOND,
	parent = 0,
	child,
};

typedef struct s_using_pipe
{
	int	fd[2];
	int	prev_fd;
}t_using_pipe;

typedef struct s_pipe
{
	char		**path;
	char		*pwd;
	int			argc;
	char		**argv;
	char		**envp;
	pid_t		pid_num;
	int			operator_cmd;
	int			status;
}t_pipe;

int		pipex(t_cplist *cmd_pipe_list,
			t_env_info_list *envp_list);
void	pipex_excute_cmd(t_cplist *cmd_pipe_list,
			t_env_info_list *envp_list);

void	init(t_pipe *p, t_using_pipe *channel, \
			t_cplist *cmd_pipe_list, t_env_info_list *envp_list);
int		set_collabo(t_pipe *p, char **envp);
char	*parse_file(t_pipe p, char **argv);

char	**get_envp(t_env_info_list	*envp_list);
char	**get_argv_to_cmd_list(int cnt_cmd, t_cplist *cmd_list);

void	check_error(int error, char *str);

char	**parse_option(t_pipe p, t_using_pipe channel);
char	*access_file(t_pipe *p, t_using_pipe *channel, int ok);
void	start_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd);
void	other_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd);
void	bottom_child(t_pipe *p, t_using_pipe *channel, t_cplist *cmd);
#endif