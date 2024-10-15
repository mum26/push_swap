NAME     = push_swap
CFLAGS   = -Wall -Wextra -Werror -g -Ilibft
LDFLAGS  = -Llibft -lft
SRCS     = main.c
OBJS     = $(SRC:.c=.o)
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
