#include <stdio.h>
#include <stdbool.h>
//FUNCAO PARA CRIAR Sx DAS FUNCOES
void cria_s_da_funcao(char nome_funcao,float valor_sx[],float funcao_y[],float x_inicial[],float diferenca_h);
//FUNCAO PARA INTEGRAR AS FUNCOES
void integracao_simpson(char nome_funcao,float h,float funcao_y[]);

int main(){
    int tamanho_indice=5;//n
    float x_inicial[]={0,0,0.5,1,1.5,2};
    float integral_Fx[5]={-(0.5),0.32,0.4,2.07,4.89};//PONTOS DA INTEGRACAO DE FX
    float Fx[5]={0,0.79,2.29,4.47,6.72};//FUNCAO f(x) COM VALORES PRE-DEFINIDOS
    float integral_Hx[5]={0,-(0.44),-(0.41),0.89,4.66};//PONTOS DA INTEGRACAO DE HX
    float Hx[5]={-(1),-(0.62),1,4.62,11};//FUNCAO h(x) COM VALORES PRE-DEFINIDOS
    float sx[4];//VETOR PARA ARMAZENAR OS RESULTADOS DAS INTERPOLACOES DE CADA FUNCAO
    float diferenca_h=0.5; //x[i-1]-x[i]
    float  integral_h=1; //(x5-x0)/2 = 1


 cria_s_da_funcao('F',sx,Fx,x_inicial,diferenca_h);   
 printf("\n");
 cria_s_da_funcao('H',sx,Hx,x_inicial,diferenca_h);
 printf("\n");
 integracao_simpson('F',integral_h,Fx);
 printf("\n");
 integracao_simpson('H',integral_h,Hx);
 printf("\n");
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
//FUNCAO PARA INTEGRAR AS FUNCOES PELO METODO DE SIMPSON
void integracao_simpson(char nome_funcao,float h,float funcao_y[]){
  float resultado_integracao;

  resultado_integracao=(h/3)*(funcao_y[0]+(4*funcao_y[1])+(2*funcao_y[2])+(4*funcao_y[3])+(2*funcao_y[4]));
  printf("Intregracao da funcao %c(x)= %.2f\n",nome_funcao,resultado_integracao);
}
