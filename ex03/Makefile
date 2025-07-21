# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 13:52:58 by rmakoni           #+#    #+#              #
#    Updated: 2025/07/21 14:59:46 by rmakoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRC = 	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShruberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX)	$(CXXFLAGS)	$(OBJ)	-o	$(NAME)

%.o: %.cpp
	$(CXX)	$(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) *.txt

re: fclean all

.PHONY: all clean fclean re