/// memoryGameGraphMain.c
/// 12/Maio/2022
/// comando Build: gcc -Wall -o t  memoryGame.c memoryGameGraph.c -lpg

#include "memoryGame.h"


//  Zona de variaveis GLOBAIS    ///////////////////////////////////////////////////
//  Justificaveis, porque as funções que operam eventos NÃO recebem mais parametros
//  e, por isso, as variaveis terão de ser globais para que as possam ser usada nas
//  nas funções sobre eventos 

/// variavel global t faz a contagem do tempo do cronometro 
Chronometer  t;              /// estrutura de contagem de tempo 
Game         player;         /// jogo de pares de letras em board e a gestão dos eventos


 
/**
 * retorna abcissa válida x em [0,MAXCOL-1] por via do click rato em meX 
 * que ocorre na consola grafica para acesso ao tabuleiro onde estão as letras  
 */
int xCoordinate( int meX )
{ /// o meX pixeis do rato é convertivel em 0,1,.,MAXCOL para acesso a board
  return (meX-(INIT_XQ))/(SIDE+DELTA);
}

/**
 * retorna a coordenada válida y em [0,MAXLINE-1] por via do click rato em meY 
 * que ocorre na consola grafica para acesso ao tabuleiro onde estão as letras  
 */
int yCoordinate( int meY )
{  /// o meY pixeis do rato é convertivel em 0,1,.,MAXLINE para acesso a board
   return (meY-(INIT_YQ))/(SIDE+DELTA);/// e retorna esse valor
}

/**
 * retorna valor em pixeis do indice inferior da celula relativamente ao indice 
 * do tabuleiro onde estão as letras  v
 */
int valueInfCell( int init, int v )
{
   return init + SIDE + v*(DELTA+SIDE);
}



/// definições das variaveis globais para o Chronometer t 
Chronometer chronometer_init( int h, int m, int s )
{
  Chronometer aux={h,m,s};
  return aux;
}


/**
 * 
 * as funções REGISTADAS dos eventos em main() servem para activar:
   - rato 
   - a função é SEMPRE execuda ao ritmo de ... enquanto o programa estiver em execução
   nota: cada uma desta funções registadas chamará outras funções adequadas a cada caso
   - o teclado NÃo está a ser utilizado
 */
 
 /// ---------------------sobre rato -------------------------------------------------
/**
 * função é registada no mouse em main() e assim é SEMPRE executada quando o utilizador
 * activa o rato e esta activação chama outras fuções que desencadeam outras acções.
 */  
void moveMouse( MouseEvent me )
{ 
  if( player.end )      return; /// fim do programa. Acertou em todos os pares de letras 
  if( player.paused ) return; /// pausa  após 2 letras clicadas 
  
  ///apenas estamos interessados em clicks no botão: LEFT
  if( me.type  == MOUSE_BUTTON_EVENT && me.button == BUTTON_LEFT  &&
      me.state == BUTTON_CLICK ){
  
    buttonLeft( me.x,me.y );/// chama esta função sempre que o botão esquerdo faz clik  
  }
}

/**
 * função é chamada quando se activa o botão esquerdo do rato e faz as validações
 * dentro do board grafica e dentro de cada célula 
 * chama buttonLeftClick( ); para jogar 1ª e 2ª letra
 */
void buttonLeft( int meX, int meY )
{
  int vTAB_MAX_X =((INIT_XQ + (player.tab.nC*(SIDE + DELTA)-DELTA)));///maximo board em XX
  int vTAB_MAX_Y =((INIT_YQ + (player.tab.nL*(SIDE + DELTA)-DELTA)));///e YY
 
  if( !between(meX,INIT_XQ, vTAB_MAX_X) || !between(meY, INIT_YQ, vTAB_MAX_Y) ) return; 
  
  
  /////// FALTA IMPLEMENTAR 
}

/**
 * A função com x,y acede ao tabuleiro das letras para jogar a 1º letra
 * no 1º click e depois jogar na 2ª letra no 2ºclick.
 * Para o 1ºclick e 2ºclick chama  game_play( );
 */
void buttonLeftClick( int x, int y )
{ 
   
  /////// FALTA IMPLEMENTAR 
}

