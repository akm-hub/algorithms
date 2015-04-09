CXX 		:= g++
CXXFLAGS	:= -std=gnu++11 -Wall -Wextra
BUILD_DIR 	:= build
BIN_DIR 	:= bin
SRC_DIR		:= src
INC_DIR		:= include
TEST_DIR	:= test
INCLUDES	:= -I$(INC_DIR)
RM			:= rm -f
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)
OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(SOURCES:.cpp=.o)))
TESTS = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%.bin,$(TEST_SOURCES))

all: $(OBJS) $(TESTS)

.SECONDEXPANSION:
PERCENT = %

$(OBJS): %.o : $$(filter $$(PERCENT)/$$(notdir %).cpp, $(SOURCES))
	$(CXX) $< -c -o $@ $(CXXFLAGS) $(INCLUDES)

$(TESTS): $(BIN_DIR)/%.bin: $(TEST_DIR)/%.cpp $(BUILD_DIR)/*.o
	$(CXX) -o $@ $^ $(CXXFLAGS) $(INCLUDES)

clean: 
	$(RM) -r $(BUILD_DIR)/*.o $(BIN_DIR)/*.bin



