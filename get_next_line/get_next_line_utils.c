/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:57:15 by gyim              #+#    #+#             */
/*   Updated: 2022/07/24 17:47:21 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

void	strccpy(char *dst, char *src, char c)
{
	int	srclen;
	int	i;

	srclen = ft_strchr(src, c);
	i = 0;
	while (i < srclen)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = c;
	if (c != '\0')
		dst[i + 1] = '\0';
}

char	*get_line(t_list **lst, int len)
{
	t_list	*curr;
	char	*ret;
	int		i;

	if (len == 0)
	{
		del_node(lst);
		return (NULL);
	}
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	curr = *lst;
	i = 0;
	curr = cut_line(ret, curr, &i);
	if (curr != NULL)
		strccpy(ret + i, curr->str, '\n');
	push_backup(lst, curr);
	return (ret);
}

void	push_backup(t_list **lst, t_list *node)
{
	if (!node)
	{
		*lst = NULL;
		return ;
	}
	if (ft_strchr(node->str, '\n') != -1)
	{
		strccpy(node->str,
			(node->str) + (ft_strchr(node->str, '\n') + 1), '\0');
		node->size = ft_strchr(node->str, '\0');
	}
	*lst = node;
}

t_list	*cut_line(char	*dst, t_list *curr, int *len)
{
	t_list	*temp;
	int		i;

	i = 0;
	while (curr != NULL && ft_strchr(curr->str, '\n') == -1)
	{
		temp = curr->next;
		strccpy(dst + i, curr->str, '\0');
		i += curr->size;
		del_node(&curr);
		curr = temp;
	}
	*len = i;
	return (curr);
}
