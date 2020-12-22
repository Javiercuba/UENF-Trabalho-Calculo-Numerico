#include <stdio.h>
#include <stdbool.h>

void CriaSplineCubica(char nome_funcao,float x_incial[],float funcao_fx[],float diferenca_h);
void integracaoSimpson(char nome_funcao,float h,float funcao_fx[]);

int main(){
    int tamanho_indice=5;
    float diferenca_h=0.5; //x[i-1]-x[i]=0,5 SEMPRE = 0,5
    float x[5]={0,0.5,1,1.5,2};//VARIACAO DO VALOR DE X EM "diferenca_h" de  0 ate 2
    float Fx[5]={0,0.79,2.28,4.47,6.71};//VALORES PRE-DEFINIDO DA FUNCAO Fx(x)  
    float Hx[5]={-(1),-(0.62),1,4.62,11};//VALORES PRE-DEFINIDOS DA FUNCAO Hx(x)
    float integral_h=1;//(x5-x0)/2
    
    //CRIA SPLINE CUBICA DA FUNCAO Fx
    CriaSplineCubica('F',x,Fx,diferenca_h);
    printf("\n"); 

    //MOSTRA A INTEGRACAO DA FUNCAO Fx
    integracaoSimpson('F',integral_h,Fx);
    printf("\n");

    //CRIA SPLINE CUBICA DA FUNCAO Hx
    CriaSplineCubica('H',x,Hx,diferenca_h); 
    printf("\n");

    //MOSTRA A INTEGRACAO DA FUNCAO Hx
    integracaoSimpson('H',integral_h,Hx);
   
   }

//FUNCAO PARA CRIAR A SPLINE CUBICA DE CADA FUNCAO
void CriaSplineCubica(char nome_funcao,float x_incial[],float funcao_fx[],float diferenca_h ){
  int i;
  float alfa[5]={0,0,0,0,0};//RECEBE OS VALORES DE Sx

  //VETORES AUXILIARES PARA ENCONTRAR c,b,d
  float l[5]={1,0,0,1,0};
  float u[5]={0,0,0,0,0};
  float z[5]={0,0,0,0,0};

  //VALORES DAS VARIAVEIS c,b,d
  float c[5]={0,0,0,0,0};
  float b[5]={0,0,0,0,0};
  float d[5]={0,0,0,0,0};

    for(i=1;i<=4;i++){
        alfa[i] = ((3/diferenca_h)*((funcao_fx[i+1] - funcao_fx[i]) - (funcao_fx[i]-funcao_fx[i-1])));
    }
  
    for(i =1; i<=4;i++){
        l[i] = (2 - (diferenca_h * u[i-1]));
        u[i] = diferenca_h/l[i];
        z[i] = ((alfa[i] - (diferenca_h * z[i-1]))/l[i]);
    }
    //GERANDO OS VALORES DE (c,d,b) A PARTIR DAS VARIAVEIS (l,u,z)
    for(i = 4; i>=0; i--){
        c[i] = z[i] - (u[i]*c[i+1]);
        b[i] = (((funcao_fx[i+1]-funcao_fx[i])/diferenca_h) - ((diferenca_h*(c[i+1]+2*c[i]))/3) );
        d[i] = ((c[i+1] - c[i])/ (3*diferenca_h));
    }
    printf("Interpolacao funcao %c(x):\n",nome_funcao);
    for(i = 1; i <=4;i++){
        printf("s[%d] = %.2f + %.2f*(x-%.2f) + %.2f*(x-%.2f)^2 + %.2f(x-%.2f)^3\n",i, funcao_fx[i], b[i], x_incial[i], c[i], x_incial[i],d[i],x_incial[i]);
    }
    printf("\n");
    printf("Integracao de %c(x) em S''\n",nome_funcao);

    for(i=1;i<=4;i++){
      printf("s'[%d] = %.2f + %.2f(x-%.2f)\n ",i,2*c[i],6*d[i],x_incial[i]);
    }
}

//FUNCAO PARA ENCONTRAR A INTEGRACAO 1/3 DE SIMPSON
void integracaoSimpson(char nome_funcao,float h,float funcao_fx[]){
  float resultado_integracao;

  resultado_integracao=(h/3)*(funcao_fx[0]+(4*funcao_fx[1])+(2*funcao_fx[2])+(4*funcao_fx[3])+(2*funcao_fx[4]));
  printf("Integracao da funcao %c(x)= %.2f\n",nome_funcao,resultado_integracao);
}


