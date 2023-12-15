CC = g++
BIN = nba
SRCS = $(shell find . -name "*.cpp")
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

.PHONY: all
all: $(BIN)

.PHONY: clean
clean:
	rm -f $(BIN)

.PHONY: run
run: $(BIN)
	./$(BIN)

$(BIN): $(SRCS)
	$(CC) $(CXXFLAGS) -o $@ $^