/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:26:48 by gyim              #+#    #+#             */
/*   Updated: 2022/12/07 11:02:24 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

int	find_op(char **cmds)
{
	int	i;
	int	ret;
	int	p_flag;

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
		return (-1);
	if (ret != -1)
		return (ret);
	i = 0;
	p_flag = 0;
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
		ret[i] = cmds[i + start];
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
	{
		printf("free : %s\n", cmds[i]);
		free(cmds[i++]);
	}
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
