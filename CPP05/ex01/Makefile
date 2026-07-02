# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oztozdem <oztozdem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/08 15:59:16 by oztozdem          #+#    #+#              #
#    Updated: 2025/10/10 14:24:02 by oztozdem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		formUp
CC =		@c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -g3
OBJS =		$(SRCS:.cpp=.o)
OBJS_DIR =	objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
SRCS =		main.cpp Bureaucrat.cpp Form.cpp

GREEN =		\033[1;32m
YELLOW =	\033[1;33m
BLUE =		\033[1;34m
RED =		\033[1;31m
RESET =		\033[0m
BOLD =		\033[1m

all:		$(OBJS_DIR) ${NAME}

${NAME}:	${OBJS_PREFIXED}
			@echo "$(BLUE)$(BOLD)Compiling ${NAME}... 🛠️$(RESET)"
			${CC} ${CFLAGS} -o ${NAME} ${OBJS_PREFIXED}
			@echo "$(GREEN)$(BOLD)${NAME} compiled 🚀$(RESET)"

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: %.cpp
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@echo "$(RED)$(BOLD)Cleaning up ${NAME} object files 🧹$(RESET)"
			@rm -rf $(OBJS_DIR)
			@echo "$(GREEN)$(BOLD)${NAME} object files removed! ✅$(RESET)"

fclean:		clean
			@echo "$(RED)$(BOLD)Deleting ${NAME} 🗑️$(RESET)"
			@rm -rf ${NAME}
			@echo "$(GREEN)$(BOLD)${NAME} deleted! ❌$(RESET)"

re:			
			@echo "$(YELLOW)$(BOLD)Recompiling ${NAME} 🔄$(RESET)"
			@$(MAKE) -s fclean all
			@echo "$(YELLOW)$(BOLD)Done recompiling! ✅$(RESET)"

.PHONY:		all clean fclean re