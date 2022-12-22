#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// arion ruiz ribas
main()
{
    char memoria[100]; //Vetor que ira representar um espaço de memoria com 100 posicoes
    char letra=' '; //Letra que sera inserida pelos algoritmos para simular o funcionamento
    int algoritmo=0, tamanho=0;
    int j=0, i=0, k=0;
    int vazio, soma, verificador;
    int maiorv=0;
    
    srand(time(0)); // Inicializa o algoritmo de sorteio de numeros aleatorios da linguagem C
    //O codigo abaixo distribui aleatoriamente a letra 'x' pelo vetor que representa a memoria
    // simulando o estado real de um trecho de memoria de um computador ja em funcionamento 
    // Imprima o estado inicial da memoria em trechos de 20 posicoes separadas pelo caracter PIPE 
    printf("\n*===========================================================================*\n");
    printf("|                            Memoria inicial                                |");
    printf("\n*===========================================================================*\n"); 
    for(i=0;i<100;i++){
        if(i==0){
                printf("|                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |\n"); 
                printf("|                 ");
        }
        if(i==20 || i==40 || i==60 || i==80){  
            printf("|                 |\n");
            printf("|                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |\n");
            printf("|                 ");
        }
        if(rand()%10 >= 5){
            memoria[i] = 'X';
            printf("|%c",memoria[i]);
        }else{
            memoria[i] = ' ';
            printf("|%c",memoria[i]);
        }
    } 
    printf("|                 |");
    printf("   |                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |");
    printf("\n*===========================================================================*\n");  
    
    do{
        //Menu do programa
        printf("\n*===========================================================================*\n");
        printf("|   1 - Primeira Escolha                                                    |\n");
        printf("|   2 - Melhor Escolha                                                      |\n");
        printf("|   3 - Pior Escolha                                                        |\n");
        printf("|   4 - Sair                                                                |");
        printf("\n*===========================================================================*\n");
        do{
            fflush(stdin);                                                                                        
            printf("\nEscolha o algoritmo pelo numero> ");
            scanf("%d",&algoritmo);
            if(algoritmo >= 5 || algoritmo <=0){
                printf("\n*====================*\n");
                printf("|   valor invalido   |");
                printf("\n*====================*\n");
            }
        }while(algoritmo <= 0 || algoritmo >=5);
        
        if(algoritmo == 4)
            exit(0);      
        
        do{
            fflush(stdin);
            printf("\nDigite o Tamanho da Informacao> ");
            scanf("%d",&tamanho);
            if(tamanho <= 0){
                 printf("\n*====================*\n");
                 printf("|   valor invalido   |");
                 printf("\n*====================*\n");
            }
        }while(tamanho <= 0);
        
        fflush(stdin);
        printf("\nDigite a letra a ser utilizada> ");
        scanf("%c",&letra);
        printf("\n*===========================================================================*\n");
        
        verificador = 0;
        vazio = 0;
        soma = 0;
        
        if(algoritmo == 1){
            //logica 1
            for(i=0;i<100;i++){
                if(memoria[i] == ' '){
                    vazio++;
                    if(vazio == tamanho){            
                        for(j=i; j>(i-tamanho); j--)
                            memoria[j] = letra;
                        break;
                    }
                }else
                    vazio = 0;
                verificador++;
            }
        }else{
            if(algoritmo == 2){
                //logica 2
                for(i=0;i<100;i++){
                    if(memoria[i] == ' '){
                        vazio++;
                        if(vazio == tamanho && vazio <= tamanho){
                            for(j=i; j>=((i-vazio)+1); j--)
                                memoria[j] = letra; 
                            break;
                        }
                    }else
                        vazio = 0;
                    verificador++;
                }
            }else{
                //logica 3
                maiorv = 0;
                for(i=0;i<100;i++){
                    if(memoria[i] == ' '){
                        vazio++;
                    }else{
                        if(vazio > maiorv)
                            maiorv = vazio;
                        vazio = 0;
                    }
                }
                vazio = 0;
                
                for(k=1; k<=maiorv; k++){
                    for(i=0;i<100;i++){
                        if(memoria[i] == ' '){
                            vazio++;
                            if(i==99){
                                for(j=((i-vazio)+1); j<i; j++){
                                    soma++;
                                    if(tamanho >= soma)
                                        memoria[j] = letra;   
                                }
                            }
                        }
                        if(memoria[i] != ' '){
                            if(vazio == (tamanho + k)){
                                for(j=(i-vazio); j<i; j++){
                                    soma++;
                                    if(tamanho >= soma)
                                        memoria[j] = letra;   
                                } 
                                break;
                            }else
                                vazio = 0;
                        }
                        verificador++;
                    }
                }
            }
        }
        //Imprima em tela o estado atual da memoria
        printf("\n*===========================================================================*\n");
        printf("|                           Memoria atual                                   |");
        printf("\n*===========================================================================*\n");
        for(i=0;i<100;i++){
            if(i==0){
                printf("|                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |\n"); 
                printf("|                 ");
            }
            if(i==20 || i==40 || i==60 || i==80){ 
                printf("|                 |\n");
                printf("|                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |\n");
                printf("|                 ");
            }
            printf("|%c",memoria[i]);
        }
        printf("|                 |");
        printf("   |                 +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+                 |");
        printf("\n*===========================================================================*\n");
        
        if(verificador == 100){
  		    printf("\n*===========================================================================*\n");
            printf("|           nao tem espaco na memoria para o valor desejado                 |");
      		printf("\n*===========================================================================*\n");
        }
            
    }while(algoritmo != 4);
    getch();
}
