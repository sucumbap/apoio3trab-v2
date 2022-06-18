#include <stdlib.h>
#include <stdbool.h>
#include "random.h"

// Cria um intervalo de inteiros para gerar numeros aleatórios unicos
// retornando um Random com os campos preenchidos
Random newRandomInterval(int min, int max) {
	Random r;
	r.dimValues = 0;
	for(int i = 0; i <= MAXRANDOM; i++) {
		r.values[i] = getRandomNumber(min, max);		
	}
	return r;
}

// Adiciona um novo intervalo de inteiros para gerar numeros aleatórios ao
// Random r passado em parametro, sendo este retornado já actualizado. 
Random addRandomInterval(Random r, int min, int max) {
	for(int i = 0; i <= MAXRANDOM; i++) {
		r.values[i] = getRandomNumber(min, max);		
	}	
	return r;
}

// Retorna um numero aleatório dentro dos disponíveis no campo values de *r e
// actualiza o values, substituindo este pelo ultimo. Caso não exista nenhum
// retorna -1
int getRandom( Random *r ) {
	int v=0;
	int i = getRandomNumber(0, MAXRANDOM);
	if ( r->values[i] == 0 ) {
		v = -1;
	} else {
		v = r->values[i];
		r->values[i] = v;
	}
	return v;	
}


int getRandomNumber(int min, int max) {
	int low = 0, hi = 0;
	if (min < max) {
		low = min;
		hi = max;
	} else {
		low = max;
		hi = min;
	}
	int result = (rand() % (hi - low)) + low;
	return result;
}