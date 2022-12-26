# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyim <gyim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/26 09:32:22 by gyim             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:=	minishell
READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
READLINE_INC	:=	$(shell brew --prefix readline)/include
CC 				:=	cc
CFLAGS 			:=	-Wall -Werror -Wextra -I$(READLINE_INC)

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
					parser/param_expansion.c \
					parser/pipe_excute.c \
					prompt/prompt.c	\
					excute/excute.c \
					excute/path.c \
					excute/cmd.c \
					builtin_list/builtin_list.c \
					builtin/builtin_utils.c \
					#builtin/cd.c \
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
	$(CC) -o $(NAME)  $(OBJ) $(LIBFT) $(FT_PRINTF) $(READLINE_LIB)

$(LIBFT) :
	make -C libft bonus
$(FT_PRINTF) :
	make -C ft_printf all

all : $(NAME)

clean :
	make -C libft fclean
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


					