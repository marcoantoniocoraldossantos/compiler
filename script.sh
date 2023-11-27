#!/bin/bash

# Diretório inicial
INITIAL_DIR=$(pwd)

# Entrando na pasta bison
cd bison || exit

# Executando o Bison
echo "executing bison..."
bison -d -o parser.c parser.y

# Movendo os arquivos gerados para pasta src e include
echo "moving parser.c and parser.h..."
mv parser.c ../src/
mv parser.h ../include/

# going back to the original directory
cd "$INITIAL_DIR" || exit

# going back to the original directory
cd "$INITIAL_DIR" || exit

# compiling all .c files in src folder
echo "calling makefile..."
make -s

echo "compiled successfully!"
./compiler test/example1.txt
