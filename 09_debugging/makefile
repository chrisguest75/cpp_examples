.RECIPEPREFIX =  

CC = g++
OBJECT_DIR = obj
CXXFLAGS = -O3 -ggdb -m64
LDFLAGS  = -m64

all: helloworld

.PRECIOUS: helloworld $(OBJECT_DIR)/helloworld.o
.PHONY: all clean

$(OBJECT_DIR)/%.o: %.cpp
	mkdir -p $(OBJECT_DIR)
	$(CC) -c $< -o $@ $(CXXFLAGS)

helloworld: $(OBJECT_DIR)/helloworld.o
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJECT_DIR)/helloworld.o helloworld
	rmdir $(OBJECT_DIR) 2>/dev/null || true