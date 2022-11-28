/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:51:34 by gyim              #+#    #+#             */
/*   Updated: 2022/11/28 20:32:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "split_input.h"

char	**split_input(char *input)
{
	int				i;
	int				input_len;
	t_tlist_info	*list;

	list = init_tlist();
	input_len = ft_strlen(input);
	i = 0;
	while (i < input_len)
	{
		i += add_token(list, input + i);
	}	
}

t_tlist_info	*init_tlist(void)
{
	t_tlist_info	*list_info;

	list_info = malloc(sizeof(t_tlist_info));
	if (!list_info)
		return (NULL);
	list_info->head = NULL;
	list_info->cnt = 0;
	return (list_info);
}

int	add_token(t_tlist_info *list, char *pos)
{
	int	t_start;
	int	t_end;

	t_start = 0;
	while (pos[t_start] != '\0' && ft_isspace(pos[t_start]))
		t_start++;
	if (pos[t_start] == '\0')
		return (t_start);
	t_end = check_token(pos, t_start);

}

void	list_add(t_tlist_info *list, char *str)
{
	t_tlist	*new_node;

	new_node = malloc(sizeof(t_tlist));
	if (!new_node)
		return ()
}

int	ft_isspace(char *ch)
{
	if (ch == ' ' && ch == '\t')
		return (1);
	else
		return (0);
}
