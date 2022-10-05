main: main.c
	gcc -o main main.c

main.o: main.c
	gcc -c main.o

clean:
	rm main.o
