NAME = library_2.so
SOURCE = 	game_graphic.cpp \
			game_snake_drawer.cpp
SFML_PATH = $(abspath ../..)/SFML-3.0.2
OBJECT = $(SOURCE:.cpp=.o)
CPP ?= clang++
CPP_FLAGS ?= -Wall -Wextra -Werror 
CPP_FLAGS += -I../../includes -I$(SFML_PATH)/include -fPIC

LD_FLAGS = -dynamiclib
LD_FLAGS += -L$(SFML_PATH)/lib \
-lsfml-graphics.3.0.2 -lsfml-network -lsfml-window -lsfml-system -lsfml-graphics.3.0

all: $(NAME)

$(NAME): $(OBJECT)
	$(CPP) $(LD_FLAGS) -o $(NAME) $(OBJECT)

%.o: %.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPP_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all
