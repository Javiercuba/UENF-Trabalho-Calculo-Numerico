
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

int VetorTodoPositivo(float x[4]){
    
     for(int y=1;y<=4;y++){
        if(x[y]<0.0){
            x[y]=x[y]*(-1);
            
        }
        printf("RESULTADO :%.2f\n",x[y]);
       }
    
}

int MaiorValor(float x[4]){
    float maior=0;
    for(int y=1;y<=4;y++){
        if(x[y]>maior){
            maior=x[y];
        }
        
       }
       
       printf("MAIOR VALOR :%.2f\n",maior);
     
}

int calculaIntegracaoJacobi(float diagonal[4],float resultados_de_cada_linha[4],float matriz[4][4],float proximos_pontos[4]){
      float  solucao_inicial_zero[4],guarda_somatorio=0,resultado_x0_menos_x1[4],criterio_de_parada;
      
      //INCREMENTANDO VALORES NO VETOR INCIAL x0
         for(int add=1;add<=4;add++){
           solucao_inicial_zero[add]=resultados_de_cada_linha[add]/diagonal[add];
            printf("RESULTADO INICIAL  X0 %.2f\n",solucao_inicial_zero[add]);
         }
         printf("===========================================================================\n");
         for(int i=1;i<=4;i++){
         guarda_somatorio=0;
             for(int j=1;j<=4;j++){
                 if(i!=j){
                  guarda_somatorio+= (matriz[i][j]*solucao_inicial_zero[j]);

                    }
                  }
                  
                  proximos_pontos[i]=(1/diagonal[i]) * (resultados_de_cada_linha[i] - (guarda_somatorio) );
            printf("RESULTADO FINAL X1:%.2f\n",proximos_pontos[i]);
            
         }
         
          printf("=================================RESULTADO DA SUBTRAÇAO DO VETOR X0 COM X1 EM MODULO================================\n");
            for(int c=1;c<=4;c++ ){
                     resultado_x0_menos_x1[c]=solucao_inicial_zero[c] - proximos_pontos[c];
              }
              VetorTodoPositivo(resultado_x0_menos_x1);
            
        
         
          printf("=================================VETOR X1 POSITIVO================================\n");
         VetorTodoPositivo(proximos_pontos);
          printf("=================================MAIOR VALOR DO VETOR X1================================\n");
          MaiorValor(proximos_pontos);
          
           printf("=================================MAIOR VALOR DA SUBTRAÇAO================================\n");
          MaiorValor(resultado_x0_menos_x1);
          
           printf("=================================CRITERIO DE PARADA================================\n\n");
         // criterio_de_parada =  MaiorValor(resultado_x0_menos_x1);
         // printf("VALOR DO CRITERIO DE PARADA INCIAL: %.4f ", MaiorValor(resultado_x0_menos_x1));
         
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
    //FUNÇÃO PARA VERIFICAR SE ATENDE OS CRITERIOS DAS LINHAS E COLUNAS
    convergenciaJacobiDiagonalLinhas(resultado_linha,resultado_coluna,matriz);
    //
    
     calculaIntegracaoJacobi(posicoes_iguais,resultado_equacoes,matriz,solucao_final_um);
   /*ESTA FUNÇAO FAZ:
   ->ISOLA O X DA FUNÇAO
   ->
   */
    
    
    
    
    
    
}
