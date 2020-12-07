
#include<stdio.h>
#include<stdbool.h>

int convergenciaJacobiDiagonalLinhas(int compara_linha[4],int compara_coluna[4],int matriz_geral[4][4]){
    bool passou_no_teste= true;
     for(int i=1;i<=4;i++){
         for(int j=1;j<=4;j++){
             if(i=j){
                compara_linha[i]<matriz_geral[i][j]?printf(" Linha %d convergente\n",i) :  printf(" Linha %d nao converge\n",i,passou_no_teste=false);
                
                compara_coluna[i]<matriz_geral[i][j]?printf(" Coluna %d convergente\n",i) : printf(" Coluna %d nao converge\n",i,passou_no_teste=false);
             }
            
         }
         
     }
     passou_no_teste? printf("Atende os criterios de Convergencia\n\n\n") : printf("Não atende os criterios de Convergencia\n\n\n");
}

float VetorTodoPositivo(float x){
    
    for(int y=1;y<=4;y++){
        if(x<0.0){
            return x*(-1);
        }else{
            return x;
        }
       }
}

float MaiorValor(float x[4]){
    float maior=0;
    for(int y=1;y<=4;y++){
        if(x[y]>maior){
            maior=x[y];
        }
       }
     return (maior);
}

float PontoCritico(float vetor[4]){
    float max=0,guarda;
    for(int x=1;x<=4;x++){
        guarda = VetorTodoPositivo(vetor[x]);
            if(guarda>max){
                max=guarda;
            }
    }
    return max;
   
}

float TrocaGauss(float vetor_zero[4],float vetor_um[4],int i){
    if(vetor_um[i]!= 0 ){
        vetor_zero[i]=vetor_um[i];
        return vetor_zero[i];
    }
    
    return vetor_zero[i];
    
}

int calculaIntegracaoJacobi(float diagonal[4],float resultados_de_cada_linha[4],float matriz[4][4],float vetor_x_um[4],float vetor_x_zero[4],int numero_interacoes){
    numero_interacoes++;
      float  guarda_somatorio=0,resultado_x0_menos_x1[4]={0,0,0,0};
      float criterio_de_parada=0;
      float precisao=0.00004;
     
      
      //MOSTRANDO VALORES NO VETOR INCIAL x0
         for(int add=1;add<=4;add++){
            printf("RESULTADO INICIAL  X0 %.2f\n",vetor_x_zero[add]);
         }
         
         printf("===========================================================================\n");
         
         for(int i=1;i<=4;i++){
         guarda_somatorio=0;
             for(int j=1;j<=4;j++){
                 if(i!=j){
                  guarda_somatorio+= (matriz[i][j]*vetor_x_zero[j]);

                    }
                  }
                  
                  vetor_x_um[i]=(1/diagonal[i]) * (resultados_de_cada_linha[i] - (guarda_somatorio) );
            printf("RESULTADO FINAL X1:%.2f\n",vetor_x_um[i]);
            
         }
         
          printf("=================================RESULTADO DA SUBTRAÇAO DO VETOR X0 COM X1================================\n");
            for(int c=1;c<=4;c++ ){
                     resultado_x0_menos_x1[c]=vetor_x_zero[c] - vetor_x_um[c];
                     printf("RESULTADO DA SUBTRAÇÃO: %.2f\n",resultado_x0_menos_x1[c]);
              }
           
          
           printf("=================================CRITERIO DE PARADA================================\n\n");
          
         criterio_de_parada=PontoCritico(resultado_x0_menos_x1)/PontoCritico(vetor_x_um);
           printf("VALOR DO CRITERIO DE PARADA ATUAL: %.5f\n", criterio_de_parada); 
           printf("VALOR DA PRECISÃO: %.5f\n", precisao);
           printf("NUMERO DE INTERAÇOES: %d\n ",numero_interacoes);
            printf("=================================CRITERIO DE PARADA================================\n\n");
          
           if(criterio_de_parada>precisao){
                for(int troca=1;troca<=4;troca++){
             vetor_x_zero[troca]=vetor_x_um[troca];
             vetor_x_um[troca]=0;
         }
             calculaIntegracaoJacobi(diagonal,resultados_de_cada_linha,matriz,vetor_x_um,vetor_x_zero,numero_interacoes);
           
             
         }
          
         }
         
