NAME = Bureaucrat
SOURCES = main.cpp Bureaucrat.cpp Intern.cpp Form.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
OBJECTS = $(SOURCES:.cpp=.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)						
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

%.o:%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)

fclean:
	@$(RM) -rf $(OBJECTS)
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re