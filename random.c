#include <stdlib.h>
#include <stdbool.h>
#include "random.h"

// Cria um intervalo de inteiros para gerar numeros aleatórios unicos
// retornando um Random com os campos preenchidos
Random newRandomInterval(int min, int max) {
	Random r;
	for(int j = 0; j <= MAXRANDOM -1; j++) {
		r.values[j] = j;
	}
	int count = (min * max) / 2;
	int arrayChangebleSize = MAXRANDOM;
	int trueArray[count];
	for (int i = 0; i <= count; i++) {
		int arrayIndexRandNum = getRandomNumber();
		trueArray[i] = r.values[arrayIndexRandNum];
		for (int j = 0; j < arrayChangebleSize -1; j++) {  
            r.values[j] = r.values[j+1];
        }
	}
	for (int i = 0; trueArray[i] != NULL; i++) {
		r.values[i] = trueArray[i];
	}
	r.dimValues = MAXRANDOM - count;
	return r;
}
// Adiciona um novo intervalo de inteiros para gerar numeros aleatórios ao
// Random r passado em parametro, sendo este retornado já actualizado. 
Random addRandomInterval(Random r, int min, int max) {

	int count = (min * max) / 2;
	
	for(int j = 0; j <= MAXRANDOM; j++) {
		r.values[j] = j;
	}
	int arrayChangebleSize = MAXRANDOM - count;
	int trueArray[count];
	for (int i = 0; i <= count; i++) {
		int arrayIndexRandNum = getRandomNumber();
		trueArray[i] = r.values[arrayIndexRandNum];
		for (int j = 0; j < arrayChangebleSize -1; j++) {  
            r.values[j] = r.values[j+1];
        }  
	}
	for (int i = count; trueArray[i] != NULL; i++) {
		r.values[i] = trueArray[i];
	}
	r.dimValues = r.dimValues - count;
	return r;
}

// Retorna um numero aleatório dentro dos disponíveis no campo values de *r e
// actualiza o values, substituindo este pelo ultimo. Caso não exista nenhum
// retorna -1
int getRandom( Random *r ) {

	int j = rand() % r->dimValues;

	int v= r->values[j];
	r->values[j] = r->values[--r->dimValues];
	return v;	
}


int getRandomNumber() {
	int low = 0, hi = 0;
	if (0 < MAXRANDOM) {
		low = 0;
		hi = MAXRANDOM;
	} else {
		low = MAXRANDOM;
		hi = 0;
	}
	int result = (rand() % (hi - low)) + low;
	return result;
}