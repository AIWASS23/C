# include "sudoku.h"

void iniciarTabuleiro(int tabuleiro[][tam], int seguranca[][tam]){
  
    int linhaVertical = nulo;
    int linhaHorizontal = nulo;
    while(linhaHorizontal < tam){
        linhaVertical = nulo;
        while(linhaVertical < tam){
        tabuleiro[linhaHorizontal][linhaVertical] = nulo;
        seguranca[linhaHorizontal][linhaVertical] = nulo;
        linhaVertical = linhaVertical + valorMinimo;
        }
        linhaHorizontal = linhaHorizontal + valorMinimo;    
    }
}

int verificarColuna(int tabuleiro[][tam], int linhaVertical, int jogada){
    
    int verificador = nulo;
    int linhaHorizontal = nulo;
   
    while(linhaHorizontal < tam){
        if(tabuleiro[linhaHorizontal][linhaVertical] == jogada){
            verificador = verificador + valorMinimo;
        }
        linhaHorizontal = linhaHorizontal + valorMinimo;
    }
    return verificador;
}

int verificarLinha(int tabuleiro[][tam], int linhaHorizontal, int jogada){
   
   int verificador = nulo;
   int linhaVertical = nulo;
  
    while(linhaVertical < tam){
        if (tabuleiro[linhaHorizontal][linhaVertical] == jogada){
            verificador = verificador + valorMinimo;
        }
        linhaVertical = linhaVertical +valorMinimo;
    }
    return verificador;
}

int  verificarBloco(int tabuleiro[][tam], int linhaHorizontalInicial, int linhaVerticalInicial, int linhaHorizontalFinal, int linhaVerticalFinal, int jogada){

    int verificador = nulo;
    int linhaVerticalAuxiliar = linhaVerticalInicial;
   
    while(linhaHorizontalInicial <= linhaHorizontalFinal){
        linhaVerticalInicial = linhaVerticalAuxiliar;
        while(linhaVerticalInicial <= linhaVerticalFinal){
          if(tabuleiro[linhaHorizontalInicial][linhaVerticalInicial] == jogada){
                verificador = verificador + valorMinimo;
            }
            linhaVerticalInicial = linhaVerticalInicial + valorMinimo;
        }
        linhaHorizontalInicial = linhaHorizontalInicial + valorMinimo;
    }
    return verificador;
}

int localizarBloco( int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int jogada) {
    
    int verificador = nulo;

   
    if(linhaHorizontal <= intervaloSuperiorBlock1){
        if(linhaVertical <= intervaloSuperiorBlock1){
            verificador = verificarBloco(tabuleiro,nulo,nulo,intervaloSuperiorBlock1,intervaloSuperiorBlock1,jogada);
        }
        if((linhaVertical > intervaloSuperiorBlock1) && (linhaVertical <= intervaloSuperiorBlock2)){
            verificador = verificarBloco(tabuleiro,nulo,intervaloInferiorBlock2,intervaloSuperiorBlock1,intervaloSuperiorBlock2,jogada);
        }
        if(linhaVertical > intervaloSuperiorBlock2){
            verificador = verificarBloco(tabuleiro,nulo,intervaloInferiorBlock3,intervaloSuperiorBlock1,intervaloSuperiorBlock3,jogada);
        }
    }
    if((linhaHorizontal > intervaloSuperiorBlock1) && (linhaHorizontal <= intervaloSuperiorBlock2)){
        if(linhaVertical <= intervaloSuperiorBlock1){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock2,nulo,intervaloSuperiorBlock2,intervaloSuperiorBlock1,jogada);
        }
        if((linhaVertical > intervaloSuperiorBlock1) && (linhaVertical <= intervaloSuperiorBlock2)){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock2,intervaloInferiorBlock2,intervaloSuperiorBlock2,intervaloInferiorBlock2,jogada);
        }
        if(linhaVertical > intervaloSuperiorBlock2){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock2,intervaloInferiorBlock3,intervaloSuperiorBlock2,intervaloSuperiorBlock3,jogada);
        }
    }
    if(linhaHorizontal > intervaloSuperiorBlock2){
        if(linhaVertical <= intervaloSuperiorBlock1){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock3,nulo,intervaloSuperiorBlock3,intervaloSuperiorBlock1,jogada);
        }
        if((linhaVertical > intervaloSuperiorBlock1) && (linhaVertical <= intervaloSuperiorBlock2)){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock3,intervaloInferiorBlock2,intervaloSuperiorBlock3,intervaloSuperiorBlock2,jogada);
        }
        if(linhaVertical > intervaloSuperiorBlock2){
            verificador = verificarBloco(tabuleiro,intervaloInferiorBlock3,intervaloInferiorBlock3,intervaloSuperiorBlock3,intervaloSuperiorBlock3,jogada);
        }
    }
    return verificador;
    
}

