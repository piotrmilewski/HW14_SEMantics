all: main.o
	gcc -o control main.o

main.o: main.c
	gcc -c main.c

run: all
	./control

clean:
	rm -rf *.o *~ control
