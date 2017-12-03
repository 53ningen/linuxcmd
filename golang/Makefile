GO=go
BUILD=$(GO) build
FMT=$(GO) fmt

TARGETS    = hello echo
SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	$(BUILD) -o $(BIN_DIR)/$@ $(SRC_DIR)/$@.go

clean:
	-rm -f $(BIN_DIR)/*

fmt: $(TARGETS)
	$(FMT) $(SRC_DIR)/

test: all
	../test-script.sh

