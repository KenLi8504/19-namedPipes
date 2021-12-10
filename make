all: user worker
	gcc -o user UI.o
	gcc -o worker worker.o

user: UI.c
	gcc -c UI.c

worker: worker.c
	gcc -c worker.c

clean:
	rm *.o
	rm user
	rm worker
