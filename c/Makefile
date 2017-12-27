CC=gcc
BUILD=$(CC)

TARGETS    = main hello echo cat cat2
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	-mkdir -p bin
	$(BUILD) $(SRC_DIR)/$@.c -o $(BIN_DIR)/$@ -Wall

clean:
	-rm -f $(BIN_DIR)/*

test: all
	../test-script.sh
