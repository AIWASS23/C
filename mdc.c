#include <stdio.h>
#include <conio.h>

int Md(){
    int mdc,x=2,j=0,m=0,n,i,n1[100],n2[100],a,b;
    printf("a:");scanf("%d",&a); printf("b:");scanf("%d",&b);
    if(a>b) {i=a;a=b;b=i;}
    for(n=b;x;n=a){
        for(i=1;i<=n;i++){
            if(!(n%i)) {
                if(n==a) {n1[j]=i; j++;}
                else {n2[m]=i; m++;}
            }
        }
        x--;
    }
    for(j--;j!=(-1);j--){ //a<b
        for(i=0;i<m;i++){
            if (n1[j]==n2[i]) return (n2[i]);
        }
    }
    return a;
}

int main(){
    printf("O mdc eh %d",Md());
    getch();
    return (0);
}