void gerarAleatorios(int tabuleiro[][tam], int seguranca[][tam]){
   
    int aleatorio, linhaHorizontal, linhaVertical;
    int incremento = nulo;
   
    while(incremento < tam){
        srand(time(NULL));
        aleatorio = rand()%9+1;
        linhaHorizontal = rand()%9;
        linhaVertical = rand()%9;
        while(tabuleiro[linhaHorizontal][linhaVertical] != nulo){
            linhaHorizontal = rand()%9;
            linhaVertical = rand()%9;
            }
        while((localizarBloco(tabuleiro, linhaHorizontal, linhaVertical, aleatorio)
                    || verificarColuna(tabuleiro, linhaVertical, aleatorio)
                    || verificarLinha(tabuleiro, linhaHorizontal, aleatorio)) != valido){
            aleatorio = rand()%9+1;
            }
           tabuleiro[linhaHorizontal][linhaVertical] = aleatorio;
           seguranca[linhaHorizontal][linhaVertical] = aleatorio;
           incremento = incremento + valorMinimo;
    }
}

void mostrarTabuleiro(int tabuleiro[][tam], int seguranca[][tam]){
    
    int linhaVertical = nulo;
    int linhaHorizontal = nulo;
    int intervaloInferior = 3;
    vermelho; printf("|---+-1--2--3-+-4--5--6-+-7--8--9-|\n");
    while(linhaHorizontal < tam){
        vermelho; printf("| %d |",linhaHorizontal + valorMinimo);
        linhaVertical = nulo;
        while(linhaVertical < tam){
            azul;
           if(tabuleiro[linhaHorizontal][linhaVertical] != valido){
               if(seguranca[linhaHorizontal][linhaVertical] == tabuleiro[linhaHorizontal][linhaVertical]){
                   roxo;
               }else{
                   verde;
               }
            }
            printf(" %d ",tabuleiro[linhaHorizontal][linhaVertical]);
            linhaVertical = linhaVertical + valorMinimo;
            if((linhaVertical % intervaloInferior) == valido){
               vermelho; printf("|");
            }
        }
        printf("\n");
        linhaHorizontal = linhaHorizontal + valorMinimo;
        if((linhaHorizontal % intervaloInferior) == valido){
           vermelho; printf("----+---------+---------+---------+\n");
        }
    }
 }

int verificarJogada(int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int numero, int seguranca[][tam]){
   
   int verificador = nulo;

   if((linhaHorizontal == invalido || linhaVertical == invalido || numero == invalido)
   ||(seguranca[linhaHorizontal][linhaVertical])!= valido){
       verificador = verificador + valorMinimo;
   }    
    if((verificarColuna(tabuleiro, linhaVertical, numero) 
        || verificarLinha(tabuleiro, linhaHorizontal, numero) 
        || localizarBloco(tabuleiro, linhaHorizontal, linhaVertical, numero)) != valido){
        verificador = verificador + valorMinimo;
    }
    if((numero < valorMinimo) || (numero > tam)){
        verificador =  verificador + valorMinimo;
    }
    return verificador;
}

void jogada(int tabuleiro[][tam], int linhaHorizontal, int linhaVertical, int numero, int seguranca[][tam],
            circular** ponteiroInicial, circular** ponteiroFinal){
    
     int verificador;
     
     verificador = verificarJogada(tabuleiro, linhaHorizontal, linhaVertical, numero, seguranca);
     if(verificador == valido){
         jogadaRealizada();
         tabuleiro[linhaHorizontal][linhaVertical] = numero;
         insereInicioCircular(&*ponteiroInicial, &*ponteiroFinal,numero,linhaVertical, linhaHorizontal);
     }else{
         jogadaInvalida();
     }
    getchar();
 }

int verificarFim(int tabuleiro[][tam]){

    int linhaHorizontal = nulo, linhaVertical = nulo, verificador = nulo;
    
    while(linhaHorizontal < tam){
        linhaVertical = nulo;
        while(linhaVertical < tam){
            if(tabuleiro[linhaHorizontal][linhaVertical] == nulo){
                verificador = verificador + valorMinimo;
            }
            linhaVertical = linhaVertical + valorMinimo;
        }
        linhaHorizontal = linhaHorizontal + valorMinimo;
    }
    return verificador;
}

