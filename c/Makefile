CC=gcc
BUILD=$(CC)

TARGETS    = hello echo
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	-mkdir -p bin
	$(BUILD) $(SRC_DIR)/$@.c -o $(BIN_DIR)/$@

clean:
	-rm -f $(BIN_DIR)/*

test: all
	../test-script.sh
