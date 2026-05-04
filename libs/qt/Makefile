# NAME = library_3.so

# SOURCE = game_graphic.cpp
# OBJECT = $(SOURCE:.cpp=.o)

# CPP ?= clang++
# CPP_FLAGS ?= -Wall -Wextra -Werror 
# CPP_FLAGS += -I../include -I../../sfml/SFML-3.0.2/include -fPIC

# LD_FLAGS = -dynamiclib
# LD_FLAGS += -L../../sfml/SFML-3.0.2/lib
# LD_FLAGS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

# all: $(NAME)

# $(NAME): $(OBJECT)
# 	$(CPP) $(LD_FLAGS) -o $(NAME) $(OBJECT)

# %.o: %.cpp
# 	@mkdir -p $(@D)
# 	$(CPP) $(CPP_FLAGS) -o $@ -c $<

# clean:
# 	rm -rf $(OBJECT)

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all