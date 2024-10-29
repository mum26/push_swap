CC       = gcc
NAME     = push_swap
CFLAGS   = -g3 -Wall -Wextra -Werror -Ilibft
LDFLAGS  = -Llibft -lft
SRCS     = push_swap.c \
			lst.c \
			contents.c \
			util.c \
			die.c \
			str_token.c \
			print.c \
			swap.c
OBJS     = $(SRCS:.c=.o)
LIB_NAME = libft
LIB_PATH = ./$(LIB_NAME)/$(LIB_NAME).a

.PHONY: NAME all
all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(LIB_PATH):
		$(MAKE) -C $(LIB_NAME)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
		$(MAKE) -C $(LIB_NAME) clean
		$(RM) $(OBJS)
.PHONY: fclean
fclean:
		$(MAKE) -C $(LIB_NAME) fclean
		$(RM) $(OBJS) $(NAME)

.PHONY: re
re: fclean all
