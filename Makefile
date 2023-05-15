# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 11:14:27 by mlindenm          #+#    #+#              #
#    Updated: 2023/05/15 19:26:27 by mlindenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SRC_DIR		=	sources
OBJ_DIR		=	$(SRC_DIR)/obj
LIBFT_PATH	=	libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

SRC			=	$(SRC_DIR)/main.c $(SRC_DIR)/dlist.c $(SRC_DIR)/error.c $(SRC_DIR)/parse.c $(SRC_DIR)/push.c $(SRC_DIR)/rev_rotate.c $(SRC_DIR)/rotate.c $(SRC_DIR)/swap.c
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_PATH)
	make bonus -C $(LIBFT_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