int calculaIntegracaoGauss(float diagonal[4],float resultados_de_cada_linha[4],float matriz[4][4],float vetor_x_um[4],float vetor_x_zero[4],int numero_interacoes){
    numero_interacoes++;
      float  guarda_somatorio=0,resultado_x0_menos_x1[4]={0,0,0,0};
      float criterio_de_parada=0;
      float precisao=0.00004;
     
      
      //MOSTRANDO VALORES NO VETOR INCIAL x0
         for(int add=1;add<=4;add++){
            printf("RESULTADO INICIAL  X0 %.2f\n",vetor_x_zero[add]);
         }
         
         printf("===========================================================================\n");
         
         for(int i=1;i<=4;i++){
         guarda_somatorio=0;
             for(int j=1;j<=4;j++){
                 if(i!=j){
                  guarda_somatorio+= (matriz[i][j]*TrocaGauss(vetor_x_zero,vetor_x_um,i));

                    }
                  }
                  
                  vetor_x_um[i]=(1/diagonal[i]) * (resultados_de_cada_linha[i] - (guarda_somatorio) );
            printf("RESULTADO FINAL X1:%.2f\n",vetor_x_um[i]);
            
         }
         
          printf("=================================RESULTADO DA SUBTRAÇAO DO VETOR X0 COM X1================================\n");
            for(int c=1;c<=4;c++ ){
                     resultado_x0_menos_x1[c]=vetor_x_zero[c] - vetor_x_um[c];
                     printf("RESULTADO DA SUBTRAÇÃO: %.2f\n",resultado_x0_menos_x1[c]);
              }
           
          
           printf("=================================CRITERIO DE PARADA================================\n\n");
          
         criterio_de_parada=PontoCritico(resultado_x0_menos_x1)/PontoCritico(vetor_x_um);
           printf("VALOR DO CRITERIO DE PARADA ATUAL: %.5f\n", criterio_de_parada); 
           printf("VALOR DA PRECISÃO: %.5f\n", precisao);
           printf("NUMERO DE INTERAÇOES: %d\n ",numero_interacoes);
            printf("=================================CRITERIO DE PARADA================================\n\n");
          
           if(criterio_de_parada>precisao){
                for(int troca=1;troca<=4;troca++){
             vetor_x_zero[troca]=vetor_x_um[troca];
             vetor_x_um[troca]=0;
         }
             calculaIntegracaoJacobi(diagonal,resultados_de_cada_linha,matriz,vetor_x_um,vetor_x_zero,numero_interacoes);
           
             
         }
          
         }
  
int main()
{
  float matriz[4][4];     //MATRIZ PRINCIPAL
  int somaLinha=0;        //VARIAVEL PARA INCREMENTAR O VALOR DAS LINHAS
  int somaColuna=0       ;// ''      ''       ''     '  '      '' COLUNAS
  int resultado_linha[4]; //GUARDA A SOMA TOTAL DAS LINHAS
  int resultado_coluna[5]={0,0,0,0,0};//GUARDA A SOMA DAS COLUNAS
  float posicoes_iguais[4];   //GUARDA AS POSIÇOES DA DIAGONAL
  float resultado_equacoes[4];//GUARDA O RESULTADO FINAL DE CADA LINHA
  float solucao_final_um[4]; //GUARDA A SEQUENCIA DE PONTOS ATE CONVERGIR
 float vetor_x_zero[4];
  int numero_interacoes=0;
 
    for(int i=1;i<=4;i++){//CRIANDO A MATRIZ 4X4
        somaLinha=0;
        for(int j=1;j<=4;j++){
            
        printf ("Posicao[%d][%d] = ",i, j);
        scanf ("%f", &matriz[ i ][ j ]);
         if(i!=j){
             somaLinha+=matriz[i][j];//SOMANDO OS VALORES DAS LINHAS E GUARDANDO EM UM VETOR
             resultado_coluna[j]=matriz[i][j]+resultado_coluna[j]; //SOMANDO OS VALORES DAS COLUNAS E GUARDADNO EM UM VETOR 
            }else{
                posicoes_iguais[j]=matriz[i][j];
            }
            resultado_linha[i]=somaLinha;
                    
        }
        
        printf("Digite o resultado da equacao %d = " ,i);
        scanf("%f",&resultado_equacoes[i]);
        printf("Linha 1 : | %.0f %.0f %.0f %.0f |= %.0f\n\n",matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],resultado_equacoes[i]);
        printf("Soma total da Linha %d = %d\n\n",i,resultado_linha[i]);

    }
           for(int teste=1;teste<=4;teste++){
       printf("Soma total da Coluna %d = %d\n",teste,resultado_coluna[teste]);
    }
     //INCREMENTANDO VALORES NO VETOR INCIAL x0
         for(int add=1;add<=4;add++){
           vetor_x_zero[add]=resultado_equacoes[add]/posicoes_iguais[add];
           
         }
    
    
    //FUNÇÃO PARA VERIFICAR SE ATENDE OS CRITERIOS DAS LINHAS E COLUNAS
    convergenciaJacobiDiagonalLinhas(resultado_linha,resultado_coluna,matriz);
    
    
    // calculaIntegracaoJacobi(posicoes_iguais,resultado_equacoes,matriz,solucao_final_um,vetor_x_zero,numero_interacoes);
     calculaIntegracaoGauss(posicoes_iguais,resultado_equacoes,matriz,solucao_final_um,vetor_x_zero,numero_interacoes);
    
}
