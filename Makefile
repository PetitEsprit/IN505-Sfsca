# COMPILATION
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++11 -g
DFLAGS		= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
IDFLAGS		:= -I./inc
LDFLAGS		= -L./$(LIB_DIR) -l$(NAME)
# Ajouter dépendances dans LDFLAGS AVANT -L 

# DIRECTORIES
BUILD	:= build
DATA	:= data
BIN_DIR := $(BUILD)/bin
DEP_DIR	:= $(BUILD)/dep
LIB_DIR	:= $(BUILD)/lib
OBJ_DIR := $(BUILD)/obj
CAT_DIR	:= $(patsubst src/%/, %, $(dir $(wildcard src/*/.)))
SUB_DIR	:= $(BIN_DIR) $(DEP_DIR) $(LIB_DIR) $(OBJ_DIR) \
		   $(addprefix $(DEP_DIR)/, $(CAT_DIR)) \
		   $(addprefix $(OBJ_DIR)/, $(CAT_DIR))

# FILES
NAME	:= sfsca
EXEC	:= $(BIN_DIR)/$(NAME).out
LIB		:= $(LIB_DIR)/lib$(NAME).a
SRC		:= $(patsubst src/%.cpp, %.cpp, $(wildcard src/*/*.cpp))
INC		:= $(wildcard inc/*)
BIN		:= $(SRC_BIN:%.cpp=$(BIN_DIR)/%.out)
DEP		:= $(SRC:%.cpp=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(EXEC)
	./$(EXEC)

clean:
	rm -rf $(BUILD) $(DATA)

re: clean all

$(BUILD):
	mkdir $@ $(DATA) $(SUB_DIR)

$(LIB): $(OBJ) | $(BUILD)
	ar -rcs $@ $^

$(EXEC): src/main.cpp $(INC) $(LIB)
	$(CXX) $(CXXFLAGS) $(IDFLAGS) $< -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(IDFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean re
