#include <stdio.h>
#include <stdbool.h>



int main(){
    // Inserção de dados
    int tamanho_indice=5;//n
    float valor_x[5]={0,0.5,1,1.5,2}, Fx[5]={0,0.79,2.29,4.47,6.72};
    float alfa[5];
    int i;
    float sx[4];
    float diferenca_h=0.5; //x[i-1]-x[i]
    float valor_x_sx[4];
    float  integral_h=1; //(x5-x0)/2 = 1


    for(int x=1;x<=4;x++){
    //CALCULANDO VALOR DE s1 ate s4 
      sx[x]=(Fx[x-1]*(valor_x[x]/diferenca_h))-(Fx[x]*(valor_x[x-1]/diferenca_h));

    //CALCULANDO VALOR QUE MULTIPLICA POR X EM sx       
      valor_x_sx[x]= ((-Fx[x-1]+Fx[x])/diferenca_h);
   }
    printf("Interpolacao da funcao F(x):\n") ; 
    for(int i=1;i<=4;i++){
    printf("[%.1f,%.1f] s%d(x) = %.2f +  %.2fx\n ",valor_x[i-1],valor_x[i],i,sx[i],valor_x_sx[i]);
    }
}
