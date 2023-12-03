#!/bin/bash

clear

# Diretório inicial
INITIAL_DIR=$(pwd)

# Entrando na pasta bison
cd bison || exit

# Executando o Bison
#echo "executing bison..."
bison -d -o parser.c parser.y

# Movendo os arquivos gerados para pasta src e include
#echo "moving parser.c and parser.h..."
mv parser.c ../src/
mv parser.h ../include/

# going back to the original directory
cd "$INITIAL_DIR" || exit

# going back to the original directory
cd "$INITIAL_DIR" || exit

# compiling all .c files in src folder
#echo "calling makefile..."
make -s

#echo "compiled successfully!"

#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all
#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./compiler test/example1.txt
#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./compiler test/example2.txt
#valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all 

#echo "testing with lexical error..."
./compiler test-lexical/example1.txt

#echo "testing with sintatic error..."
./compiler test-sintatic/example1.txt

#echo "testing with semantic error..."
./compiler test-semantic/example1.txt
./compiler test-semantic/example2.txt
./compiler test-semantic/example3.txt
./compiler test-semantic/example4.txt
./compiler test-semantic/example5.txt
./compiler test-semantic/example6.txt
./compiler test-semantic/example7.txt
./compiler test-semantic/example8.txt

