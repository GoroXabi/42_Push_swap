# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xortega <xortega@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 11:02:31 by xortega           #+#    #+#              #
#    Updated: 2024/03/11 13:38:26 by xortega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
SRC_PATH	:=	src
LIBFT		:=	libft.a
LIBFT_PATH	:=	libft/
OBJ_DIR		:=	obj
SOURCES		:=	push_swap.c ps_parse.c ps_checks.c ps_lists.c ps_radix.c \
				ps_movements_b.c  ps_movements_a.c ps_trivial_cases.c \
				ps_utils.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./includes

all: $(NAME)

$(NAME): $(OBJS)
	@clear
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./$(LIBFT)
	@sleep 0.2;
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\033[0;32;3mPUSH_SWAP ✅\n\n"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make -C $(LIBFT_PATH) clean
	@rm -fr $(OBJ_DIR)

fclean:
	make -C $(LIBFT_PATH) fclean
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re