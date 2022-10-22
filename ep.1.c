//============================ MARCELO DE ARAÚJO ============================//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.00000001

typedef struct {
  int tamanho;
  double **matriz;
} Matriz_SL;

double **alocaMatriz(int linha, int coluna) {
  int i, j;
  double **m;
  m = malloc(sizeof(m) * linha);

  if(m == NULL) {
    return NULL;
  }

  for(int i=0; i < linha; i++) {
    m[i] = malloc(sizeof(double) * coluna);

    if(m[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(m[j]);
      }

      free(m);
      return NULL;
    }
  } 

  return m;
} //ok

double *alocaVetor(int vetor) {
  double *m;
  m = malloc(sizeof(m) * vetor);

  if(m == NULL) {
    return NULL;
  }
  return m;
} //ok

void imprimeMatriz(double **m, int linha, int coluna) {
  int i, j;

  for(int i = 0; i < linha; i++) {
    for (int j = 0; j < coluna; j++) {
      printf("%10.4lf \n", m[i][j]);
    }
    printf("\n");
  }
} //ok

void leMatrizLagrange(double **m, int linha, int coluna) {
  int i = 0;
  int j;

  do {
    printf("Informe A %d : ", coluna - i - 1);
    scanf("%lf", &m[0][0]);

    if(m[0][0] <= 0) {
      printf("Lembrar: Termo A%d obrigatoriamente positivo e nao-nulo.\n", coluna - i - 1);
    }
  } while(m[0][0] <= 0);

  for (int i = 1; i < coluna - 1; i++) {
    printf("Informe A%d: ", coluna - i - 1);
    scanf(" %lf", &m[0][i]);
  }

  do {
    printf("Informe A%d : ", 0);
    scanf(" %lf", &m[0][coluna - 1]);

    if(m[0][coluna - 1] == 0) {
      printf("Lembrar: A tem que ser obrigatoriamente diferente de 0.\n");
    }
  } while(m[0][coluna - 1] == 0);

  m[0][coluna] = 0; 
  m[0][coluna + 1] = 0;

  for(int i = 1; i < linha; i++) {
    for(int j = 0; j < coluna + 2; j++) {
      m[i][j] = 0;
    }
  }
  imprimeMatriz(m, linha, coluna);
} //ok

Matriz_SL *lerArquivo() {
  int  n, i, j;
  double **matrix;
  char nomeArquivo[20];
  FILE *arquivo;

  printf("Digite o nome do arquivo: ");
  scanf(" %s", nomeArquivo);

  arquivo = fopen(nomeArquivo, "r");

  if(arquivo == NULL) {
    printf("O arquivo não existe.\n");
    return NULL;
  }
  fscanf(arquivo, " %d", &n);
    
  matrix = alocaMatriz(n, n+1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) {
      fscanf(arquivo, " %lf", &matrix[i][j]);
    }
  }
  fclose(arquivo);
  Matriz_SL *mSL = (Matriz_SL*) malloc(sizeof(Matriz_SL));
  
  if(mSL == NULL) {
    return NULL;
  }

  mSL -> matriz = matrix;
  mSL -> tamanho = n;

  return mSL;
} //OK

int perguntaGrauEquacao() {
  int grauEq;

  do {
    printf("Informe grau da equação: ");
    scanf(" %d", &grauEq);
    printf("\n");

  } while(grauEq < 0);
  return grauEq;
} //OK

void metodoDeLagrange() {
  int i, j;
  int mTamanho  = perguntaGrauEquacao() + 1;
  double **mlinear = alocaMatriz(4, mTamanho + 2);
  double *limites = alocaVetor(4);

  leMatrizLagrange(mlinear, 1, mTamanho);

  for(int i = 0; i < mTamanho; i++) {
    mlinear[1][mTamanho - 1 - i] = mlinear[0][i];
    mlinear[2][i] = i%2==0 ? mlinear[0][i] : -1*mlinear[0][i];
    mlinear[3][mTamanho - 1 - i] = i%2==0 ? mlinear[0][i] : -1*mlinear[0][i];
  }
  imprimeMatriz(mlinear, 4, mTamanho);

  for(int j = 0; j < 4; j++) {
    for(int i = 0; i < mTamanho; i++) {
      mlinear[j][mTamanho] = ((mlinear[j][i] < 0) && ((mTamanho - i - 1) > mlinear[j][mTamanho])) ? (mTamanho - i - 1) : mlinear[j][mTamanho];
      mlinear[j][mTamanho + 1] = (mlinear[j][i] < mlinear[j][mTamanho + 1]) ? mlinear[j][i] : mlinear[j][mTamanho + 1];
    }
    mlinear[j][mTamanho + 1] = fabs(mlinear[j][mTamanho + 1]);
  }

  for(int i = 0; i < 4; i++) {
    limites[i] = (1.0 + pow(mlinear[i][mTamanho + 1] / mlinear[i][0], 1.0/(mTamanho - 1 - mlinear[i][mTamanho]))) * (i < 2 ? 1 : -1);
  }
  printf("Os limites para a equacao sao:\n");
  printf("Superiores: %.4f  <= x <=  %.4f\n", 1.0/limites[1], limites[0]);
  printf("Inferiores: %.4f <= x <= %.4f\n", limites[2], 1.0/limites[3]);
}

int checarCriterioDasLinhasEColunas(double **m) {
  int nVariaveis = 3;
  int i, j;
  double pivo, somaLinha, somaColuna;

  for(int i = 0; i < nVariaveis; i++) {
    somaLinha = 0.0;
    somaColuna = 0.0;
    pivo = fabs(m[i][i]);

    for(int j = 0; j < nVariaveis; j++) {
      if(i != j) {
        somaLinha = somaLinha + fabs(m[i][j]);
        somaColuna = somaColuna + fabs(m[j][i]);
      }
      if(somaLinha > pivo || somaColuna > pivo) {
        return -1;
      }
    }
  }
  return 1;
} //OK

