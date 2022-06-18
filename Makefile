memory_demo: memoryGameGraph.o memoryGame.o random.o
	gcc -g -Wall -o memory memoryGameGraph.o \
		memoryGame.o random.o -lpg

memoryGameGraph.o: memoryGameGraph.c memoryGame.h
	gcc -g -Wall -c memoryGameGraph.c

memoryGame.o: memoryGame.c memoryGame.h random.h
	gcc -g -Wall -c memoryGame.c

random.o: random.c random.h
	gcc -g -Wall -c random.c
