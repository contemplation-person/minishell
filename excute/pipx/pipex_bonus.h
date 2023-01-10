/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:10:52 by juha              #+#    #+#             */
/*   Updated: 2023/01/10 14:46:16 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <sys/wait.h>
# include "../excute/excute.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

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
	char	**path;
	char	*pwd;
	int		argc;
	char	**argv;
	char	**envp;
	pid_t	pid_num;
	int		operator_cmd;
	int		checking_family;
	int		status;
}t_pipe;

int		pipx(int argc, char **argv, char **envp);
void	excute_cmd(t_tnode *cmd_list, t_env_info_list *envp_list);

void	init(t_pipe *p, t_using_pipe *channel, int argc, char **argv);
int		set_collabo(t_pipe *p, char **envp);
char	*parse_file(t_pipe p, char **argv);

void	check_error(int error, char *str);

char	**parse_option(t_pipe p, t_using_pipe channel);
char	*access_file(t_pipe *p, t_using_pipe *channel, int ok);
void	start_child(t_pipe *p, t_using_pipe *channel);
void	other_child(t_pipe *p, t_using_pipe *channel);
void	bottom_child(t_pipe *p, t_using_pipe *channel);
#endif