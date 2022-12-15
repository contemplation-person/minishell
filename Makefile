# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:53:25 by juha              #+#    #+#              #
#    Updated: 2022/12/15 16:02:19 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #


NAME			:= minishell
CC 				:=	cc
CFLAGES 		:=	-Wall -Werror -Wextra
READLINE_LIB	:=	-lreadline -L$(shell brew --prefix readline)/lib
READLINE_INC	:=	-I$(shell brew --prefix readline)/include
SRC = builtin/builtin.h                builtin/pwd.c                    parser/parser/parse_tree.c       parser_list/parser.h             parser_list/tree.c               parser_temp/parse_tree_test.c    prompt_temp/prompt.c
builtin/builtin_list.c           builtin/unset.c                  parser/parser/parse_tree2.c      parser_list/prompt.c             parser_list/utils.c              parser_temp/parser.h             prompt_temp/split_input.c
builtin/cd.c                     excute/excute.c                  parser/parser/parse_tree_test.c  parser_list/search_tree.c        parser_list/utils2.c             parser_temp/token.c              prompt_temp/split_input.h
builtin/echo.c                   excute/excute.h                  parser/parser/parser.h           parser_list/split_input.c        parser_list/valid_check.c        parser_temp/tree.c               prompt_temp/token_check.c
builtin/env.c                    parser/parser/operator.c         parser/parser/token.c            parser_list/token_check.c        parser_temp/operator.c           prompt/prompt.c                  prompt_temp/token_list.c
builtin/exit.c                   parser/parser/pair.c             parser/parser/tree.c             parser_list/token_list.c         parser_temp/pair.c               prompt/prompt.h                  prompt_temp/tree.c
builtin/export.c                 parser/parser/parse_stack.c      parser_list/parser.c             parser_list/token_list2.c        parser_temp/parse_stack.c        prompt_temp/parser.c             prompt_temp/utils.c

OBJ = $(SRC:.c=.o);

# %.c : %.o
# $(CC) $(CFLAGS) -c $<


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : 
	make fclean
	make all

.PHONY : all clean fclean re bonus








#builtin/cd.c builtin/echo.c builtine/env.c \
#builtin/exit.c builtin/export.c builtin/pwd.c\


					
