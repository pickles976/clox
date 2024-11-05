

all:
	gcc -o clox.exe main.c chunk.c memory.c debug.c

clean:
	rm -f main.o 
	rm -f clox.exe