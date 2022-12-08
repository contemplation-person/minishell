/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:26:48 by gyim              #+#    #+#             */
/*   Updated: 2022/12/08 20:26:24 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_op(char **cmds)
{
	int	i;
	int	ret;
	int	p_flag;

	ret = check_double_op(cmds);
	if (ret == -2)
		return (-1);
	if (ret != -1)
		return (ret);
	ret = check_pipe_op(cmds);
	if (ret == -2)
		return (-1);
	if (ret != -1)
		return (ret);
	ret = check_redirect(cmds);
	if (ret == -2)
		return (-1);
	return (ret);
}

char	**subcmds(char **cmds, int start, int end)
{
	int		len;
	char	**ret;
	int		i;

	len = end - start + 1;
	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = NULL;
	i = 0;
	while (i < len)
	{
		ret[i] = ft_strdup(cmds[i + start]);
		i++;
	}
	return (ret);
}

int	cmds_len(char **cmds)
{
	int	len;

	len = 0;
	while (cmds[len])
		len++;
	return (len);
}

void	free_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
}

void	print_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		printf("%s ", cmds[i]);
		i++;
	}
	putchar('\n');
}
