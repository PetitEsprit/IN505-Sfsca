# COMPILATION
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror
DFLAGS		= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
IDFLAGS		:= -I./inc
LDFLAGS		= -L./$(LIB_DIR) -l$(NAME)
# Ajouter dépendances dans LDFLAGS AVANT -L 

# DIRECTORIES
BUILD	:= build
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
	rm -rf $(BUILD)

re: clean all

$(BUILD):
	mkdir $@ $(SUB_DIR)

$(LIB): $(OBJ) | $(BUILD)
	ar -rcs $@ $^

$(EXEC): src/main.cpp $(INC) | $(BUILD) $(LIB)
	$(CXX) $(CXXFLAGS) $(IDFLAGS) $< -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(IDFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean re
