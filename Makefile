# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/30 14:47:32 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:=	minishell
# MAC_OS READLINE
# READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
# READLINE_INC	:=	$(shell brew --prefix readline)/include
# LINUX READLINE
READLINE_LIB	:=	-lreadline -Lreadline
READLINE_INC	:=	-I./readline
CC 				:=	cc
CFLAGS 			:=	-Wall -Werror -Wextra -I$(READLINE_INC)

SRC 			:=	parser/parser.c	\
					parser/search_tree.c \
					parser/split_input.c \
					parser/split_input2.c \
					parser/token_check.c \
					parser/token_list.c	\
					parser/token_list2.c \
					parser/tree.c \
			 		parser/utils.c \
					parser/utils2.c	\
					parser/valid_check.c \
					parser/param_expansion.c \
					parser/cmds_check.c \
					operator/pipe_op.c \
					operator/redirection_excute.c \
					operator/here_doc.c \
					operator/logical_op.c \
					prompt/prompt.c	\
					excute/excute.c \
					excute/path.c \
					excute/cmd.c \
					excute/env_to_str.c \
					builtin_list/builtin_list.c \
					builtin/builtin_utils.c \
					builtin/cd.c \
					builtin/echo.c \
					builtin/env.c \
					builtin/exit.c \
					builtin/export.c \
					builtin/pwd.c \
					builtin/unset.c \
					get_next_line/get_next_line_bonus.c \
					get_next_line/get_next_line_utils_bonus.c 
LIBFT			:= libft/libft.a 
FT_PRINTF		:= ft_printf/libftprintf.a
OBJ 			:= $(SRC:.c=.o)


$(NAME) : $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) -o $(NAME)  $(OBJ) $(LIBFT) $(FT_PRINTF) $(READLINE_LIB)

$(LIBFT) :
	make -j 4 -C libft bonus
$(FT_PRINTF) :
	make -j 4 -C ft_printf all

all : $(NAME)

clean :
	make -C libft fclean
	make -C ft_printf fclean
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus



# READLINE_LIB	:=	-lreadline -Lreadline
# READLINE_INC	:=	-I./readline

# READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
# READLINE_INC	:=	-I$(shell brew --prefix readline)/include

#builtin/cd.c builtin/echo.c builtine/env.c \
#builtin/exit.c builtin/export.c builtin/pwd.c\


					