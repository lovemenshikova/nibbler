NAME = snake
# LIBRARY_NAME_1 = qt
LIBRARY_NAME_2 = sfml
SOURCE_DIR = sources/
OBJECT_DIR = build/
INCLUDE_DIR = includes/
# BINARY_DIR = 
LIBRARY_DIR = libs/
BINARY_PATH = $(NAME)
# LIBRARY_PATH_1 = $(LIBRARY_DIR)$(LIBRARY_NAME_1)
LIBRARY_PATH_2 = $(LIBRARY_DIR)$(LIBRARY_NAME_2)

SOURCE_FILES = main.cpp \
snake.cpp \
snake_utils.cpp \
snake_player.cpp \
snake_lib_handler.cpp \
snake_level.cpp

SFML_PATH=/Users/liubov/projects/nibbler/nibbler/nibbler/SFML-3.0.2

export CPP = clang++
export CPP_FLAGS = -Wall -Wextra -Werror -std=c++17

# Объединяем все флаги линкера в одну строку
LD_FLAGS = -L$(SFML_PATH)/lib \
-lsfml-graphics.3.0.2 -lsfml-window -lsfml-system -lsfml-graphics.3.0

SOURCES = $(addprefix $(SOURCE_DIR), $(SOURCE_FILES))
OBJECTS = $(subst $(SOURCE_DIR), $(OBJECT_DIR), $(SOURCES:.cpp=.o))

all: dependency $(BINARY_PATH)
	@echo "$(BINARY_PATH) is ready!"

dependency:
	$(MAKE) -C $(LIBRARY_PATH_2)

$(BINARY_PATH): $(OBJECTS)
	$(CPP) $(LD_FLAGS) -o $(BINARY_PATH) $^

$(OBJECT_DIR)%.o: $(SOURCE_DIR)%.cpp
	@mkdir -p $(@D)
	$(CPP) $(CPP_FLAGS) -I$(INCLUDE_DIR) -o $@ -c $<

clean:
	$(MAKE) -C $(LIBRARY_PATH_2) clean
	rm -rf $(OBJECT_DIR)

fclean: clean
	rm -rf $(BINARY_PATH)

re: fclean all