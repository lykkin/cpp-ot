NAME=cpp-ot
SRC_DIR := ./src
OBJ_DIR := ./out
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
CXX=g++

MKDIR_P = mkdir -p

.PHONY: clean test directories

INCLUDES_DIR = ./include

CXXFLAGS=-std=c++17 -Wall -Werror -g -O3 -Wextra -Wstrict-aliasing=2 \
		 -Wformat=2 -Wno-format-nonliteral -Wshadow -Wpointer-arith -Wcast-qual \
		 -Wmissing-prototypes -Wno-missing-braces -pedantic-errors -I$(INCLUDES_DIR)

all: compile

test: compile

compile: $(OBJ_FILES)

clean:
	$(RM) ./out/**/*.o
	$(RM) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES_DIR)/%.h $(OBJ_DIR)/$(dir %)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/%:
	$(MKDIR_P) $(@D)
