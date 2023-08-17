#include <stdio.h>
#include "employee.h"

void menu() {
    char option[1];
    do {
        printf("Menu\n");
        printf("Digite 1 - Cadastrar funcionario\n");
        printf("Digite 2 - Listar funcionario\n");
        printf("Digite 3 - Alterar dados do funcionario\n");
        printf("Digite 4 - Deletar funcionario\n");
        printf("Digite 5 - Terminar programa\n");
        scanf("%",&option);
        fflush(stdin);
        gets(option);
        scanf("%",&option);

        if (option[0] == '1') {
            cadastrar();
        } else if (option[0] == '2') {
            listar();
        } else if (option[0] == '3') {
            alterar();
        } else if (option[0] == '4') {
            excluir();
        } else if (option[0] == '5') {
            printf("saiu");
        } else {
            printf("default");
        }
    }while (option[0] != '5');


}

int main() {
    menu();
    return 0;
}
