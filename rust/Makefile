RUSTC=rustc
BUILD=$(RUSTC)

TARGETS    = hello
SRC_DIR    = ./src
BIN_DIR    = ./bin

$(TARGETS):
	$(BUILD) $(SRC_DIR)/$@.rs -o $(BIN_DIR)/$@

all: $(TARGETS)

clean:
	-rm -f $(BIN_DIR)/*
