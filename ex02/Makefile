NAME		=	ex02

SRCS		=	srcs/main.cpp \
				srcs/Bureaucrat.cpp \
				srcs/Form.cpp \
				srcs/ShrubberyCreationForm.cpp \
				srcs/RobotomyRequestForm.cpp \
				srcs/PresidentialPardonForm.cpp

OBJS		=	$(SRCS:.cpp=.o)
CC			=	clang++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
INC_PATH	=	-I./incs
COMPILE		=	$(CC) $(FLAGS) $(INC_PATH)

%.o : %.cpp
			$(CC) $(FLAGS) $(INC_PATH) -c $<  -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	${OBJS}
			$(COMPILE) $(OBJS) -o $(NAME)

clean:
			rm -f ${OBJS} maison

fclean:
			rm -f ${OBJS} maison
			rm -f ${NAME}

re:			fclean all

.PHONY:		clean fclean all re
