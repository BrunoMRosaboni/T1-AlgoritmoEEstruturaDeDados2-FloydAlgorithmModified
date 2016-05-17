CC = gcc
CFLAGS = -Wall
DEPS = Floyd.h
OBJ = main.o Floyd.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -rf *.o

mrproper: clean
	rm -rf main

run:
	./main < Entrada.txt > Saida.txt
