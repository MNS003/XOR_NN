# C++ Makefile with file structure:
# --Makefile
# --<program name>
# --src:
# ----/Driver.cpp
# --lib:
# ----/<all cpp files>.cpp
# --build:
# ----/<all object files>.o

CFLAGS = g++ -Wall -g -std=c++11
OBJECTS = ./build/Vector.o ./build/XOR.o ./build/Matrix.o ./build/Perceptron.o
DRIVER = ./build/Driver.o
TEST_PATH = ./tests
TEST_OBJECTS = ./build/
PROGRAM_NAME = main
LIB = ./lib
SRC = ./src
BUILD = ./build

$(PROGRAM_NAME): $(OBJECTS) $(DRIVER) #builds program
	$(CFLAGS) $(OBJECTS) $(DRIVER) -o $(PROGRAM_NAME)

test: | $(PROGRAM_NAME) test_objects runtest

runtest:
	./test

test_objects: $(TEST_OBJECTS) $(OBJECTS) #builds tester
	$(CFLAGS) $(OBJECTS) $(TEST_OBJECTS) -o test

$(BUILD)/%.o: $(SRC)/%.cpp #builds driver
	$(CFLAGS) -c $< -o $@

$(BUILD)/%.o: $(LIB)/%.cpp #builds lib files
	$(CFLAGS) -c $< -o $@

$(BUILD)/%.o: $(TEST_PATH)/%.cpp #builds test objects
	$(CFLAGS) -c $< -o $@

#default args
ARGS = data/XOR.txt data/OR.txt data/AND.txt

run:
	./$(PROGRAM_NAME) $(ARGS)

clean: 
	rm -f $(PROGRAM_NAME) $(BUILD)/*.o
	clear