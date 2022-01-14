# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 17:47:21 by msanjuan          #+#    #+#              #
#    Updated: 2022/01/14 18:26:18 by msanjuan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS = utils/ft_atoi.c \
	utils/ft_calloc.c \
	init/init_philos.c \
	init/init_forks.c \
	routine/create_threads.c \
	utils/get_time.c \
	status/philo_eat.c \
	status/philo_sleep.c \
	status/philo_think.c \
	status/philo_dead.c  \
	end_simulation.c \
	routine/routine.c \
	routine/join_threads.c \
	routine/check_death.c \
	utils/print_status.c \
	routine/one_philo.c \
	errors/check_args.c \
	utils/ft_isdigit.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = clang
CFLAGS = -Wall -Werror -Wextra -pthread -g3 #-MMD -g -fsanitize=thread
IFLAGS:= -I ./incl

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = philo
RM = rm -f

# /* ~~~~~~~ Colors ~~~~~~~ */
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): $(OBJS)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_DIR)main.c $(IFLAGS) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) "[OK COMPILED]" $(EOC)

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME} a.out

re: 	fclean all

.PHONY: all clean fclean re