NAME = so_long

BONUSNAME = checker

SRCS = so_long.c

BONUSSRCS = checker.c

OBJS := ${SRCS:.c=.o}

BONUSOBJS := ${BONUSSRCS:.c=.o}

HEADER = so_lomg.h

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	cc $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(SRCS)
	cc -c $(FLAGS) $(SRCS)

bonus):	$(BONUSOBJS)
	cc $(FLAGS) -o $(BONUSNAME) $(BONUSOBJS)

$(BONUSOBJS):	$(BONUSSRCS)
	cc -c $(FLAGS) $(BONUSSRCS)

clean:
	rm -f $(OBJS) $(BONUSOBJS)

fclean:	clean
	rm -f $(NAME) $(BONUSNAME)

re:	fclean all