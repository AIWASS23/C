


/*BIBLIOTECAS NECESSARIAS PARA O FUNCIONAMENTO CORRETO DO PROGRAMA.*/
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

/*ATALHO PARA CORES QUE SERÂO UTLIZADAS NO PROGRAMA*/
#define vermelho  printf("\33[0;31m")
#define verde     printf("\33[0;32m")
#define azul      printf("\33[0;34m")  
#define branco    printf("\33[0;39m")
#define roxo      printf("\33[0;35m")

#define intervaloSuperiorBlock1  2 
#define intervaloSuperiorBlock2  5 
#define intervaloInferiorBlock2  3
#define intervaloInferiorBlock3  6 
#define intervaloSuperiorBlock3  8

#define valorMinimo 1
#define invalido -1
#define termina 4
#define valido 0
#define nulo 0
#define tam 9

/*Estrutura que será utilizada para implementação
 da lista*/
struct lista{
  int possibilidade;
  struct lista *proximo;
};

typedef struct lista lista;

struct listaDuplaCircular{
  int coluna;
  int linha;
  int valor;

  struct listaDuplaCircular *proximo;
  struct listaDuplaCircular *anterior;
};

typedef struct listaDuplaCircular circular;


/*================================================================================================================================================================*/
/*|                             PRINCIPAIS FUNÇÔES UTILIZADAS PARA ELABORAÇÂO E MANIPULAÇÂO DO SUDOKU -                                              |*/
/*=================================================================================================================================================================*/
int verificarBloco(int tabuleiro[][tam], int linhaHorizontalInicial, int linhaVerticalIncial, int linhaHorizontalFinal,  int linhaVerticalFinal,  int jogada);
int verificarJogada(int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int numero, int seguranca[][tam]);
void jogada(int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int numero, int seguranca[][tam],circular** ponteiroInicial, circular** ponteiroFinal);
int localizarBloco( int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int jogada);
int verificarColuna(int tabuleiro[][tam], int linhaVertical, int jogada);
int verificarLinha(int tabuleiro[][tam], int linhaHorizontal, int jogada);
void mostrarTabuleiro(int tabuleiro[][tam], int seguranca[][tam]);
void iniciarTabuleiro(int tabuleiro[][tam], int seguranca[][tam]);
int quantidadeJogadas(int tabuleiro[][tam], int seguranca[][tam]);
void gerarAleatorios(int tabuleiro[][tam], int seguranca[][tam]);
void inserirJogada(int tabuleiro[][tam], int seguranca[][tam],circular** ponteiroInicial, circular** ponteiroFinal);
void anulaJogada(int tabuleiro[][tam], int seguranca[][tam],circular** ponteiroInicial, circular** ponteiroFinal);
int verificarFim(int tabuleiro[][tam]);
void resultadoFinal(int fimJogo);
int recebeLinhaHorizontal();
int recebeLinhaVertical();
int verificaNumero();
int recebeNumero();

/*================================================================================================================================================================*/
/*|                             PINRCIPAIS FUNÇÔES UTILIZADAS PARA ELABORAÇÂO E MANIPULAÇÂO DA LISTA DE POSSIBILIDADES                              |*/
/*=================================================================================================================================================================*/
lista* inserePossibilidadesListaRecursiva(int tabuleiro[][tam], int seguranca[][tam], lista* inicio, int  linhaHorizontal, int linhaVertical, int contador);
lista* verificaPossibilidades(int tabuleiro[][tam], int seguranca[][tam], lista* inicio);
lista* inserePossibilidades(lista* inicio,int possibilidade);
void imprimePossibilidadesRecursivo(lista **inicio);
void deletaPossibilidadesRecursivo(lista **inicio);
lista* ponteiroFinalRecursivo(lista* inicio);
void possibilidades(lista* inicio);
lista* criaNo(int possibilidades);

/*================================================================================================================================================================*/
/*|                             PINRCIPAIS FUNÇÔES UTILIZADAS PARA ELABORAÇÂO E MANIPULAÇÂO DA LISTA DUPLA CIRCULAR                              |*/
/*=================================================================================================================================================================*/
circular* criaNoCircular(int valor, int coluna, int linha);
int removeJogadaCircular(circular** ponteiroInicial, circular** ponteiroFinal,int coluna, int linha);
void insereInicioCircular(circular** ponteiroInicial, circular** ponteiroFinal, int valor, int coluna, int linha);
void alterarJogada(int tabuleiro[][tam], int seguranca[][tam], circular** ponteiroInicial, circular** ponteiroFinal);
void imprimeCircular(circular** ponteiroFinal);

/*================================================================================================================================================================*/
/*|                             FUNÇÔES UTILIZADAS PARA MOSTRAR MENSAGENS OU MENUS (ACESSIBILIDADE).                                                              |*/
/*=================================================================================================================================================================*/ 
void menu(int tabuleiro[][tam], int seguranca[][tam]);
void jogadaRealizada();
void jogadaInvalida();
void opcaoinvalida();
void menuInicial();
void menuJogada();












