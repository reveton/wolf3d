NAME	= wolf3d

SRC		= src/main.c \
		  src/init.c \
		  src/key.c \
		  src/loop.c \
		  src/move.c \
		  src/parsing.c \
		  src/print.c \
		  src/support_func.c \
		  src/calculating.c \
		  src/parsing_2.c \

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Wolf created"
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Usage: ./wolf3d <map>"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Deleted obj"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Deleted Wolf"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
