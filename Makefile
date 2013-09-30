all: mergeSort mergeSort1 mergeSort2
mergeSort: ./src/mergeSort.c ./src/common.c
	gcc -g -O3 -o ./bin/merge.o ./src/mergeSort.c ./src/common.c
mergeSort1: ./src/mergeSort1.c ./src/common.c
	gcc -g -O3 -o ./bin/merge1.o ./src/mergeSort1.c ./src/common.c
mergeSort2: ./src/mergeSort2.c ./src/common.c
	gcc -g -O3 -o ./bin/merge2.o ./src/mergeSort2.c ./src/common.c
clean:
	rm -f ../bin/*.o
