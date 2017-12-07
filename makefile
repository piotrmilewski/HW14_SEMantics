all: main.o
	gcc -o control main.o

main.o: main.c
	gcc -c main.c

run: all
	./control -c 17
	./control -v
	./control -c 68
	./control -v
	./control -r

clean:
	rm -rf *.o *~ control
