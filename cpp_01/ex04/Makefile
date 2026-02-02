# ================== VARIABLES ================== #

NAME        = sed_is_for_losers
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98
RM          = rm -rf

SRC         = src/main.cpp
DIR_OBJS    = objs

OBJ = $(SRC:src/%.cpp=$(DIR_OBJS)/%.o)

# ================== COLOR ================== #

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RESET       = \033[0m

# ================== RULES ================== #

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compilation de $(NAME) terminée !$(RESET)"

$(DIR_OBJS)/%.o: src/%.cpp
	@mkdir -p $(DIR_OBJS)
	@echo "$(YELLOW)Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(DIR_OBJS)
	@printf "$(RED)Suppression des objets.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Suppression de l'exécutable.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re