# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 11:14:27 by mlindenm          #+#    #+#              #
#    Updated: 2023/05/04 19:40:18 by mlindenm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SRC			=	sources/main.c
OBJ			=	$(addprefix obj/, $(SRC:.c=.o))
LIBFT_PATH	=	libraries/libft
LIBFT		=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -Wno-gnu-include-next -I./LeakSanitizer/include -L./LeakSanitizer -llsan -lc++ -o $(NAME)

obj/%.o: %.c | obj
	$(CC) $(CFLAGS) -c $*.c -o obj/$*.o

obj:
	mkdir -p obj

$(LIBFT): $(LIBFT_PATH)
	make bonus -C $(LIBFT_PATH)

clean:
	@rm -rf obj
	@make fclean -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
