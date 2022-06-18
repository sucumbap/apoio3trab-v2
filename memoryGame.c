/// memoryGame.c
/// 12/Maio/2022

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include "random.h"
#include "memoryGame.h"

#define LETTERS     26 /// total de letras maiúscula

/**
 * DEFINIÇÕES das funções em que as assinaturas estão escritas em memoryGame.h ====
 */
 
 ///lê caractere a caractere até fim de linha e ignora-os
void readChars()
{
   while( getchar()!='\n');
}

///lê um valor inteiro do teclado com recuperação de erro caso ocorra 
int read_int( const char txt[] )
{
  bool   b = false;
  int v = 0;
  char   c = 0;
  int    r = 0;
  do{
    printf("%s",txt);
    r = scanf("%d%c", &v, &c );
    b = r != 1 && (c!='\t' && c!='\n' && c!=' ');
    if( b ) 
    {
      printf("ERRO - novo valor:\n");
      readChars();
    }
  }while( b );
  return v;
}

///lê um valor inteiro com recuperação de erro caso ocorra fora do intervalo [inf,sup]
int read_int_between( const char txt[], int inf, int sup )
{
   bool   b = false;
   int v = 0;
   do{
      v = read_int(txt);
      b = v<inf || v>sup;
      if( b ) 
      {
        printf("ERRO - novo valor: ");
      }
   }while( b );
   return v;
}

/**
 * retorna true se v dentro do intervalo [inf,sup] e false caso contrario
 */
bool between( int v, int inf, int sup ){   return v>=inf && v<=sup; }


/// gera para player board um jogo com as letras e com os indices.
/// chamar as funções de Random.c para gerar esses aleatórios
void game_generate( Game *player )
{
    ////// FALTA IMPLEMENTAR
}