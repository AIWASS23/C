#include <stdio.h> // v= (delta(s)/delta(t))



float vmu(float s1, float s2 , float t1 , float t2){
    
    float v;
    float m = (t1-t2);
    if(m==0)
    {
       printf("delta t = 0 tente novamente");
       }
    else{ 
    v = (s1 - s2)/(t1 - t2);                     
    return v;
}
}
float tsmu(float v , float t1 , float t2){//calcula espaço e tempo mu
    
    float sum;
    sum = (t1 - t2)*v ;                    
    return sum;
}

main(){
       float k;
       float s1;
       float s2; 
       float t1;
       float t2;
       int x;
       int y = 0;
               printf("#####Calculando a Velocidade#####\n");
               printf("# 1-Desejo calcular MU          #\n");
               printf("# 2-Desejo sair                 #\n");
               printf("#################################\n");
               scanf("%d" , &x);
       if(x==0)
       { 
               return 0;
               }
       if(x>0){
       while(x > 0){
             
               switch(x){
                         case 1:
                                printf("Oque voce deseja calcular?\n");
                                printf(" 1-Velocidade \n 2-Espaco \n 3-Tempo\n 0-Sair\n");
                                scanf("%d" , &y);
                                switch(y){
                                          case 1:
                                               printf("Entre com s\n");
                                               scanf("%f" , &s1);
                                               printf("Entre com s0\n");
                                               scanf("%f" , &s2);
                                               printf("entre com t\n");
                                               scanf("%f" ,& t1);
                                               printf("entre com t0\n");
                                               scanf("%f" , &t2);
                                               k = vmu(s1,s2,t1,t2);
                                               printf("O resultado eh %f\n", k);
                                               break;
                                          case 2:
                                               printf("Entre com v\n");
                                               scanf("%f" , &s1);
                                               printf("entre com t\n");
                                               scanf("%f" ,& t1);
                                               printf("entre com t0\n");
                                               scanf("%f" , &t2);
                                               k = tsmu(s1,t1,t2);
                                               printf("O resultado eh %f\n", k);
                                               break;
                                          case 3:
                                               printf("Entre com v\n");
                                               scanf("%f" , &s1);
                                               printf("entre com s\n");
                                               scanf("%f" ,& t1);
                                               printf("entre com s0\n");
                                               scanf("%f" , &t2);
                                               k = tsmu(s1,t1,t2);
                                               printf("O resultado eh %f\n", k);
                                               break;
                                 break;
                                          }
                      case 2:
                              x = 0;
                              break;
                              
                           }
 
                  }
                  //system("pause");
                  return 0;
                  
}
}
