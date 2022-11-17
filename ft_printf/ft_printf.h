/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:25:39 by gyim              #+#    #+#             */
/*   Updated: 2022/08/12 14:16:32 by gyim             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_node
{
	int		left;
	int		sign;
	int		base_show;
	char	zero;
	int		width;
	int		precision;
	int		signed_num;
	int		minus;
	char	hex_x;
}	t_node;

int		ft_printf(const char *format, ...);

t_node	*init_node(void);
int		print_specifier(va_list ap, const char *format, int *index);
void	get_options(t_node *node, const char *format, int *index);
void	get_flags(t_node *node, const char *format, int *index);
void	get_width(t_node *node, const char *format, int *index);
void	get_precision(t_node *node, const char *format, int *index);
int		print_specifier(va_list ap, const char *format, int *index);

int		print_var(va_list ap, t_node node, const char *format, int *index);

int		print_char(va_list ap, t_node node);

int		print_string(va_list ap, t_node node);

int		print_pointer(va_list ap, t_node node);

int		print_decimal(va_list ap, t_node node);

int		print_integer(va_list ap, t_node node);

int		print_unsigned_decimal(va_list ap, t_node node);

int		print_lower_hex(va_list ap, t_node node);

int		print_upper_hex(va_list ap, t_node node);

int		print_percent(t_node node);

char	*alloc_field(int len, t_node node);
int		find_width(int slen, t_node node);
int		write_str(char *dst, char *src, t_node node);
void	move_sign(char *dst, int start, t_node node);
char	*uitoa_base(unsigned long long n, int base, t_node node);
char	*itoa_base(long long n, int base, t_node node);
int		base_len(long long n, int base, t_node node);
char	*char_to_string(char ch);

void	alloc_unsigned_num(char *dst, unsigned long long n, int len, int base);
void	alloc_num(char *dst, long long n, int len, int base);
char	*alloc_null(char *dst, int *isnull);
int		unsigned_base_len(unsigned long long n, int base, t_node node);

void	to_upper_all(char *str);
char	*get_str(char *temp, t_node node);
void	add_sign(char *dst, t_node node, int len);
void	invalid_parameter(char c, int *index);

int		free_str(char **str);
void	free_str_field(char **str, char **field);
int		free_null(char **str, int isnull);
int		option_fail(t_node node);
int		print_format(const char *format, int *index, va_list ap);

#endif