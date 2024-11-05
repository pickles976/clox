

all:
	gcc -o clox.exe main.c chunk.c memory.c

clean:
	rm -f main.o 
	rm -f clox.exe