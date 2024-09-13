# Name of the project
PROJ_NAME=main

# Clear Command
ifeq ($(OS),Windows_NT)
	REMOVE=del /Q .\lib\bin\*.o *.exe $(PROJ_NAME)
else
	REMOVE=rm -rf del /Q ./lib/bin/*.o *.exe $(PROJ_NAME) *~
endif


# files
BIN=lib/bin
SRC=lib/src

# Object files
OBJ=$(C_SOURCE:.c=.o)

# Compiler
CC=gcc

# Flags for compiler (add -g to debug)
CC_FLAGS=-c         \
         -g         \
         -I.        \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

#
# Compilation and linking
#
all: clean $(PROJ_NAME)
	$(CC) -o $(PROJ_NAME).exe $(BIN)/Point2d.o $(BIN)/Response.o $(BIN)/Error.o

$(PROJ_NAME): Point2d.o Response.o Error.o
	$(CC) -o $(BIN)/main.o main.c $(CC_FLAGS)

Point2d.o:
	$(CC) -o $(BIN)/Point2d.o $(SRC)/math/Point2d.c $(CC_FLAGS)

Response.o:
	$(CC) -o $(BIN)/Response.o $(SRC)/shared/Response.c $(CC_FLAGS)

Error.o:
	$(CC) -o $(BIN)/Error.o $(SRC)/shared/Error.c $(CC_FLAGS)

clean:
	$(REMOVE)