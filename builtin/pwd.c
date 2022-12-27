/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:20:36 by juha              #+#    #+#             */
/*   Updated: 2022/11/23 08:20:36 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// env PWD 경로 수정, env OLDPWD 경로 수정

void	builtin_pwd(char **excute_str_form)
{
	int		i;
	char	*str;

	i = cnt_argc(excute_str_form);
	if (i != 1)
		return (builtin_error_message("bash", "pwd", "too many arguments", \
				127));
	str = NULL;
	str = getcwd(str, 1);
	ft_putstr_fd(str, STDIN_FILENO);
	free(str);
	g_error_code = 0;
}

//int	main()
//{
//	t_env_info		info;
//	t_env_info_list	l;
//	char			**test;

//	l.env_info = &info;
//	ft_bzero(&l, sizeof(t_env_info_list));
//	test = calloc(sizeof(char **), 4);
//	test[0] = ft_strdup("pwd");
//	test[3] = ft_strdup("test1");
//	test[2] = ft_strdup("testte===");
//	test[1] = NULL;
//	builtin_pwd(test);
//	// print_envp(l, EXPORT);
//	// system("leaks a.out");
//}
