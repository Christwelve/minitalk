CLIENT		= 	client
SERVER		=	server
CFLAGS		= 	-Wall -Werror -Wextra
CC			= 	cc
RM			=	rm -rf
INCLUDE 	= 	-I include

# MAN_FILES	=	client.c \
# 				server.c \

# MAN_OBJ		=	$(MAN_FILES:.c=.o)

LIBS		=	libs/libs.a

GREEN		= 	\033[0;32m
BLUE		=	\033[0;94m
WHITE		=	\033[0m


# RULES

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBS) src/client.o
	$(CC) $(CFLAGS) -o $(CLIENT) src/client.o $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** Client compiled!***$(WHITE)"

$(SERVER): $(LIBS) src/server.o
	$(CC) $(CFLAGS) -o $(SERVER) src/server.o $(LIBS) $(INCLUDE)
	@echo "$(GREEN)*** Server compiled!***$(WHITE)"	

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS):
	@if [ ! -d "./libs" ]; then git clone https://github.com/Christwelve/libs.git; fi
	@make --silent -C libs

clean:
	$(RM) src/client.o src/server.o
	make clean --silent -C libs
	@echo "$(BLUE)*** Object files minitalk cleaned! ***$(WHITE)"

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	make fclean --silent -C libs
	@echo "$(BLUE)*** Executable (.a) file minitalk cleaned! ***$(WHITE)"

re: fclean all
	@echo "$(GREEN)*** Cleaned and rebuilt minitalk! ***$(WHITE)"

.PHONY:  test clean fclean re all