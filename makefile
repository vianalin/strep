all: strep.o
	gcc -o strep strep.o
strep.o: strep.c
	gcc -c strep.c
run: strep
	./strep
clean:
	rm *.o
	rm strep
