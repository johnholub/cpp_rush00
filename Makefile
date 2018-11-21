NAME = ft_retro

SRC = main.cpp\
      visual.cpp\
      beg_game.cpp\
      MainEvent.cpp\
      move_sky.cpp\
      CharacterFly.cpp\
      characterMove.cpp\
      Bullets.cpp\
      Enemy.cpp\
      checkdmg.cpp\

OBJ		= $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

SRCDIR	= ./src/
INCDIR	= ./headers/
OBJDIR	= ./obj/

CC = clang++

FLAGS = -Wall -Wextra -Werror

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<


$(NAME): $(OBJ)
		$(CC) $(FLAGS) -lncurses $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)

re: fclean all
