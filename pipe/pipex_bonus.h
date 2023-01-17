/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:10:52 by juha              #+#    #+#             */
/*   Updated: 2023/01/17 15:50:42 by gyim             ###   ########seoul.kr  */
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
	t_fds		*fds;
	int			stdin_out[2];
	pid_t		pid_num;
	int			operator_cmd;
	int			status;
}t_pipe;

int		pipex(t_cplist *cmd_pipe_list, t_fds *fds,
			t_env_info_list *envp_list);
int		pipex2(t_cplist *cmd_pipe_list, t_fds *fds,
			t_env_info_list *envp_list);

void	init(t_pipe *p, t_using_pipe *channel, \
			t_cplist *cmd_pipe_list, t_env_info_list *envp_list);
int		set_collabo(t_pipe *p, char **envp);
char	*parse_file(t_pipe p, char **argv);
void	free_t_pipe(t_pipe *p);
//char	*access_heredoc_name(void);

char	**get_envp(t_env_info_list	*envp_list);
char	**get_argv_to_cmd_list(int cnt_cmd, t_cplist *cmd_list);

void	check_error(int error, char *str);

int		excute_redirection(t_pipe *p, t_cplist *cmd);
int		check_redirection_builtin(char **cmd);

char	**parse_option(t_pipe p);
void	start_child(t_pipe *p, t_using_pipe *channel,
			t_cplist *cmd, t_env_info_list *envp_list);
void	other_child(t_pipe *p, t_using_pipe *channel,
			t_cplist *cmd, t_env_info_list *envp_list);
void	bottom_child(t_pipe *p, t_using_pipe *channel,
			t_cplist *cmd, t_env_info_list *envp_list);

int		pipex_error_code(t_pipe *p);
#endif
