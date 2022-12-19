# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/19 11:18:13 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:=	minishell
CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -Lreadline
READLINE_INC	:=	-I./readline
SRC 			:=	parser/parser.c	\
					parser/search_tree.c \
					parser/split_input.c \
					parser/token_check.c \
					parser/token_list.c	\
					parser/token_list2.c \
					parser/tree.c \
			 		parser/utils.c \
					parser/utils2.c	\
					parser/valid_check.c \
					prompt/prompt.c	\
					excute/excute.c \
					#builtin/builtin_list.c \
					builtin/cd.c \
					builtin/echo.c \
					builtin/env.c \
					builtin/exit.c \
					builtin/export.c \
					builtin/pwd.c \
					builtin/unset.c
LIBFT			:= libft/libft.a
FT_PRINTF		:= ft_printf/libftprintf.a
OBJ 			:= $(SRC:.c=.o)


$(NAME) : $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME)  $(OBJ) $(LIBFT) $(FT_PRINTF) $(READLINE_LIB) $(READLINE_INC)

$(LIBFT) :
	make -C libft bonus
$(FT_PRINTF) :
	make -C ft_printf all


clean :
	make -C libft fclean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus






# READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
# READLINE_INC	:=	-I$(shell brew --prefix readline)/include

#builtin/cd.c builtin/echo.c builtine/env.c \
#builtin/exit.c builtin/export.c builtin/pwd.c\


					
