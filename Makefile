SRC_DIR := ./src
OBJ_DIR := ./out
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC_FILES))
CXX=g++

MKDIR_P = mkdir -p

.PHONY: clean test directories lint

INCLUDES_DIR = ./include

CXXFLAGS=-std=c++17 -Wall -Werror -g -O3 -Wextra -Wstrict-aliasing=2 \
		 -Wformat=2 -Wno-format-nonliteral -Wshadow -Wpointer-arith -Wcast-qual \
		 -Wmissing-prototypes -Wno-missing-braces -pedantic-errors -I$(INCLUDES_DIR)

all: lint compile

test: lint compile

lint:
	./cpplint.py src/**/*.cc include/**/*.h

compile: $(OBJ_FILES)

clean:
	$(RM) ./out/**/*.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INCLUDES_DIR)/%.h $(OBJ_DIR)/$(dir %)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/%:
	$(MKDIR_P) $(@D)
