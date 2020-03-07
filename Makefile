# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adietric <adietric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 13:22:46 by adietric          #+#    #+#              #
#    Updated: 2019/04/18 17:41:44 by adietric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME_TWO = push_swap

LIB_PATH = ./libsrcs

SRCS_PATH = ./srcs

OBJLIB_PATH = ./obj

OBJ_PATH = ./obj

MAIN_PATH = ./main

OBJM_PATH = ./main

LIB_NAME =	ft_atoi.c	 			\
			ft_isdigit.c 			\
			ft_putendl.c			\
			ft_putstr.c				\
			ft_strchr.c				\
			ft_strcmp.c				\
			ft_strdel.c				\
			ft_strdup.c				\
			ft_strjoin.c			\
			ft_strnew.c				\
			ft_strsub.c				\
			ft_putchar.c			\
			ft_bzero.c				\
			ft_bzeroint.c			\
			ft_memset.c				\
			get_next_line.c

SRCS_NAME = ft_action.c				\
			ft_algo_1.c				\
			ft_algo_2.c				\
			ft_check.c				\
			ft_cpy.c				\
			ft_execution.c			\
			ft_order.c				\
			ft_rdm_1.c				\
			ft_rdm_2.c				\
			ft_stock.c				\
			ft_valid.c				\
			ft_free.c				\

MAIN_NAME = ft_checker.c			\
			ft_graphique.c			\
			ft_push_1.c				\
			ft_push_2.c				\
			ft_loop_1.c				\
			ft_loop_2.c				\
			ft_loop_3.c

OBJLIB_NAME = $(LIB_NAME:.c=.o)

OBJ_NAME = $(SRCS_NAME:.c=.o)

OBJM_NAME = $(MAIN_NAME:.c=.o)

LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJM = $(addprefix $(OBJM_PATH)/,$(OBJM_NAME))

INCL = ./includes/point.h

CC = gcc

FLAG = -Wall -Werror -Wextra

all: $(NAME) $(NAME_TWO)

$(NAME): $(OBJ) $(OBJLIB) $(OBJM) $(INCL)
	@$(CC) $(FLAG) $(OBJ) $(OBJLIB)  ./main/ft_checker.o ./main/ft_graphique.o ./main/ft_loop_1.o ./main/ft_loop_2.o ./main/ft_loop_3.o -I  $(INCL) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_TWO): $(OBJ) $(OBJLIB) $(OBJM) $(INCL)
	@$(CC) $(FLAG) $(OBJ) $(OBJLIB) ./main/ft_push_1.o ./main/ft_push_2.o -I $(INCL) -o $(NAME_TWO)

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJM_PATH)/%.o: $(MAIN_PATH)/%.c
	@mkdir $(OBJM_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJLIB) $(OBJM)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME) $(NAME_TWO)

re: fclean all