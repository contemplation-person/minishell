/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:12:15 by juha              #+#    #+#             */
/*   Updated: 2023/01/13 00:22:11 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_heredoc(t_cplist *cplist)
{
	t_cplist	*temp;
	t_rnode		*rtemp;
	char		*exit_code;
	int			fd;
	char		*str;

	temp = cplist;
	while (temp->cmd)
	{
		rtemp = temp->rd_head;
		while (rtemp)
		{
			if (rtemp->redirection == HEREDOC)
			{
				exit_code = rtemp->file;
				rtemp->file = NULL;
				while (42)
				{
					ft_putstr_fd("> ", STDOUT_FILENO);
					str = get_next_line(STDIN_FILENO);
					if (str == NULL)
						break ;
					else if (str == "") // 의문.시그널인듯.
					{
						free(str);
						break ;
					}
					else if (!ft_strncmp(exit_code, str, ft_strlen(exit_code)) \
						&& ft_strlen(exit_code) == ft_strlen(str))
					{
						free(str);
						break ;
					}
					if (rtemp->file == NULL)
						rtemp->file = ft_strdup(str);
					else
						smart_join(&(rtemp->file), str);
					free(str);
				}
			}
			rtemp->next;
		}
		temp->next;
	}
}