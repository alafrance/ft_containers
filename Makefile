# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 14:11:52 by alafranc          #+#    #+#              #
#    Updated: 2021/11/05 14:26:41 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= ft_containers

FILES			= main.cpp


INC_CONTAINERS = vector.hpp stack.hpp map.hpp
INC_ITERATOR	= iterator.hpp random_access_iterator.hpp bidirectional_iterator.hpp
INC_GENERAL		= metafunctions.hpp pair.hpp utility.hpp RedBlackTree.hpp
INC_FILES		=	${ addprefix containers/, ${INC_CONTAINERS} }\
 					${ addprefix iterator/, ${INC_ITERATOR} }\
 					${INC_GENERAL}

INC_PATH		= .
INC				= $(addprefix ${INC_PATH}/, ${INC_FILES})

SRC_PATH		= .
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})

BIN_PATH		= bin
BIN				= $(SRC:%.cpp=$(BIN_PATH)/%.o)

CC				= clang++
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror -std=c++98
AR				= ar rcs

all:  			${NAME}

init:
				@$(shell mkdir -p $(BIN_PATH))


$(BIN): $(BIN_PATH)/%.o: %.cpp ${INC}
				@mkdir -p $(@D)
				$(CC) $(FLAGS) -c $< -o $@

${NAME}: 		init ${BIN}
				${CC} ${FLAGS} ${BIN} -I ${INC_PATH} -o ${NAME}

test:			${NAME}
				make -C ../ft_containers_test all

leaks:			${NAME}
				leaks -atExit -- ./${NAME}

clean:
				@${RM} ${BIN_PATH}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all
