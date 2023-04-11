NAME	=	philo
CC		=	gcc
INC		=	philo.h
CFLAGS	=	-Wall -Wextra -Werror -pthread #-fsanitize=thread -g
RM		=	rm -rf

SRCS	=	main.c		\
			action.c	\
			atoi.c		\
			setup.c		\
			start.c		\
			utils.c		\

OBJS = $(SRCS:.c=.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(R)philo is created

%.o: %.c $(INC)
	@echo $(Y)COMPİLİNG [$<]
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(B)Removed [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(B)Removed [$(NAME)]

re:	fclean all

.PHONY: all, clean, fclean, re