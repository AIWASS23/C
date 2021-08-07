#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTDNUMBERS 5

void getName(char[], char[]);

int main() {
	int i;
	char *dados = NULL;
	FILE *lf;
	char fileName[50] = {""};
	char user[50];
	char allNumbers[20 * QTDNUMBERS];
	
	int numbers[QTDNUMBERS];
	srand(time(NULL));
	for (i = 0; i < QTDNUMBERS; i++) {
		numbers[i] = rand() % 100;
	}
	
	int myNumbers[QTDNUMBERS];
	for (i = 0; i < QTDNUMBERS; i++) {
		myNumbers[i] = 0;
	}
	
	int passo = 0;
	char inputType[10] = "text";
	int acertos = 0;
	
	dados = getenv("QUERY_STRING");
	
	if (sscanf(dados, "abo=brinha&user=%s", user) == 1) {
		// Iniciando o jogo
		passo = 0;
		
		getName(user, fileName);
		
		lf = fopen(fileName, "wt");
		
		for (i = 0; i < QTDNUMBERS; i++) {
			fprintf(lf, "%d ", numbers[i]);
		}
		
		fclose(lf);
	} else if (sscanf(dados, "user=%[^&]&%s", user, allNumbers) == 2) {
		// Checando se os números inseridos coincidem
		passo = 2;
		
		getName(user, fileName);
		
		lf = fopen(fileName, "rt");
		
		for (i = 0; i < QTDNUMBERS; i++) {
			fscanf(lf, "%d ", &numbers[i]);
		}
		
		
		i = 0;
		char *pch = strtok(allNumbers, "&myNumber=");
		while (pch != NULL) {
			pch = strtok(NULL, "&myNumber=");
			myNumbers[i] = atoi(pch);
			i++;
			pch = strtok(NULL, "&myNumber=");
		}
		
		for (i = 0; i < QTDNUMBERS; i++)
			if (numbers[i] == myNumbers[i])
				acertos++;
		
		fclose(lf);
	} else if (sscanf(dados, "user=%s", user) == 1) {
		// Recuperando os número do arquivo
		passo = 1;
		
		getName(user, fileName);
		
		lf = fopen(fileName, "rt");
		
		for (i = 0; i < QTDNUMBERS; i++) {
			fscanf(lf, "%d ", &numbers[i]);
		}
		
		fclose(lf);
	} else {
		// Não entrou com nenhum parâmetro na URL
		passo = -1;
	}
	
	printf("Content-type:text/html;charset=UTF-8%c%c\n", 13, 10);
	printf("<html>");
		printf("<head>");
			printf("<meta charset=\"utf-8\">");
			printf("<meta name=\"author\" content=\"Alisson Nunes\">");
			printf("<meta name=\"reply-to\" content=\"alynva@gmail.com\">");
			printf("<meta name=\"generator\" content=\"Dev-C++ 5.11\">");
			printf("<meta http-equiv=\"content-language\" content=\"pt-br\">");
			printf("<meta name=\"description\" content=\"Um jogo simples, com a mecânica programada em Lingaugem C.\">");
			if (passo == 0)
				printf("<meta http-equiv=\"refresh\" content=\"5; url=?user=%s\">", user);
			else if (passo == -1)
				printf("<meta http-equiv=\"refresh\" content=\"0; url=../jogo-da-memoria.html\">");
			printf("<title>Jogo da memoria</title>");
			printf("<link rel=\"stylesheet\" href=\"../jogo-da-memoria.css\">");
		printf("</head>");
		printf("<body>");
			if (passo >= 0) {
				printf("<a href=\"../jogo-da-memoria.html\">Voltar</a>");
				printf("<form action=\"\">");
					if (passo != 0 && acertos != QTDNUMBERS) {
						strcpy(inputType, "hidden");
						printf("<input type=\"hidden\" name=\"user\" value=\"%s\">", user);
					}
					for (i = 0; i < QTDNUMBERS; i++) {
						printf("<input class=\"theNumber\" type=\"%s\" name=\"theNumber%d\" value=\"%i\" disabled>", inputType, i, numbers[i]);
					}
					if (passo != 0 && acertos == QTDNUMBERS)
						printf("<br>");
					for (i = 0; i < QTDNUMBERS; i++) {
						if (passo != 0) {
							printf("<input class=\"myNumber");
							if (passo == 2) {
								if (myNumbers[i] == numbers[i])
									printf(" acerto");
								else
									printf(" erro");
							}
							printf("\" type=\"number\"");
							if (acertos == QTDNUMBERS)
								printf(" disabled");
							printf(" name=\"myNumber%d\" value=\"%d\">", i, myNumbers[i]);
						}
					}
					if (passo != 0 && acertos != QTDNUMBERS)
						printf("<br><input type=\"submit\" value=\"Tentar\">");
				printf("</form>");
				if (passo == 2) {
					printf("<span class=\"result\">");
					if (acertos == QTDNUMBERS)
						printf("Uau! Voc&#234; acertou todos!");
					else if (acertos > QTDNUMBERS / 2)
						printf("Uia, foi quase.");
					else if (acertos == 0)
						printf("Que pena, voc&#234; errou todos.");
					else
						printf("Voc&#234; precisa melhorar, passou longe!");
					printf("</span>");
				}
				printf("<a href=\"jogo-da-memoria.cgi?abo=brinha&user=%s\">Recome&#231;ar</a>", user);
			}
		printf("</body>");
	printf("</html>");
	
	return 0;
}

void getName(char user[], char name[]) {
	strcat(name, "jogo-da-memoria-");
	strcat(name, user);
	strcat(name, ".txt");
}
