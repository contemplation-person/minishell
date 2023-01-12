/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:41:20 by gyim              #+#    #+#             */
/*   Updated: 2023/01/12 23:07:35 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "../get_next_line/get_next_line_bonus.h"

int	read_lines(int here_doc_fd, t_fds *fds, char *limiter, t_env_info_list *envp_list)
{
	char	*line;
	char	*p_expanded;
	char	*temp;

	temp = remove_token_quote(limiter);
	while (1)
	{
		write(2, ">", 1);
		line = get_next_line(fds->stdin_fd);
		if (ft_strncmp(temp, line, ft_strlen(temp)) == 0
			&& line[ft_strlen(temp)] == '\n')
			break ;
		p_expanded = p_token_expansion(line, envp_list);
		write(here_doc_fd, p_expanded, ft_strlen(p_expanded));
		free(line);
		free(p_expanded);
	}
	free(temp);
	free(line);
	return (0);
}

void	delete_here_doc(void)
{
	char	*here_doc;

	here_doc = ft_strjoin(getenv("HOME"), HERE_DOC);
	unlink(here_doc);
	free(here_doc);
}
