# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/13 13:45:37 by oztozdem          #+#    #+#              #
#    Updated: 2026/06/19 14:45:55 by oztozdem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		PmergeMe
CC =		@c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -g3
OBJS =		$(SRCS:.cpp=.o)
OBJS_DIR =	objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
SRCS =		main.cpp PmergeMe.cpp

all:		$(OBJS_DIR) ${NAME}

${NAME}:	${OBJS_PREFIXED}
			@echo "Compiling ${NAME}... 🛠️"
			${CC} ${CFLAGS} -o ${NAME} ${OBJS_PREFIXED}
			@echo "${NAME} compiled 🚀"

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@echo "Cleaning up ${NAME} object files 🧹"
			@rm -rf $(OBJS_DIR)
			@echo "${NAME} object files removed! ✅"

fclean:		clean
			@echo "Deleting ${NAME} 🗑️"
			@rm -rf ${NAME}
			@echo "${NAME} deleted! ❌"

re:			
			@echo "Recompiling ${NAME} 🔄"
			@$(MAKE) -s fclean all
			@echo "Done recompiling! ✅"

.PHONY:		all clean fclean re