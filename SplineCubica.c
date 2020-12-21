#include <stdio.h>
#include <stdbool.h>

void cria_s_da_funcao(char nome_funcao,float valor_sx[],float funcao_y[],float x_inicial[],float diferenca_h);

int main(){
    int tamanho_indice=5;//n
    float x_inicial[]={0,0,0.5,1,1.5,2};
    float Hx[5]={0,0.79,2.29,4.47,6.72};//FUNCAO h(x) COM VALORES PRE-DEFINIDOS
    float Fx[5]={-(1),-(0.62),1,4.62,11};//FUNCAO f(x) COM VALORES PRE-DEFINIDOS
    float sx[4];//VETOR PARA ARMAZENAR OS RESULTADOS DAS INTERPOLACOES DE CADA FUNCAO
    float diferenca_h=0.5; //x[i-1]-x[i]
    float  integral_h=1; //(x5-x0)/2 = 1


 cria_s_da_funcao('F',sx,Fx,x_inicial,diferenca_h);   
 printf("\n");
 cria_s_da_funcao('H',sx,Hx,x_inicial,diferenca_h);


}

//FUNCAO PARA CRIAR Sx DAS FUNCOES
void cria_s_da_funcao(char nome_funcao,float valor_sx[],float funcao_y[],float x_inicial[],float diferenca_h){
  float valor_x_sx[4]={0,0,0,0};
  for(int j=1;j<=4;j++){
   //CALCULA O VALOR DE S1 ATE S4 
   valor_sx[j]=(funcao_y[j-1]*(x_inicial[j+1]/diferenca_h))-(funcao_y[j]*(x_inicial[j]/diferenca_h));

   //CALCULA O VALOR QUE MULTIPLICA X (TEM SER FEITO OS DOIS SEPARADOS) 
   valor_x_sx[j]=((-funcao_y[j-1]+funcao_y[j])/diferenca_h);

  }
    printf("Interpolacao da funcao %c(x):\n",nome_funcao) ; 
    for(int i=1;i<=4;i++){
      //MOSTRA NA TELA A POSICAO DA FUNCAO EM CADA PONTO 
    printf("[%.1f,%.1f] s%d(x) = %.2f +  %.2fx\n ",x_inicial[i],x_inicial[i+1],i,valor_sx[i],valor_x_sx[i]);
    
    valor_sx[i]=0;
  } 

}
