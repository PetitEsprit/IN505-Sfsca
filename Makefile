# COMPILATION
CXX			:= g++
CXXFLAGS	:= -Wall -Wextra -Werror
DFLAGS		= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
IDFLAGS		:= -I./inc
LDFLAGS		:= -L./$(LIB_DIR) -l$(NAME)
# Ajouter dépendances dans LDFLAGS AVANT -L 

# DIRECTORIES
BUILD		:= build
SRC_PATH	:= src
BIN_DIR 	:= $(BUILD)/bin
DEP_DIR		:= $(BUILD)/dep
LIB_DIR		:= $(BUILD)/lib
OBJ_DIR 	:= $(BUILD)/obj
SUB_DIR		:= $(BIN_DIR) $(DEP_DIR) $(LIB_DIR) $(OBJ_DIR)

# FILES
NAME	:= sfsca
EXEC	:= $(BIN_DIR)/$(NAME).out
LIB		:= $(LIB_DIR)/$(NAME).a
SRC		:= $(notdir $(wildcard $(SRC_PATH)/*/*.cpp))
BIN		:= $(SRC_BIN:%.cpp=$(BIN_DIR)/%.out)
DEP		:= $(SRC:%.cpp=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(EXEC)

clean:
	rm -rf $(BUILD)

re: fclean all

$(BUILD):
	mkdir $@ $(SUB_DIR)

$(LIB): $(OBJ) | $(BUILD)
	ar -rcs $^ $@

$(EXEC): $(SRC_PATH)/main.cpp | $(BUILD) $(LIB)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(IDFLAGS) $< -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.cpp | $(BUILD)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(IDFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean re