void inserirJogada(int tabuleiro[][tam], int seguranca[][tam],circular** ponteiroInicial, circular** ponteiroFinal){
   
    int linhaVertical,linhaHorizontal,numero;
    
    linhaHorizontal = recebeLinhaHorizontal();
    linhaVertical = recebeLinhaVertical();
    numero = recebeNumero();
    if(tabuleiro[linhaHorizontal][linhaVertical] != nulo){
        vermelho;printf("Impossivel inserir!\n");
    }else{
    jogada(tabuleiro,linhaHorizontal,linhaVertical,numero,seguranca,&*ponteiroInicial, &*ponteiroFinal);
    }
}

int recebeLinhaVertical(){
    
    char linhaVerticalString[tam];
    int linhaVerticalInteiro;
    
    azul;printf("\nDigite uma Coluna = ");
    fgets(linhaVerticalString, sizeof(linhaVerticalString), stdin);
    sscanf(linhaVerticalString, "%d", &linhaVerticalInteiro);
    if((linhaVerticalInteiro > tam) || (linhaVerticalInteiro < valorMinimo)){
        linhaVerticalInteiro = invalido;
    }else{
        linhaVerticalInteiro = linhaVerticalInteiro - valorMinimo;
    }
    
    return linhaVerticalInteiro;
}

int recebeLinhaHorizontal(){

    char linhaHorizontalString[tam];
    int linhaHorizontalInteiro;
    
    azul;printf("\nDigite uma linha = ");

    fgets(linhaHorizontalString, sizeof(linhaHorizontalString), stdin);
    sscanf(linhaHorizontalString, "%d", &linhaHorizontalInteiro);
    if((linhaHorizontalInteiro > tam) || (linhaHorizontalInteiro < valorMinimo)){
        linhaHorizontalInteiro = invalido;
    }else{
        linhaHorizontalInteiro = linhaHorizontalInteiro - valorMinimo;
    }

    return linhaHorizontalInteiro;
}

int recebeNumero(){
    
    char numeroString[tam];
    int numeroInteiro;
    printf("\nDigite o numero que deseja inserir no tabuleiro = " );
    fgets(numeroString, sizeof(numeroString), stdin);
    sscanf(numeroString, "%d", &numeroInteiro);
    if((numeroInteiro > tam) || (numeroInteiro < valorMinimo)){
        numeroInteiro = invalido;
    }

    return numeroInteiro;
}

int verificaNumero(){
    
    char opcaoString[tam];
    int opcaoInteiro;
    
    fgets(opcaoString, sizeof(opcaoString), stdin);
    sscanf(opcaoString, "%d", &opcaoInteiro);
    return opcaoInteiro;
}

void resultadoFinal(int fimJogo){
   
    if(fimJogo == 1){
        printf("\nParabens por completar o Sudoku!\n");
    }else{
        printf("\nVc Desistiu com sucesso '-'!\n");
    }
}

void anulaJogada(int tabuleiro[][tam], int seguranca[][tam],circular** ponteiroInicial, circular** ponteiroFinal){

    if(quantidadeJogadas(tabuleiro, seguranca) == nulo ){
        vermelho;printf("\nOperação invalida - não existem jogadas anteriores!");
    }
    else{
        int linhaHorizontal = recebeLinhaHorizontal();
        int linhaVertical = recebeLinhaVertical();
        
        if((linhaHorizontal == invalido || linhaVertical == invalido)
            ||((seguranca[linhaHorizontal][linhaVertical])!= valido)){
            vermelho; printf("\nOperação invalida - Dados de entrada incorretos!\n");

        }else{
            if(tabuleiro[linhaHorizontal][linhaVertical] == nulo){
                vermelho; printf("\nOperação invalida - Posição já esta nula!");

            }else{
                tabuleiro[linhaHorizontal][linhaVertical] = nulo;
                removeJogadaCircular(&*ponteiroInicial, &*ponteiroFinal,linhaVertical,linhaHorizontal);
                verde; printf("\nRemoção realizada com sucesso!");
            }
        }    
    }
    getchar();
}
void alterarJogada(int tabuleiro[][tam], int seguranca[][tam], circular** ponteiroInicial, circular** ponteiroFinal){
    if(quantidadeJogadas(tabuleiro, seguranca) == nulo ){
        vermelho;printf("\nOperação invalida - não existem jogadas anteriores!");
    }
    else{
        int linhaHorizontal = recebeLinhaHorizontal();
        int linhaVertical = recebeLinhaVertical();
        int valor = recebeNumero();
        
        if((linhaHorizontal == invalido || linhaVertical == invalido) 
            ||((seguranca[linhaHorizontal][linhaVertical])!= valido)){
            vermelho; printf("\nOperação invalida - Dados de entrada incorretos!\n");

        }else{
            if((tabuleiro[linhaHorizontal][linhaVertical] == nulo) || (tabuleiro[linhaHorizontal][linhaVertical] == valor)){
                vermelho; printf("\nOperação invalida - Posição já esta nula!");

            }else{
                removeJogadaCircular(&*ponteiroInicial, &*ponteiroFinal,linhaVertical,linhaHorizontal);
                jogada(tabuleiro,linhaHorizontal,linhaVertical,valor,seguranca,&*ponteiroInicial, &*ponteiroFinal);
               
                if(tabuleiro[linhaHorizontal][linhaVertical] == valor){
                 azul; printf("\nAlteração realizada com sucesso!\n");
                }
            }
        }    
    }
    getchar();

}

