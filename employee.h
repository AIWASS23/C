
#ifndef BANCO_DE_DADOS_EMPLOYEE_H
#define BANCO_DE_DADOS_EMPLOYEE_H
typedef struct employee {
    char name[100];
    char date_of_birth[20];
    float salary;
    char cpf[12];
    char gender[12];
} Employee;
void cadastrar();
void listar();
void alterar();
void excluir();

#endif //BANCO_DE_DADOS_EMPLOYEE_H
