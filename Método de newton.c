﻿#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

main()
{
     char *s = (char *) 1;
     int n = 0, sair = 0;

     printf("Teste da biblioteca readline. Para sair entre com uma linha vazia\n\n");

     read_history("/tmp/historico"); /* le o histórico do arquivo, se o arquivo existir */
     using_history(); /* habilita o uso do histórico */

     do {
         /* o argumento da readline é o prompt a ser exibido
           se o argumento for NULL, nenhum prompt é exibido */
         s = readline("\\>"); 

         if ( *s ) /* para ignorar linhas em branco */
         {
             add_history(s); /* adiciona a linha lida ao histórico */
             n++; /* para ser usada na função append_history abaixo */

             /* aqui você pode fazer o que quizer com a linha lida */
             printf("linha lida: %s\n", s);

             /* e depois liberar a memória alocada pela readline */
             free(s);
         }
         else
             sair = 1;
     } while ( !sair );

     /* se o arquivo existir adiciona n linhas do histórico ao arquivo,
       caso contrário escreve todo o histórico no arquivo */
     if ( append_history(n, "/tmp/historico") != 0 )
     write_history("/tmp/historico");

     exit(0);
}
 
