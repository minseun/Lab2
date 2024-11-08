calculate : main.o ./add.o ./subtract.o ./multiply.o ./divide.o
	gcc -o calculate main.o ./add.o ./subtract.o ./multiply.o ./divide.o ./divide.o -I./lib -L./lib
main.o : main.c
	gcc -c main.c -I./lib
./lib/add.o : ./add.c
	gcc -c ./add.c
./lib/subtract.o : ./subtract.c
	gcc -c ./subtract.c
./lib/multiply.o : ./multiply.c
	gcc -c ./multiply.c
./lib/divide.o : ./divide.c
	gcc -c ./divide.c

clean : 
	rm -f calculate main.o ./add.o ./subtract.o ./multiply.o ./divide.o ./divide.o
