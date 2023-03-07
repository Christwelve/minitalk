NAME		= 	minitalk
CFLAGS		= 	-Wall -Werror -Wextra
CC			= 	cc
RM			=	rm -rf
INCLUDE 	= 	-I include

MAN_FILES	=	client.c \
				server.c \

MAN_OBJ		=	$(MAN_FILES:.c=.o)

LIBS		=	libs/libs.a

GREEN		= 	\033[0;32m
BLUE		=	\033[0;94m
WHITE		=	\033[0m


# RULES

all: $(NAME)

$(NAME): $(LIBS) $(MAN_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MAN_OBJ) $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** minitalk compiled!***$(WHITE)"

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	@if [ ! -d "./libs" ]; then git clone https://github.com/Christwelve/libs.git; fi
	@make --silent -C libs

clean:
	$(RM) $(MAN_OBJ)
	make clean --silent -C libs
	@echo "$(BLUE)*** Object files minitalk cleaned! ***$(WHITE)"

fclean: clean
	$(RM) $(NAME)
	make fclean --silent -C libs
	@echo "$(BLUE)*** Executable (.a) file minitalk cleaned! ***$(WHITE)"

re: fclean all
	@echo "$(GREEN)*** Cleaned and rebuilt minitalk! ***$(WHITE)"

.PHONY:  test clean fclean re all