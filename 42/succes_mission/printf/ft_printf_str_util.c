/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/succes_mission/printf/ft_printf_str_util.c
/*   Created: 2022/05/22 23:03:12 by juha              #+#    #+#             */
/*   Updated: 2022/05/30 15:47:22 by juha             ###   ########seoul.kr  */
=======
/*   Created: 2022/12/07 19:41:07 by juha              #+#    #+#             */
/*   Updated: 2022/12/26 15:35:59 by juha             ###   ########seoul.kr  */
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/unset.c
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD:42/succes_mission/printf/ft_printf_str_util.c
void	write_c(va_list *ap, char c, size_t *form_len)
{
	char	*ret;

	ret = &c;
	if (c == 'c')
	{
		(*form_len)++;
		*ret = (char)va_arg(*ap, int);
		write(1, ret, 1);
	}
	else if (c == '%')
	{
		(*form_len)++;
		write(1, "%", 1);
	}
}

void	write_str(va_list *ap, char str, size_t *form_len)
{
	char	*c;
	int		i;

	c = &str;
	c = va_arg(*ap, char *);
	i = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		*form_len += 6;
		return ;
	}
	while (c[i])
		i++;
	(*form_len) += i;
	write(1, c, i);
=======
/*
	옵션  없는  unset
	if (key값이 같으면 지움)
		return (0);
	if (key 값이 다르면 지우지 않음)
*/
t_bool	builtin_unset(t_env_info_list *l, char **excute_str_form)
{
	t_env_info	*node;

	if (!l)
		return (FALSE);
	while (*excute_str_form)
	{
		node = l->env_info;
		while (node)
		{
			if (!ft_strncmp(node->key, *excute_str_form, ft_strlen(*excute_str_form)))
				delete_one_list(l, *excute_str_form);
			node = node->next;
		}
		excute_str_form++;
	}
	return (TRUE);
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/unset.c
}