int quantidadeJogadas(int tabuleiro[][tam], int seguranca[][tam]){

    int linhaHorizontal = nulo, linhaVertical = nulo, contador = nulo;
    
    while(linhaHorizontal < tam){
        linhaVertical = nulo;
        while(linhaVertical < tam){
            if((tabuleiro[linhaHorizontal][linhaVertical] != valido) 
            && (seguranca[linhaHorizontal][linhaVertical]) == nulo){
                contador = contador + valorMinimo;
            }
            linhaVertical = linhaVertical + valorMinimo;
        }
        linhaHorizontal = linhaHorizontal + valorMinimo;
    }
    return contador;
}

lista* criaNo(int possibilidades){
    
    lista* novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->possibilidade = possibilidades;
    novo->proximo = NULL;
    return novo;
}

lista* ponteiroFinalRecursivo(lista* inicio){
    
    if(inicio == NULL){
        return NULL;
    }
    if(inicio->proximo == NULL){
        return inicio;
    }
    ponteiroFinalRecursivo(inicio->proximo);
}

lista* inserePossibilidades(lista* inicio, int possibilidade){
   
    lista *fim = ponteiroFinalRecursivo(inicio);
    if(inicio == NULL){
        inicio = criaNo(possibilidade);
    }else{
        fim->proximo = criaNo(possibilidade);
    }
    return inicio;
}

void imprimePossibilidadesRecursivo(lista **inicio){
   
    if(*inicio != NULL){
        imprimePossibilidadesRecursivo(&(*inicio)->proximo);   
         printf("-> %d ", (*inicio)->possibilidade);
    }
}

void deletaPossibilidadesRecursivo(lista **inicio){
   
    if(*inicio != NULL){
        deletaPossibilidadesRecursivo(&(*inicio)->proximo);
    }
    free(*inicio);
    *inicio = NULL;
}

lista* verificaPossibilidades(int tabuleiro[][tam], int seguranca[][tam], lista* inicio){
    
    int linhaVertical, linhaHorizontal, contador = tam, verificador = nulo;

    linhaHorizontal = recebeLinhaHorizontal();
    linhaVertical = recebeLinhaVertical();
    if((linhaHorizontal == invalido || linhaVertical == invalido) || seguranca[linhaHorizontal][linhaVertical] != valido){
        vermelho;printf("\nOperação invalida!");
    }else{
        inicio = inserePossibilidadesListaRecursiva(tabuleiro, seguranca, inicio, linhaHorizontal, linhaVertical, contador);
    }
    return inicio;
}

lista* inserePossibilidadesListaRecursiva(int tabuleiro[][tam], int seguranca[][tam], lista* inicio, int linhaHorizontal, int linhaVertical, int valores){
    int verificador = nulo;

    if(valores == nulo){
        return inicio;
    }else{
        verificador = verificarJogada(tabuleiro, linhaHorizontal, linhaVertical, valores,seguranca);
        if(verificador == valido){
            inicio = inserePossibilidades(inicio, valores);
        }
        inserePossibilidadesListaRecursiva(tabuleiro, seguranca, inicio, linhaHorizontal, linhaVertical, valores - valorMinimo);
    } 
}

void possibilidades(lista* inicio){
    if(inicio == NULL){
        vermelho;printf(" Entrada incorreta ou não existem jogadas possiveis para posição solicitada");
    }else{
        verde; printf("Suas possibilidades de jogadas para esta casa do tabuleiro = ");
        imprimePossibilidadesRecursivo(&inicio);
    }
    getchar();
}

