.RECIPEPREFIX =  

CC = g++
#CC = clang++
OBJECT_DIR = obj
BIN_DIR = bin
CXXFLAGS = -O3 -ggdb -m64
LDFLAGS  = -m64

all: $(BIN_DIR)/helloworld

.PRECIOUS: $(BIN_DIR)/helloworld $(OBJECT_DIR)/helloworld.o
.PHONY: all clean

$(OBJECT_DIR)/%.o: %.cpp
	mkdir -p $(OBJECT_DIR)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(BIN_DIR)/helloworld: $(OBJECT_DIR)/helloworld.o
	mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECT_DIR)/helloworld.o $(BIN_DIR)/helloworld
	rmdir $(OBJECT_DIR) 2>/dev/null || true