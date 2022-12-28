/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/succes_mission/so_long/play/play2.c
/*   Created: 2022/08/30 21:48:35 by juha              #+#    #+#             */
/*   Updated: 2022/09/02 18:49:35 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_cnt(t_all *a, unsigned int cnt)
{
	char	*str;

	str = ft_itoa(cnt);
	mlx_string_put(a->v.mlx, a->v.win, a->m.x / 2 * 32, a->m.y / 2 * 32, \
	0x444444, str);
	free (str);
=======
/*   Created: 2022/12/19 11:36:45 by juha              #+#    #+#             */
/*   Updated: 2022/12/26 14:06:31 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_struct.h"
#include "../minishell.h"
#include "builtin.h"

void	builtin_error_message(char *name, char *error, \
								char *message, int error_code)
{
	g_error_code = error_code;
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
}

int	cnt_argc(char **excute_str_form)
{
	int	i;

	i = 0;
	while (excute_str_form[i])
		i++;
	return (i);
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/builtin_utils.c
}
