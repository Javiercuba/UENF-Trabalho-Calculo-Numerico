
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
     passou_no_teste? printf("Atende os criterios de Convergencia\n") : printf("Não atende os criterios de Convergencia\n");
}

int calculaIntegracaoJacobi(float diagonal[4],float resultados_de_cada_linha[4]){
      float  solucao_inicial[4];
      
         for(int j=1;j<=4;j++){
           solucao_inicial[j]=resultados_de_cada_linha[j]/diagonal[j];//PROBLEMA COM NUMERO NEGATIVO
          
            printf("%.2f\n",solucao_inicial[j]);
            
         }
         
     
      
      
      //    solucao_incial= igualdade/x1;
    //     xzero=igualdade/x1;
      
    //  x=(1/x1)*(igualdade - )
}


int main()
{
  int matriz[4][4];       //MATRIZ PRINCIPAL
  int somaLinha=0;        //VARIAVEL PARA INCREMENTAR O VALOR DAS LINHAS
  int somaColuna=0       ;// ''      ''       ''     '  '      '' COLUNAS
  int resultado_linha[4];//GUARDA A SOMA DAS LINHAS
  int resultado_coluna[5]={0,0,0,0,0};//GUARDA A SOMA DAS COLUNAS
  int posicoes_iguais[4];   //GUARDA AS POSIÇOES DA DIAGONAL
  int resultado_equacoes[4];//GUARDA O RESULTADO FINAL DE CADA LINHA
   
 
    for(int i=1;i<=4;i++){//CRIANDO A MATRIZ 4X4
        somaLinha=0;
        for(int j=1;j<=4;j++){
            
        printf ("Posicao[%d][%d] = ",i, j);
        scanf ("%d", &matriz[ i ][ j ]);
         if(i!=j){
             somaLinha=somaLinha+matriz[i][j];//SOMANDO OS VALORES DAS LINHAS E GUARDANDO EM UM VETOR
             resultado_coluna[j]=matriz[i][j]+resultado_coluna[j]; //SOMANDO OS VALORES DAS COLUNAS E GUARDADNO EM UM VETOR 
            }else{
                posicoes_iguais[j]=matriz[i][j];
            }
            resultado_linha[i]=somaLinha;
                    
        }
        
        printf("Digite o resultado da equacao %d = " ,i);
        scanf("%d",&resultado_equacoes[i]);
        printf("Linha 1 : |%d %d %d %d|= %d\n\n",matriz[i][1],matriz[i][2],matriz[i][3],matriz[i][4],resultado_equacoes[i]);
        printf("Soma total da Linha %d = %d\n\n",i,resultado_linha[i]);

    }
           for(int teste=1;teste<=4;teste++){
       printf("Soma total da Coluna %d = %d\n",teste,resultado_coluna[teste]);
       
    
        
    }
    //FUNÇÃO PARA VERIFICAR SE ATENDE OS CRITERIOS DAS LINHAS E COLUNAS
    convergenciaJacobiDiagonalLinhas(resultado_linha,resultado_coluna,matriz);
    //
    
   
     calculaIntegracaoJacobi(posicoes_iguais,resultado_equacoes);
    
    
    
    
    
    
}
