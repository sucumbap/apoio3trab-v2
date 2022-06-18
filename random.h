#ifndef __RANDOM_H__
#define __RANDOM_H__

#define MAXRANDOM 256
typedef struct {
	int values[MAXRANDOM];
	int dimValues;
} Random;

// Cria um intervalo de inteiros para gerar numeros aleatórios unicos
Random newRandomInterval(int min, int max);
// Adiciona um novo intervalo de inteiros para gerar numeros aleatórios
Random addRandomInterval(Random r, int min, int max);
// Coloca em *value um número aleatório, dentro dos disponíveis.
// Devolve true se existir algum número disponível
int getRandom(Random *r);

#endif
