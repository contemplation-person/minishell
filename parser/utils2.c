/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:54:06 by gyim              #+#    #+#             */
/*   Updated: 2022/12/08 20:23:39 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_double_op(char **cmds)
{
	int	p_flag;
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	p_flag = 0;
	while (cmds[i])
	{
		if (cmds[i][0] == '(')
			p_flag++;
		else if (cmds[i][0] == ')')
			p_flag--;
		if (p_flag == 0 && (ft_strncmp(cmds[i], "||", 3) == 0
				|| ft_strncmp(cmds[i], "&&", 3) == 0))
			ret = i;
		i++;
	}
	if (p_flag != 0)
		return (-2);
	return (ret);
}

int	check_pipe_op(char **cmds)
{
	int	p_flag;
	int	i;
	int	ret;

	i = 0;
	p_flag = 0;
	ret = -1;
	while (cmds[i])
	{
		if (cmds[i][0] == '(')
			p_flag++;
		else if (cmds[i][0] == ')')
			p_flag--;
		if (p_flag == 0 && cmds[i][0] == '|')
			ret = i;
		i++;
	}
	if (p_flag != 0)
		return (-2);
	return (ret);
}

int	check_redirect(char **cmds)
{
	int	p_flag;
	int	i;
	int	ret;

	i = 0;
	p_flag = 0;
	ret = -1;
	while (cmds[i])
	{
		if (cmds[i][0] == '(')
			p_flag++;
		else if (cmds[i][0] == ')')
			p_flag--;
		if (p_flag == 0 && (ft_strncmp(cmds[i], "<<", 3) == 0
				|| ft_strncmp(cmds[i], "<", 2) == 0
				|| ft_strncmp(cmds[i], ">>", 3) == 0
				|| ft_strncmp(cmds[i], ">", 2) == 0))
			ret = i;
		i++;
	}
	if (p_flag != 0)
		return (-2);
	return (ret);
}
