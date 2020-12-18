#include <stdio.h>
#include <stdbool.h>



int main()
{
float Fx[5]={0,0.5,1,1.5,2},Fy[5];//FUNCAO f(x) COM VALORES PRE DEFINIDOS
float Fx_guarda_subtracao[5];//GUARDA A SUBTRACAO DE X[i-1]-X[i]
float Hx[5],Hy[5]; //FUNCAO h(x) 

for(int i=0;i<4;i++){
Fx_guarda_subtracao[i]=Fx[i+1]-Fx[i];

printf("%.1f\n",Fx_guarda_subtracao[i]);
}  




  



}