// Mostra a letra na respetiva célula
void writeCell(Game *player, int lin, int col, char letter) {
  int x1_pixeis=((DELTA+INIT_XQ+SIDE)/2)+(col*(SIDE+DELTA));
  int y1_pixeis=((INIT_YQ+DELTA+SIDE)/2)+(lin*(SIDE+DELTA))+LARGE_FONT_SIZE; 
     
  graphLetter( x1_pixeis, y1_pixeis, c_yellow, letter, c_blue, LARGE_FONT );

}

/**
 * a função escreve a 1º letra do par na consola grafica em line1, cols1 no 1ºclick
 * e de seguida escreve a 2ª letra do par em line2,cols2 e analisa as duas letra se 
 * forem iguais serão marcadas como ocupadas com busy=1, caso contrario serão apagadas. 
 * Verificado se o jogo terminou com a chamada game_end_board( player )
 */
void game_play( Game *player, int line, int col, bool first )
{ 
  /////// FALTA IMPLEMENTAR 

} 

/**
 * retorna true se o tabuleiro estiver todas as letras ocupadas,
 * caso contrario retorna false
 */
bool game_end_board( Game *player ){
  /////// FALTA IMPLEMENTAR
  
  return true;
}

/// ---------------------sobre as temporizações ------------------------------------------
/**
 * Vamos registar executeChronometer() no timer no main() ao ritmo de um tempo estabelecido 
 * e assim esta é SEMPRE chamada durante a execução do programa. No caso usamos 1 segundo.
 */
 
/**
 * a função faz a contagem e afixação do tempo do cronometro e a verificação do 
 * tempo de pausa após a click dos sucessivos pares de letras por cada fim de
 * pausa escreve dois rectangulos na consola grafica para apagar as letras
 */ 
void executeChronometer() 
{
  if( !player.first ) return;         /// inicio do cronometro após 1º click no tabuleiro 
  if( player.end )    return;         /// fim do programa. Acertou em todas as letras
  
  chronometer(&t);                    /// contagem dos segundos, minutos e horas
  chronometerGraph(TIME_X,TIME_Y, &t);/// afixa horas,minutos,segundos na janela grafica  
 
 //
  if( player.paused ){
	  player.ct++;    ///começa a contagem do tempo de pausa
    
	  /////// FALTA IMPLEMENTAR

  }
}

/// ----------------- sobre texto na consola gráfica -------------
/**
 * escreve texto grafico a partir x,y com cor letra corL e com cor de fundo corF e 
 * tamanho da letra dimL que pode ser SMALL_FONT ou MEDIUM_FONT ou LARGE_FONT
 */
void msgGraphic( int x, int y, RGB corL, char txt[], RGB corF, int dimL )
{
  int TAB_LETTER_X[4]={0, 8,10,20}; /// SMALL_FONT,MEDIUM_FONT,LARGE_FONT, indices 1,2,3
  int TAB_LETTER_Y[4]={0,10,16,26}; /// SMALL_FONT,MEDIUM_FONT,LARGE_FONT, indices 1,2,3 

  ///"apagar" letras, é desenhar rectangulo com as medidas w,h e com a mesma cor de fundo
  graph_rect(x, y, TAB_LETTER_X[dimL]*strlen(txt), -TAB_LETTER_Y[3], corF, true);
  ///escrever o texto com uma dada cor e tamanho a partir de x,y  
  graph_text(x, y, corL, txt, dimL); /// SMALL_FONT MEDIUM_FONT LARGE_FONT             
}
/**
 * a função escreve na consola grafica uma letra
 */
void graphLetter( int x, int y, RGB corL, char c, RGB corF, int dimL )
{
  char txt[]={c,0}; /// constroi uma string com uma só letra contida em c
  msgGraphic( x, y, corL, txt, corF, dimL );
}

/// ----------------- sobre a gestão do tempo na consola gráfica -------------
/**
 * escreve cronometro na consola grafica em x,y
 */
void chronometerGraph(int x, int y, const Chronometer *t )
{
  char time[10];
  /// forma a string tempo a partir das variáveis globais: horas, minutos, segundos
  sprintf(time,"%02d:%02d:%02d", t->hours, t->minutes, t->seconds);  
  msgGraphic( x, y, c_blue, time, c_white, MEDIUM_FONT );/// "apaga" e escrever texto
}  


