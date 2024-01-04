########################################
########## VARIABLES

NAME		= Polymorphisme
CC			= c++
INCLUDES	= -I ./includes/
CFLAGS		= -Wall -Wextra -Werror -std=c++98 $(INCLUDES)
RM			= rm -f

########################################
########## COLORS
DEF_COLOR = \033[0;39m
GRAY = \033[1;90m
RED = \033[1;91m
GREEN = \033[1;92m
YELLOW = \033[1;93m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m
WHITE = \033[1;97m

########################################
########## SOURCES
SRCS	=	srcs/main.cpp srcs/Animal.cpp srcs/Cat.cpp srcs/Dog.cpp srcs/WrongCat.cpp srcs/WrongAnimal.cpp

OBJS	=	$(SRCS:.cpp=.o)

.cpp.o:
		@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)
		@echo "$(MAGENTA)Compilation of : $<..$(DEF_COLOR)"

########################################
########## RULES

all:		$(NAME)

$(NAME):	$(OBJS)
				@$(CC) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Success compilation of $(NAME) !$(DEF_COLOR)"

clean:
				@$(RM) $(OBJS)
				@echo "$(YELLOW)rm of $(OBJS).$(DEF_COLOR)"

fclean: 	clean
				@$(RM) $(NAME)
				@echo "$(RED)rm of $(NAME).$(DEF_COLOR)"

re:			fclean all

.PHONY: all clean fclean re