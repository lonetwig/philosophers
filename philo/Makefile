CC = cc

PATH_F = functions
C_FILES_FUNC = $(PATH_F)/check_and_get_args.c $(PATH_F)/forks.c $(PATH_F)/ft_atoi.c $(PATH_F)/ft_malloc.c $(PATH_F)/print_and_exit.c $(PATH_F)/threads.c \
$(PATH_F)/time.c $(PATH_F)/num_to_str.c $(PATH_F)/ft_split.c

PATH_R = routine
C_FILES_ROUT = $(PATH_R)/all_states.c $(PATH_R)/checker.c $(PATH_R)/print_state.c $(PATH_R)/routine.c $(PATH_R)/take_put_fork.c

C_FILES = $(C_FILES_FUNC) $(C_FILES_ROUT) philosophers.c
O_FILES = $(C_FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror
NAME = philo.a
EXE = philo

all:$(NAME)

$(NAME):$(O_FILES)
	ar -rcs $(NAME) $(O_FILES)
	$(CC) $(NAME) $(FLAGS) -o $(EXE)

%.o:%.c philosophers.h
	$(CC) -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all bonus clean fclean re