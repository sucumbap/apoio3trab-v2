/// memoryGame.h
/// 12/Maio/2022


#include <stdio.h>
#include <stdbool.h>
#include <math.h>   
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#include "pg/pglib.h"  /// ler/estudar o ficheiro graphicslib.pdf

#define LARGE_FONT_SIZE 26

//===================================================================
#define MAXLINE      5 /// dimensões maximas do tabuleiro para linhas e colunas
#define MIN_COLS	 4 /// Número mínimo de linhas
#define MIN_LINES	 4 /// Número mínimo de colunas
#define MAXCOL      13 /// Número
#define LETTERS     26 /// total de letras maiúscula
#define MAXCHAR    100 /// dimensão máxima para string's 

//===================================================================

#define MAX_LARG  1200  /// dimensões da consola grafica de 1200 por 550
#define MAX_ALT    550     

#define TIME_X     300  /// localização no eixo do XX do cronometro na consola grafica 
#define TIME_Y      30  /// localização no eixo do YY do cronometro na consola grafica

#define INIT_TXT_X  10  /// inicio do texto no eixo do XX 
#define INIT_TXT_Y  30  /// inicio do texto no eixo do YY 

#define SIDE        80  /// dimensão de cada quadrícula na consola grafica
#define DELTA       10  /// intervalo entre em quadricula no eixo XX e no eixo YY 
#define INIT_XQ  ((INIT_TXT_X) + (DELTA))/// inicio em XX da 1ª quadricula
#define INIT_YQ  ((INIT_TXT_Y) + (DELTA))/// inicio em YY da 1ª quadricula
  
#define PAUSETIME    3  /// apaga as 2 letras em 3 segundos. É a pausa de visualização

            
typedef struct {
    char letter;               /// letra jogada
    int  busy;                 /// ocupado=1(letra não jogavel) livre=0 (letra jogavel)
} Cell;
	
typedef struct 
{
    Cell board[MAXLINE][MAXCOL];/// tabuleiro de dimensões maximas
    int nL, nC;                 /// dimensões correntes do tabuleiro
} Board;

typedef struct {
   Board tab;                  /// tabuleiro de jogo
  
   // variaveis de gestão do jogo 
   int line1, cols1;           /// coordenada do 1ºclick
   int line2, cols2;           /// coordenada do 2ºclick
   char letter1, letter2;      /// as letras associadas ao 1º e 2º click

   bool end;                   /// controlo do fim do programa    
   bool first;                 /// Indica se já existe a primeira célula selecionada
   bool firstClick;            /// 1º click na letras (inicia contagem do cronometro )
   bool paused;                /// activa o bloqueio da consola gráfica para PAUSETIME seg
   int  ct;                    /// conta tempo PAUSETIME seg de fecho da consola grafica 

} Game;

/// este tipo Chronometer quantifica  os dados da contagem de tempo
typedef struct {
  int hours, minutes, seconds;
}Chronometer;
 

/// ASSINATURAS de funções ///////////////

//================================================================================
void readChars();
int read_int( const char txt[] );
int read_int_between( const char txt[], int inf, int sup );

bool between( int v, int inf, int sup);/// dá true se o v está no intervalo [inf, sup]
int  xCoordinate( int meX );           /// retorna x em board 0,1,.,MAXCOL via meX pixel
int  yCoordinate(int meY );            /// retorna y em board 0,1,.,MAXLINE via meY pixel
int  valueInfCell( int init , int v ); /// retorna indice pixel inferior da cell via  v

void game_graphicBoard( int x0, int y0, int l, int c, RGB c1, bool f1, 
                        RGB c2, bool f2, int side, int delta );

///preenche a board com os valores dos arrays idxRandom e letterRandom
void game_generate( Game *player); 
void game_play( Game *player, int line, int col, bool first );
bool game_end_board( Game *player );

void moveMouse( MouseEvent me );     /// chamada quando há click do rato e chama buttonLeft()
void buttonLeft( int meX, int meY ); /// faz validações de localização sobre as celulas
void buttonLeftClick( int x, int y );/// é chamada em buttonLeft()  nos click par de letras


void executeChronometer();             /// é SEMPRE chamada DURANTE a execução do programa
void chronometer( Chronometer *t );                         /// faz a contagem do tempo 
void chronometerGraph( int x, int y, const Chronometer *t );/// afixa tempo consola grafica
void chronometerInit( int h, int m, int s) ;                /// inicia o tempo com h,m,s
  
  
void msgGraphic( int x, int y, RGB corL, char txt[], RGB corF, int dimL );///msg grafica
void graphLetter( int x, int y, RGB corL, char c, RGB corF, int dimL );   ///char grafico
