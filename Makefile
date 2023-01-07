.PHONY: build clean default

print-%: ; @echo $*=$($*)
CC=clang
CFLAGS=-std=c++17 -Wstring-plus-int -Wnull-conversion
INC=-I/usr/local/include
LIBS=-lreadline
BIN_NAME=clover
INCLUDEDIR=src/cpp/clover/lang/

# Strip and Compress Flags
STRIP=strip

build: clean
	@echo "Compiling clover ..."
	@time g++ -Ofast -c main.cpp -I $(INCLUDEDIR) -I $(INCLUDEDIR)/*.cpp $(CFLAGS)
	@mv *.o obj/
	@echo "Building Clover ..."
	@g++ -Ofast obj/*.o -o $(BIN_NAME)
	@echo 'clover built'

clean:
	@echo "Cleaning previous compiled files."
	@rm -rf obj/*.o
	@rm -rf clover
run:
	@./clover

compress:
	$(STRIP) $< $(BIN_NAME)

all: build
