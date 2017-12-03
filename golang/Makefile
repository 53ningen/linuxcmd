GO=go
BUILD=$(GO) build

TARGETS    = hello
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	$(BUILD) -o $(BIN_DIR)/$@ $(SRC_DIR)/$@.go

clean:
	-rm -f $(BIN_DIR)/*
