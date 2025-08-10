# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meghribe <meghribe@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 10:08:54 by meghribe          #+#    #+#              #
#    Updated: 2025/08/10 16:16:33 by meghribe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

$(NAME):

.PHONY: all
all: $(NAME)
	c++ $(CFLAGS) megaphone.cpp

.PHONY: clean
clean:
	rm -rf megaphone.o

.PHONY: fclean
fclean: clean
	rm -rf megaphone

.PHONY: re
re: 
	fclean re
