CC=clang
RM=rm -rf
NAME=libunit.a
EXEMPLE=exemple

SRCS_DIR=srcs
INCS_DIR=includes
SRCS:=$(wildcard ./$(SRCS_DIR)/*.c)
INCS=$(wildcard ./$(INCS_DIR)/*.h)
OBJS:=$(SRCS:.c=.o)

FLAGS=-Wall -Wextra -Werror -g -I$(INCS_DIR)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(OBJS): $(INCS)

$(NAME): $(OBJS) $(INCS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

run_exemple: $(NAME)
	$(CC) -o $(EXEMPLE) $(EXEMPLE).c $(NAME) && ./$(EXEMPLE)

re: fclean all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(EXEMPLE)


.PHONY: all clean fclean re