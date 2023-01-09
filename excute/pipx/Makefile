# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:57:00 by juha              #+#    #+#              #
#    Updated: 2023/01/09 19:28:30 by juha             ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC 			= 	cc
CFLAGES 	= 	-Wall -Werror -Wextra
NAME 		= 	pipex
BONUS_SRC 	=	pipex_bonus.c operation_bonus.c utils_bonus.c excute.c
LIBFT		=	libft.a
LIB_DIR 	=	./libft
OBJS 		=	$(SRC:.c=.o)
BONUS_OBJS	=	$(BONUS_SRC:.c=.o)

.PHONY: all clean fclean re bonus

$(NAME) : $(BONUS_OBJS) $(LIBFT)
		$(CC) $(CFLAGES) -L./ -lft -Ipipex $^ -o $(NAME)

$(LIBFT) : 
		make -j3 bonus -C $(LIB_DIR)
		mv $(LIB_DIR)/$(LIBFT) ./$(LIBFT)

all : $(NAME)

clean : 
	@rm -rf *.o
	@make clean -C $(LIB_DIR)

fclean :
	@make clean
	@rm -rf $(NAME) $(LIBFT)
	@make fclean -C $(LIB_DIR)

re :
	@make fclean
	@make all
