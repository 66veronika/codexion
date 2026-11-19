NAME		= codexion

RM 			= rm -rf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
INCLUDES	= -Iinclude

SRCS		=	src/main.c\
				src/parsing.c\
				src/coders.c\
				src/dongle.c \

OBJS 		= $(SRCS:.c=.o)
HEADERS 	= include/codexion.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
