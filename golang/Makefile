GO=go
BUILD=$(GO) build

TARGETS    = hello
SRC_DIR    = ./src
BIN_DIR    = ./bin

$(TARGETS):
	$(BUILD) -o $(BIN_DIR)/$@ $(SRC_DIR)/$@.go

all: $(TARGETS)

clean:
	-rm -f $(BIN_DIR)/*