circular* criaNoCircular(int valor, int coluna, int linha){
     circular* novo = (circular*)malloc(sizeof(circular));
    novo->valor = valor;
    novo->coluna= coluna;
    novo->linha = linha;
    novo->proximo = novo;
    novo->anterior = novo;

    return novo;
}

int removeJogadaCircular(circular** ponteiroInicial, circular** ponteiroFinal,int coluna, int linha){
    circular* atual = *ponteiroInicial;
    circular* anterior = *ponteiroFinal;

    if(*ponteiroInicial == NULL){
        printf("impossivel deletar!\n");
        return 0;
    }
    if(atual == anterior){
    	
        free(anterior); 
        *ponteiroInicial = NULL;
        *ponteiroFinal = NULL;
        return 1;
    }else{
        do{
            if((atual->coluna == coluna) && (atual->linha == linha)){
                if(atual == *ponteiroInicial){
                    *ponteiroInicial = atual->proximo;
                    (*ponteiroFinal)->proximo = atual->proximo;
                    (*ponteiroInicial)->anterior = *ponteiroFinal;
                    free(atual);
                    return 1;
                }else{
                    anterior->proximo = atual->proximo;
                    if(atual == *ponteiroFinal){
                        *ponteiroFinal = anterior;
                        (*ponteiroFinal)->proximo = *ponteiroInicial;
                        (*ponteiroInicial)->anterior = *ponteiroFinal;

                    }
                    free(atual);
                    return 1;
                }
            }
            else{
                anterior = atual;
                atual = atual->proximo;
            }
        }while(atual != *ponteiroInicial);
    }
}

void insereInicioCircular(circular** ponteiroInicial, circular** ponteiroFinal, int valor, int coluna, int linha){
    circular* novo = criaNoCircular(valor, coluna, linha);

    if(*ponteiroInicial == NULL){
        *ponteiroInicial = novo;
        *ponteiroFinal = novo;
    }else{
        novo->anterior = *ponteiroFinal;
        (*ponteiroFinal)->proximo = novo;
        novo->proximo = *ponteiroInicial;
        (*ponteiroInicial)->anterior = novo;
        *ponteiroInicial = novo;
    }
}

void imprimeCircular(circular** ponteiroFinal){
    int contador = 1;
    circular* inicio;
    inicio = (*ponteiroFinal);
    if(inicio == NULL){
        vermelho;printf("Nenhuma Jogada foi localizada!\n");
    }else{
        printf("\tJOGADAS\n");
        do{
            printf("+=====================+\n");
            printf("|%dº Jogada           |\n", contador);
            printf("|Linha - %d           |\n",inicio->linha + 1);
            printf("|Coluna - %d          |\n",inicio->coluna + 1);
            printf("|Jogada - %d          |\n",(inicio)->valor);

            inicio = inicio->proximo;
            contador = contador + 1;
        }while(inicio != *ponteiroFinal);
        printf("+=====================+\n");
    }
}

void menuInicial(){
        
        branco;
        printf("+---------------------------------+\n");
        printf("|        Marcelo De Araujo  |\n");
        printf("|---------------------------------|\n");
        printf("|             SuDoKu              |\n");
        printf("+---------------------------------+\n");
}

void menu(int tabuleiro[][tam], int seguranca[][tam]){
    
    menuInicial();
    mostrarTabuleiro(tabuleiro, seguranca);
    branco;printf("\n\n\t1 - Realizar Jogada\n");
    printf("\t2 - Alterar jogada anterior\n");
    printf("\t3 - Remover jogada anterior\n");
    printf("\t4 - Verificar Possibilidades\n");
    printf("\t5 - Imprimir Jogadas\n");
    printf("\t6 - Sair");
    verde;printf("\n\t=>  Digite uma opcao = ");
}

void menuJogada(){
   
    branco;;printf("\n\nDeseja mesmo abandonar partida?\n");
    verde;printf("\n\t1 - nao\n");
    vermelho;printf("\t6 - sim\n");
}

void opcaoinvalida(){
   
    printf("\nOpcao Invalida - Digite opcao 1 ou 2!\n\n");
    getchar();
}

void jogadaRealizada(){
    
    verde; printf("\nJogada Realizada!\n\n");
}

void jogadaInvalida(){
    
    vermelho; printf("\nJogada Invalida! - Preste mais atencao!!\n\n");
}
