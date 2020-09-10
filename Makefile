dict: main.o list.o recorddata.o finddata.o
	gcc main.o list.o recorddata.o finddata.o -o dict

main.o: main.c header.h
	gcc -c -g main.c 

list.o: list.c header.h
	gcc -c -g list.c 

recorddata.o: recorddata.c header.h
	gcc -c -g recorddata.c 

finddata.o: finddata.c header.h
	gcc -c -g finddata.c 

clean:
	rm *.o output