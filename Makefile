CC = g++
BIN = nba
SRCS = $(shell find . -name "*.cpp")

.PHONY: all
all: $(BIN)

.PHONY: clean
clean:
	rm -f $(BIN)

.PHONY: run
run: $(BIN)
	./$(BIN)

$(BIN): $(SRCS)
	$(CC) -o $@ $(SRCS)