/**
 * faz actualização do cronometro na variavel t do tipo Tempo
 */
void chronometer( Chronometer *t )
{
  t->seconds++; 
  if( t->seconds == 60 ) {
     t->seconds = 0;
     t->minutes++;
     if( t->minutes == 60 ) t->hours = (t->hours + 1) % 24;
  }
}
/**
 * Desenha na consola grafica um tabuleiro grafico a partir de x0, y0, com quadriculas de 
 *  cor c1 e de lado por lado e separadas entre si por um delta com a moldura de cor c2 
 */
void game_graphicBoard( int x0, int y0, int l, int c, 
                        RGB c1, bool f1, RGB c2, bool f2, int side, int delta ){
  for( int y=0; y<l; ++y ){     /// l total de linhas
    for( int x=0; x<c; ++x ){   /// c total de colunas
      /// desenha as quadriculas 
      graph_rect( x0 + x*(side+delta), y0 + y*(side+delta), side, side, c1, f1);  
      /// faz a moldura das quadriculas 
      graph_rect( x0 + x*(side+delta)-delta/2, y0 + y*(side+delta)-delta/2, 
                  side+delta, side+delta, c2, f2);  
    }
  }
}

int main() {
 ///comando build: gcc -Wall -o t  memoryGame.c memoryGameGraph.c -lpg
 //=================================== parte da consola terminal
  srand( time(0));
    
  char txt[MAXCHAR]; /// forma uma string para o sprintf
  int nL, nC ;       /// linhas e colunas correntes, em que 1<=nL<=MAXLINE,1<=nC<=v_MAXCOL               
  
  sprintf(txt,"Quantas linhas  quer para o Tabuleiro entre [4, %d]? " ,MAXLINE);
  nL = read_int_between(txt,MIN_LINES, MAXLINE);
  int v_MAXCOL=(LETTERS*2)/nL; /// o maximo de colunas é v_MAXCOL em concordancia com nL
  sprintf(txt,"Quantas colunas quer para o Tabuleiro entre [4,%d]? " ,v_MAXCOL);
  nC = read_int_between(txt,MIN_COLS, v_MAXCOL);
  
  /// variavel global para o tabuleiro é player.tab
  (player.tab).nL= nL;
  (player.tab).nC= nC; 
  
  int ctLetter = (nL*nC);     /// o total de letras é concordante com dimensões da board
  if( ctLetter%2==1 ) { printf("ERRO- %dx%d=%d Não é par!\n",nL,nC,ctLetter); exit(0); }
 
  /// gerar o tabuleiro de jogo na variavel global  player.tab.board
  game_generate(&player);
   
  /// inicio da parte grafica onde se cria a consola grafica de 1200 por 550 pixeis
  //graph_init2("Game Of Memory", MAX_LARG, MAX_ALT); 
  graph_init2("Game Of Memory", INIT_XQ+(SIDE+DELTA)*nC, INIT_YQ +(SIDE+DELTA)*nL); 
   
  ///=== Vamos REGISTAR os enventos de rato e de temporização ====================
  /// ==== registo da função moveMouse() que trata eventos de rato. 
  /// Esta função é SEMPRE chamada quando o utilizador "activa/mexe" o rato
  graph_regist_mouse_handler( moveMouse );
  
  /// ==== registo da função que é chamada ao ritmo de um tempo, neste caso 1000==1s 
  ///Esta função está SEMPRE durante a  execução do programa 
  graph_regist_timer_handler( executeChronometer, 1000 );
  
  graph_text( INIT_TXT_X, INIT_TXT_Y, c_blue, "Game Memory of Letters", MEDIUM_FONT);
  game_graphicBoard(INIT_XQ,INIT_YQ, nL, nC, c_blue,true, c_black, false, SIDE, DELTA );
   
  t = chronometer_init(0,0,0);
  chronometerGraph(TIME_X,TIME_Y, &t);

  graph_start(); /// mantem activa a consola grafica de MAX_LARG por MAX_ALT pixeis

  printf("\n");
  return 0;
}
