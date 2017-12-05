SC=swiftc
BUILD=$(SC)

TARGETS    = hello echo
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	$(BUILD) ./src/$@.swift -o ./bin/$@

clean:
	-rm -f $(BIN_DIR)/*

test: all
	../test-script.sh
