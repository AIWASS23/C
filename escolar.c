#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 120

typedef struct aluno {
	char nome[40];
	int ano;
	char curso[40];
	float media;
} aluno;



aluno * copia_aluno( aluno * a) 
{
	aluno *t;

	t=(aluno *)malloc(sizeof(aluno));
	if (t==NULL)
		return t;

	*t = *a;
	/* ou:
	strcpy(t->nome,a->nome);
	t->ano = a->ano;
	strcpy(t->curso,a->curso);
	t->media = a->media;
	*/

	return t;
}



void guarda_aluno( aluno * a, char * filename) 
{
	FILE *f;

	if (a==NULL) return;

	f = fopen(filename,"a");
	
	if (f==NULL) return;

	fprintf(f, "%s\t%d\t%s\t%f\n",a->nome,a->ano,a->curso,a->media);

	fclose(f);
}

void mostra_aluno(aluno * a) 
{
	if (a==NULL) return;
	printf("\nnome:%s\nano:%d\ncurso:%s\nmedia:%f\n",a->nome,a->ano,a->curso,a->media);
}

void mostra_ficheiro(char * filename)
{
	FILE *f;
	char buf[MAX_BUF];

	f = fopen(filename,"r");
	
	if (f==NULL) 
	{
		printf("\nErro na abertura do ficheiro \"%s\"!\n", filename);
		return;
	}

	printf("\nFicheiro \"%s\"\n", filename);

	fgets(buf, MAX_BUF, f);
	while (!feof(f))
	{
		printf("%s",buf);
		fgets(buf, MAX_BUF, f);
	}

	fclose(f);
}


int main(int argc, char* argv[])
{
	aluno a1 = {"Paulo Sergio", 1999, "EI", 14.2F};
	aluno a2 = {"Richard Carvalho", 1998, "EEC", 12.8F};
	aluno a3 = {"Marcelo De Araujo", 1989, "SE", 15.1F};

	aluno * at;

	printf("\nAlunos:\n");

	mostra_aluno(&a1);
	mostra_aluno(&a2);
	mostra_aluno(&a3);
	
	printf("\nFicheiro Inicial:\n");
	
	mostra_ficheiro("teste.txt");

	printf("\nCópia 1:\n");
	at = copia_aluno(&a1);
	mostra_aluno(at);
	guarda_aluno(at,"teste.txt");
	
	printf("\nCópia 2:\n");
	at = copia_aluno(&a2);
	mostra_aluno(at);
	guarda_aluno(at,"teste.txt");
	
	printf("\nFicheiro Final:\n");
	
	mostra_ficheiro("teste.txt");

	return 0;
}
