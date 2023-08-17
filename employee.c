#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

FILE *carregarArquivo() {
    FILE *File = fopen("funcionario.bin", "rb+");
    if (File == NULL) {
        File = fopen("funcionario.bin", "wb+");
        if (File == NULL) {
            printf("Ocorreu um erro na abertura do programa");
        }
    }
    return File;
}



Employee inserirDados() {
    Employee employee;
    printf("Digite os dados\n");
    printf("Digite o nome: ");
    gets(employee.name);


    printf("Digite o cpf: ");
    gets(employee.cpf);

    printf("Digite a data de aniversario: ");
    gets(employee.date_of_birth);


    printf("Digite o genero: ");
    gets(employee.gender);

    printf("Digite o salario: ");
    scanf("%f", &employee.salary);
    printf("\n");

    return employee;
}

void cadastrar() {
    FILE *file = carregarArquivo();
    Employee employee;
    fseek(file, 0, SEEK_END);
    employee = inserirDados();
    fwrite(&employee, sizeof(Employee), 1, file);
    fclose(file);
}

void listar() {
    FILE *file = carregarArquivo();
    Employee employee;
    fseek(file, 0, SEEK_SET);
    fread(&employee, sizeof(Employee), 1, file);
    while (!feof(file)) {
        printf("Nome: %s\n", employee.name);
        printf("CPF: %s\n", employee.cpf);
        printf("data de aniversario: %s\n", employee.date_of_birth);
        printf("genero: %s\n", employee.gender);
        printf("salario: %.2f\n\n", employee.salary);
        fread(&employee, sizeof(Employee), 1, file);

    }
    fclose(file);
}

void alterar() {
    FILE *file = carregarArquivo();
    fseek(file, 0, SEEK_SET);
    char cpf[12];
    printf("Digite o cpf: ");
    gets(cpf);
    Employee employee;
    fread(&employee, sizeof(Employee), 1, file);
    while (!feof(file)) {
        if (strcmp(cpf, employee.cpf) == 0) {
            fseek(file, sizeof(Employee) * -1, SEEK_CUR);
            employee = inserirDados();
            fwrite(&employee, sizeof(Employee), 1, file);
            break;
        }
        fread(&employee, sizeof(Employee), 1, file);
    }
    fclose(file);
}

void excluir() {
    FILE *file = carregarArquivo();
    FILE *aux = fopen("aux.bin","wb+");
    fseek(file, 0, SEEK_SET);
    fseek(aux, 0, SEEK_SET);
    char cpf[12];
    printf("Digite o cpf: ");
    gets(cpf);
    Employee employee;
    fread(&employee, sizeof(Employee), 1, file);

    while (!feof(file)) {
        if (strcmp(cpf, employee.cpf) == 0) {
            fread(&employee, sizeof(Employee), 1, file);
            continue;
        }

        fwrite(&employee, sizeof(Employee), 1, aux);
        fread(&employee, sizeof(Employee), 1, file);
    }
    fclose(file);
    fclose(aux);
    remove("funcionario.bin");
    rename("aux.bin", "funcionario.bin");

}