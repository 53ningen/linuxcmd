RUSTC=rustc
BUILD=$(RUSTC)

TARGETS    = hello echo
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	$(BUILD) $(SRC_DIR)/$@.rs -o $(BIN_DIR)/$@

clean:
	-rm -f $(BIN_DIR)/*

test: all
	../test-script.sh

