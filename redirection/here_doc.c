/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:41:20 by gyim              #+#    #+#             */
/*   Updated: 2022/12/28 17:23:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "redirection.h"
#include "../get_next_line/get_next_line_bonus.h"

int	read_lines(char *limiter, int out_fd)
{
	char		*line;
	const char	*str = ">";

	while (1)
	{
		write(2, str, ft_strlen(str));
		line = get_next_line(0);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
			break ;
		write(out_fd, line, ft_strlen(line));
	}
	return (0);
}
