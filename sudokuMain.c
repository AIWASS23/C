#include "sudokuFuncoes.c"

int main(){
    
    int opcao;
    int checaTabuleiro = 0, fimJogo = 0, tamOpcao = 0;
    int tabuleiro[tam][tam]; /*Matriz que gera o tabuleiro do jogo*/
    int seguranca[tam][tam]; /*Matriz usada apenas para chegar os imutaveis*/
    lista *listaSimples= NULL;
    circular* ponteiroInicial = NULL;
    circular* ponteiroFinal = NULL;

    iniciarTabuleiro(tabuleiro,seguranca);
    gerarAleatorios(tabuleiro,seguranca);
    
    while((opcao != 6) && (fimJogo != 1)){
        system("clear");
        menu(tabuleiro, seguranca);
        opcao = verificaNumero();
        
        switch(opcao){          
            case 1:
                inserirJogada(tabuleiro, seguranca, &ponteiroInicial, &ponteiroFinal);               
                checaTabuleiro = verificarFim(tabuleiro);
                getchar();
                if(checaTabuleiro == 0){
                    fimJogo = 1;
                }
                break;
            case 2:
                    alterarJogada(tabuleiro, seguranca, &ponteiroInicial, &ponteiroFinal);
                    break;
            case 3:
                    anulaJogada(tabuleiro, seguranca, &ponteiroInicial, &ponteiroFinal);
                    break;
            case 4:
                   listaSimples = verificaPossibilidades(tabuleiro, seguranca, listaSimples);
                   possibilidades(listaSimples);
                   deletaPossibilidadesRecursivo(&listaSimples);
                   break;
            case 5:
                   imprimeCircular(&ponteiroFinal);
                   getchar();
                   break;
            case 6:
                do{
                    system("clear");
                    menu(tabuleiro, seguranca);
                    menuJogada();
                    opcao = verificaNumero();
                    if((opcao != 6) && (opcao != 1)){
                        opcaoinvalida();
                    }
                }while((opcao != 6) && (opcao != 1));
                break;
                
            default:
                opcaoinvalida();
        }    
    }    
    resultadoFinal(fimJogo);
    return 0 ;
}
   
