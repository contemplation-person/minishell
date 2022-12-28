/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:42/succes_mission/pipex/libft/ft_bzero.c
/*   Created: 2022/03/09 12:27:42 by juha              #+#    #+#             */
/*   Updated: 2022/05/14 17:08:30 by juha             ###   ########seoul.kr  */
=======
/*   Created: 2022/12/02 12:28:24 by juha              #+#    #+#             */
/*   Updated: 2022/12/27 14:33:29 by gyim             ###   ########seoul.kr  */
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/env.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD:42/succes_mission/pipex/libft/ft_bzero.c
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			t;

	if (n > 0)
	{
		t = 0;
		temp = (unsigned char *)s;
		while (t < n)
			temp[t++] = '\0';
	}
	else
		return ;
=======
t_bool	builtin_env(t_env_info_list *minishell_envp, char **excute_str_form)
{
	int	i;

	i = 0;
	while (excute_str_form[i])
		i++;
	if (i > 1)
	{
		builtin_error_message("42가", "구현하지말래요", "", 127);
		return (FALSE);
	}
	else
		print_envp(*minishell_envp, ENV);
	return (TRUE);
>>>>>>> b658099e248d20e16d25eff82aa46c41059ed0e0:builtin/env.c
}
