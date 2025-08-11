# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 10:08:54 by meghribe          #+#    #+#              #
#    Updated: 2025/08/11 22:37:03 by meghribe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

IDIR = .
ODIR = .
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
NAME = megaphone

$(NAME):

.PHONY: all
all: $(NAME)
	$(CC) $(CFLAGS) megaphone.cpp

.PHONY: clean
clean:
	rm -rf megaphone.o

.PHONY: fclean
fclean: clean
	rm -rf megaphone

.PHONY: re
re: 
	fclean re
