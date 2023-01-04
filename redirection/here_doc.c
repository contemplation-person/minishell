/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:41:20 by gyim              #+#    #+#             */
/*   Updated: 2023/01/04 18:52:40 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "../get_next_line/get_next_line_bonus.h"

int	read_lines(int here_doc_fd, char *limiter)
{
	char	*line;

	while (1)
	{
		write(2, ">", 1);
		line = get_next_line(0);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
			break ;
		write(here_doc_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	return (0);
}
