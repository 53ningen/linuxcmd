  CC=gcc
BUILD=$(CC)

TARGETS    =  hello \
              echo \
              cat \
              cat2 \
              head \
              bug_head \
              ls \
              tree \
              mkdir \
              ln \
              symlink \
              rm \
              mv \
              stat \
              chmod \
              touch \
              spawn \
              kill

SRC_DIR    = ./src
BIN_DIR    = ./bin

all: $(TARGETS)

$(TARGETS):
	-mkdir -p bin
	$(BUILD) $(SRC_DIR)/$@.c -o $(BIN_DIR)/$@ -Wall

clean:
	-rm -rf $(BIN_DIR)/*

test: all
	../test-script.sh