void metodoDeGaussSeidel() {
  Matriz_SL *mSL = lerArquivo();

  if(mSL == NULL) {
    printf("Houve um erro ao ler a matriz ou o arquivo.\n");
    return;
  }
  double **m = mSL -> matriz;

  if(checarCriterioDasLinhasEColunas(m) == -1) {
    printf("\nMatriz não satisfaz criterio das linhas e colunas\n");
    return;
  }
  
  double divisor, valorLinha;
  int i, j;
  int h = 0;
  int nVariaveis = mSL -> tamanho;
  double valores[nVariaveis];
  double valoresAnteriores[nVariaveis];

  for(int i = 0;i < nVariaveis; i++) {
    valores[i] = 0.0;
    valoresAnteriores[i] = 0.0;
  }
  int difMinimaAlcancada = 0;

  while(h < 1000 && difMinimaAlcancada == 0) {
    for(int i = 0; i < nVariaveis; i++) {
      valorLinha = 0.0;
      divisor = m[i][i];

      for(int j = 0; j < nVariaveis; j++){
        if(i!=j) {
          valorLinha = valorLinha - (valores[j] * m[i][j]);
        }
      }
      valores[i] = (valorLinha + m[i][nVariaveis])/divisor;
    }
    printf("%d\n", h);
    difMinimaAlcancada = 1;

    for(int i = 0; i < nVariaveis; i++) {
      difMinimaAlcancada = (fabs(valoresAnteriores[i]-valores[i]) < 0.00000001) && (difMinimaAlcancada == 1) ? 1 : 0;
      valoresAnteriores[i] = valores[i];
    }
    h++;
  }
  printf("Número de iteracões: %d\n", h);
  printf("Solucão encontrada:\n");

  for(int i = 0; i < nVariaveis; i++) {
    printf("x%d: %f\n", i+1, valores[i]);
  }
   printf("\n");
}

void verificarValor(int valor) {
  switch(valor) {
    case 10: printf("A");
      break;
    case 11: printf("B");
      break;
    case 12: printf("C");
      break;
    case 13: printf("D");
      break;
    case 14: printf("E");
      break;
    case 15: printf("F");
      break;
    default: printf("%d", valor);
      break;
  }
}

void convertBin(int i, double f) {
  int res_int[10]; 
  int index_int = 0;
  int index_frac = 0;

  double f_aux = f;
  double res_fra[20];

  while(i >= 2) {
    res_int[index_int] = i%2;
    i = (i - i%2)/2;
    index_int++;
  }
  res_int[index_int] = i;

  while(f_aux > 0 && index_frac < 20) {
    double k;
    f_aux = modf(f_aux * 2, &k);
    res_fra[index_frac] = k;
    index_frac++;
  }
  printf("Binário: ");

  for(int i = index_int; i >= 0; i--) {
    printf("%d", res_int[i]);
  }
    
  if(f > 0) {
    printf(".");

    for(int i = 0; i < index_frac; i++) {
      printf("%d", (int)res_fra[i]);
    }
  }
  printf("\n");
}

void convertHex(int i, double f){
  int res_int[10];
  int index_int = 0;
  int index_frac = 0;

  double f_aux = f;
  double res_fra[20];

  while(i >= 16) {
    res_int[index_int] = i%16;
    i = (i - i%16)/16;
    index_int++;
  }
  res_int[index_int] = i;

  while(f_aux > 0 && index_frac < 20){
    double k;
    f_aux = modf(f_aux * 16, &k);
    res_fra[index_frac] = k;
    index_frac++;
  }
  printf("Hexadecimal: ");
  for(int i = index_int; i >= 0; i--) {
    verificarValor(res_int[i]);
  }
  if(f > 0) {
    printf(".");
    for(int i = 0; i < index_frac; i++) {
      verificarValor((int)res_fra[i]);
    }
  }
  printf("\n");
}

void convertOct(int i, double f){
  int res_int[10];
  int index_int = 0;
  int index_frac = 0;

  double f_aux = f;
  double res_fra[20];

  while(i >= 8){
    res_int[index_int] = i%8;
    i = (i - i%8)/8;
    index_int++;
  }
  res_int[index_int] = i;

  while(f_aux > 0 && index_frac < 20){
    double k;
    f_aux = modf(f_aux * 8, &k);
    res_fra[index_frac] = k;
    index_frac++;
  }
  printf("Octadecimal: ");

  for(int i = index_int; i >= 0; i--) {
    printf("%d", res_int[i]);
  }
  if(f > 0) {
    printf(".");
    for(int i = 0; i < index_frac; i++) {
      printf("%d",(int)res_fra[i]);
    }
  }
  printf("\n");
}

int main() {
  char letra;

  do {
    printf("C - Conversão \n");
    printf("S - Sistema Linear \n");
    printf("E - Equação Algébrica \n");
    printf("F - Finalizar \n");
    scanf(" %c", &letra);

    switch(letra){
      double value, intpart, fracpart;

      case 'C':
        printf("Digite o número a ser convertido: ");
        scanf(" %lf", &value);
        fracpart = modf(value, &intpart);
        convertBin(intpart, fracpart);
        convertOct(intpart, fracpart);
        convertHex(intpart, fracpart);
        printf("\n");
        break;

      case 'S':
        metodoDeGaussSeidel();
        break;

      case 'E':
        metodoDeLagrange();
        break;

      case 'F':
        printf("Finalizando a aplicação...\n");
        return 0;

      default:
        printf("Comando inválido!\n");
        break;
    }
  } while(1);
}
