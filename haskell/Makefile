GHC=ghc
BUILD=$(GHC) build

TARGETS    = hello echo
SRC_DIR    = ./src
BIN_DIR    = ./bin
HI_DIR     = ./hi
O_DIR      = ./o

all: $(TARGETS)

$(TARGETS):
	stack ghc -- ./src/$@.hs -o ./bin/$@ -odir $(O_DIR)/$@.o -hidir $(HI_DIR)/$@.hi

clean:
	-rm -f $(BIN_DIR)/* $(O_DIR)/* $(HI_DIR)/*

test: all
	../test-script.sh
