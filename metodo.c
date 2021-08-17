#include <stdio.h>
#include <math.h>

double calculafx(double coef[6], double p0){
    double fx;
    int i;
    fx = coef[6];
    for(i= 5;i>=0;i--){
       fx = (p0*fx) + coef[i];}
    return fx;}

double calculadfx(double coef[6], double p0){
    double fx, dfx;
    int i;
    fx = coef[6];
    dfx = coef[6];
    for(i= 5;i>=1;i--){
       fx = (p0*fx) + coef[i];
       dfx = (p0*dfx) + fx;}
    return dfx;}

double calculaddfx(double coef[6], double p0){
    double fx, dfx, ddfx;
    int i;
    fx = coef[6];
    dfx = coef[6];
    ddfx = coef[6];
    for(i= 5;i>=2;i--){
       fx = (p0*fx) + coef[i];
       dfx = (p0*dfx) + fx;
       ddfx = (p0*ddfx) + 2*dfx;}
     return ddfx;}

double modulo(double x){
    if (x>=0.0){
      return (x);}
    else{
       return (-1.0*x);}}

int main(void){
	
     int n, op, grau, i;
     double e, numer, denom, p0, p, fx, dfx, ddfx, tol, coef[6];
     printf("\e[H\e[2J");
     tol = 0.000001;
     printf("Digite 0 p/ polinômio ou 1 p/ exponecial: ");
     scanf("%i", &op);
     if (op>0){
       printf("\nEntre com o ponto inicial: ");
       scanf("%lf", &p0);
       fx = exp(p0) - p0 -1;
       dfx = exp(p0) -1;
       ddfx = exp(p0);
       n =1;
       p = p0 - (fx*dfx)/((dfx*dfx)-(fx*ddfx));
       printf("\nP%i %lf\n", (n-1), p0);
       e = modulo(p-p0);
       while (n<20 && e>=tol) {
          p0 = p;
          fx = exp(p0) - p0 -1;
          dfx = exp(p0) -1;
          ddfx = exp(p0);
          p = p0 - (fx*dfx)/((dfx*dfx)-(fx*ddfx));
           n++;
     e = modulo(p-p0);
     printf("P%i %lf\n", (n-1), p0);}
       printf("\nAproximação p/ raíz é  %e\n", p);
       printf("\nAproximação da f(x) no ponto é  %e\n", fx);
       printf("Com %i iterações\n\n", n);}
     else{
     printf("Entre com o grau do polinômio: ");
     scanf("%i", &grau);
     for(i = 0 ; i <= 6 ; i++){
       coef[i] = 0;
       }
     for(i = 0 ; i <= grau ; i++){
       printf("\nEntre com o coeficiente a%i: ", i);
       scanf("%lf",&coef[i]);
       }
     printf("\nEntre com o ponto inicial: ");
     scanf("%lf", &p0);
     n = 1;
     fx = calculafx (coef,p0);
     dfx = calculadfx (coef,p0);
     ddfx = calculaddfx (coef,p0);
     p = p0 - (fx*dfx)/((dfx*dfx)-(fx*ddfx));
     printf("\nP%i %lf\n", (n-1), p0);
     e = modulo(p-p0);
     while (n<20 && e>=tol) {
        p0 = p;
        fx = calculafx (coef,p0);
        dfx = calculadfx (coef,p0);
        ddfx = calculaddfx (coef,p0);
        p = p0 - (fx*dfx)/((dfx*dfx)-(fx*ddfx));
   n++;
   e = modulo(p-p0);
   printf("P%i %lf\n", (n-1), p0);
}
     printf("\nAproximação p/ raíz é  %e\n", p);
     printf("\nAproximação da f(x) no ponto é  %e\n", fx);
     printf("Com %i iterações\n\n", n);
     }}
