//Grupo
//Javier Ernesto Lopez
//Daniel de Faria Ferreira
//José Marcos N S Filho

#include <stdio.h>
#include <stdbool.h>

int convergenciaJacobiDiagonalLinhas(int compara_linha[4], int compara_coluna[4], float matriz_geral[4][4]);

float VetorTodoPositivo(float x);

void CriaVetorInicial(float x_zero[4], float resultado[4], float posicoes[4]);

float MaiorValor(float x[4]);

float PontoCritico(float vetor[4]);

float TrocaGauss(float vetor_zero[4], float vetor_um[4], float troca_valores[4], int i);

void ZerarETroca(float vetor_um[4], float vetor_troca[4]);

int ResultadoSubtracao(float resultado_subtracao[4], float x0[4], float x1[4],int interacoes);

int calculaIntegracaoJacobi(float diagonal[4], float resultados_de_cada_linha[4], float matriz[4][4], float vetor_x_um[4], float vetor_x_zero[4], int numero_interacoes);

int calculaIntegracaoGauss(float diagonal[4], float resultados_de_cada_linha[4], float matriz[4][4], float vetor_x_um[4], float vetor_x_zero[4], int numero_interacoes);
void espaco();

int main()
{
    float matriz[4][4];                          //MATRIZ PRINCIPAL
    int somaLinha = 0;                           //VARIAVEL PARA INCREMENTAR O VALOR DAS LINHAS
    int somaColuna = 0;                          // ''      ''       ''     '  '      '' COLUNAS
    int resultado_linha[4];                      //GUARDA A SOMA TOTAL DAS LINHAS
    int resultado_coluna[5] = {0, 0, 0, 0, 0};   //GUARDA A SOMA DAS COLUNAS
    float posicoes_iguais[4];                    //GUARDA AS POSIÇOES DA DIAGONAL
    float resultado_equacoes[4];                 //GUARDA O RESULTADO FINAL DE CADA LINHA
    float solucao_final_um[5] = {0, 0, 0, 0, 0}; //GUARDA A SEQUENCIA DE PONTOS ATE CONVERGIR
    float vetor_x_zero[4];
    int numero_interacoes = 0;
    int escolha_metodo, metodo1, metodo2;

    for (int i = 1; i <= 4; i++)
    { //CRIANDO A MATRIZ 4X4
        somaLinha = 0;
        for (int j = 1; j <= 4; j++)
        {

            printf("Posicao[%d][%d] = ", i, j);
            scanf("%f", &matriz[i][j]);
            if (i != j)
            {
                somaLinha += matriz[i][j];                                //SOMANDO OS VALORES DAS LINHAS E GUARDANDO EM UM VETOR
                resultado_coluna[j] = matriz[i][j] + resultado_coluna[j]; //SOMANDO OS VALORES DAS COLUNAS E GUARDADNO EM UM VETOR
            }
            else
            {
                posicoes_iguais[j] = matriz[i][j];
            }
            resultado_linha[i] = somaLinha;
        }

        printf("Digite o resultado da equacao %d = ", i);
        scanf("%f", &resultado_equacoes[i]);

       
    }
    for (int teste = 1; teste <= 4; teste++)
    {
        printf("Soma total da Coluna %d = %d\n", teste, resultado_coluna[teste]);
    }
    espaco();
    for (int teste = 1; teste <= 4; teste++)
    {
        printf("Soma total da Linha %d = %d\n", teste, resultado_coluna[teste]);
    }

espaco();
    // FUNÇÃO PARA VERIFICAR SE ATENDE OS CRITERIOS DAS LINHAS E COLUNAS
    convergenciaJacobiDiagonalLinhas(resultado_linha, resultado_coluna, matriz);
    printf("===========================================================================\n");

    CriaVetorInicial(vetor_x_zero, resultado_equacoes, posicoes_iguais);

    printf("===========================================================================\n");

    calculaIntegracaoGauss(posicoes_iguais, resultado_equacoes, matriz, solucao_final_um, vetor_x_zero, numero_interacoes);
    CriaVetorInicial(vetor_x_zero, resultado_equacoes, posicoes_iguais);
    calculaIntegracaoJacobi(posicoes_iguais, resultado_equacoes, matriz, solucao_final_um, vetor_x_zero, numero_interacoes);
    espaco();
<<<<<<< HEAD
  printf("Resposta questao (C):Existe Diferenca entre os dois metodos\npois o Gauss usa os valores atuais e os anteriores e o\n Jacobi usa só os anteriores da interação atual ");
  espaco();
=======
    printf("Resposta questao (C):Existe Diferenca entre os dois metodos \n pois o Gauss usa os valores atuais e os anteriores e o \n Jacobi usa só os anteriores da interação atual ")
>>>>>>> 1fadd6ac3d4540e9de22ffa09c89af41fb7822cd
}

int convergenciaJacobiDiagonalLinhas(int compara_linha[4], int compara_coluna[4], float matriz_geral[4][4])

{
    bool passou_no_teste = true;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (i = j)
            {
                if (compara_linha[i] < matriz_geral[i][j])
                {
                    printf(" Linha %d convergente\n", i);
                }
                else
                {
                    passou_no_teste = false;
                    printf(" Linha %d nao converge\n", i);
                }
                if (compara_coluna[i] < matriz_geral[i][j])
                {
                    printf(" Coluna %d convergente\n", i);
                }
                else
                {
                    printf(" Coluna %d nao converge\n", i);
                    passou_no_teste = false;
                }
            }
        }
    }
    espaco();
    passou_no_teste ? printf("Atende os criterios de Convergencia\n\n\n") : printf("Não atende os criterios de Convergencia\n\n\n");
}
void CriaVetorInicial(float x_zero[4], float resultado[4], float posicoes_iguais[4])
{
    //INCREMENTANDO VALORES NO VETOR INCIAL x0
    for (int add = 1; add <= 4; add++)
    {
        x_zero[add] = resultado[add] / posicoes_iguais[add];
        printf("RESULTADO INICIAL  X0 %.2f\n", x_zero[add]);
    }
    espaco();
}

void espaco()
{
  printf("\n\n");
}

float VetorTodoPositivo(float x)
{
    for (int y = 1; y <= 4; y++)
    {
        if (x < 0.0)
        {
            return x * (-1);
        }
        else
        {
            return x;
        }
    }
}

float MaiorValor(float x[4])
{
    float maior = 0;
    for (int y = 1; y <= 4; y++)
    {
        if (x[y] > maior)
        {
            maior = x[y];
        }
    }
    return maior;
}

float PontoCritico(float vetor[4])
{
    float max = 0, guarda;
    for (int x = 1; x <= 4; x++)
    {
        guarda = VetorTodoPositivo(vetor[x]);
        if (guarda > max)
        {
            max = guarda;
        }
    }
    return max;
}

float TrocaGauss(float vetor_zero[4], float vetor_um[4], float troca_valores[4], int i)
{

    if (vetor_um[i] == 0)
    {
        return troca_valores[i];
    }
    else
    {
        troca_valores[i] = vetor_um[i];
        return troca_valores[i];
    }
}

void ZerarETroca(float vetor_um[4], float vetor_troca[4])
{
    for (int x = 1; x <= 4; x++)
    {
        vetor_um[x] = vetor_troca[x];
        vetor_troca[x] = 0;
    }
}

int ResultadoSubtracao(float resultado_subtracao[4], float x0[4], float x1[4],int interacoes)
{
    for (int c = 1; c <= 4; c++)
    {
        resultado_subtracao[c] = x0[c] - x1[c];
        printf("RESULTADO DA SUBTRAÇÃO X%d-X%d : %.5f\n",interacoes-1,interacoes, resultado_subtracao[c]);
    }
}

int calculaIntegracaoJacobi(float diagonal[4], float resultados_de_cada_linha[4], float matriz[4][4], float vetor_x_um[4], float vetor_x_zero[4], int numero_interacoes)
{
    numero_interacoes++;
    float guarda_somatorio = 0, resultado_x0_menos_x1[4] = {0, 0, 0, 0};
    float criterio_de_parada = 0;
    float precisao = 0.00004;

    for (int i = 1; i <= 4; i++)
    {

        guarda_somatorio = 0;
        for (int j = 1; j <= 4; j++)
        {
            if (i != j)
            {
                guarda_somatorio += (matriz[i][j] * vetor_x_zero[j]);
            }
        }

        vetor_x_um[i] = (1 / diagonal[i]) * (resultados_de_cada_linha[i] - (guarda_somatorio));
//        printf("RESULTADO FINAL X1:%.2f\n", vetor_x_um[i]);
    }
    ResultadoSubtracao(resultado_x0_menos_x1, vetor_x_zero, vetor_x_um,numero_interacoes);
    printf("\n\n");
    printf("=========RESULTADO CRITERIO DE PARADA JACOBI=============\n\n");

    criterio_de_parada = PontoCritico(resultado_x0_menos_x1) / PontoCritico(vetor_x_um);
    printf("MAIOR VALOR DAS SUBTRACOES EM MODULO: %.5f\n", PontoCritico(resultado_x0_menos_x1));
    printf("VALOR  MAXIMO DE  X1 EM MODULO: %.2f\n", PontoCritico(vetor_x_um));

    printf("#   VALOR DO CRITERIO DE PARADA ATUAL: %.5f\n", criterio_de_parada);
    printf("#    VALOR DA PRECISÃO: %.5f                \n", precisao);
    printf("#    NUMERO DE INTERAÇOES JACOBI: %d        \n ", numero_interacoes);
espaco();
    if (criterio_de_parada > precisao)
    {
        ZerarETroca(vetor_x_zero, vetor_x_um);
        calculaIntegracaoJacobi(diagonal, resultados_de_cada_linha, matriz, vetor_x_um, vetor_x_zero, numero_interacoes);
    }
}

int calculaIntegracaoGauss(float diagonal[4], float resultados_de_cada_linha[4], float matriz[4][4], float vetor_x_um[4], float vetor_x_zero[4], int numero_interacoes)
{
    numero_interacoes++;
    float guarda_somatorio = 0, resultado_x0_menos_x1[4] = {0, 0, 0, 0};
    float criterio_de_parada = 0;
    float precisao = 0.00004;
    float troca_valores[4];

    //MOSTRANDO VALORES NO VETOR INCIAL x0
    for (int add = 1; add <= 4; add++)
    {
        troca_valores[add] = vetor_x_zero[add];
        //printf("RESULTADO INICIAL  X%d %.2f\n",numero_interacoes-1,vetor_x_zero[add]);
    }

    printf("===========================================================================\n");

    for (int i = 1; i <= 4; i++)
    {
        guarda_somatorio = 0;
        for (int j = 1; j <= 4; j++)
        {
            if (i != j)
            {
                guarda_somatorio += (matriz[i][j] * TrocaGauss(vetor_x_zero, vetor_x_um, troca_valores, j));
            }
        }
        vetor_x_um[i] = (1 / diagonal[i]) * (resultados_de_cada_linha[i] - (guarda_somatorio));
        printf("RESULTADO FINAL X%d :%.2f\n", numero_interacoes, vetor_x_um[i]);
    }

    printf("================================================================\n");
     ResultadoSubtracao(resultado_x0_menos_x1,vetor_x_zero,vetor_x_um,numero_interacoes);  

    printf("=======RESULTADOS DO CRITERIO DE PARADA GAUSS===============\n\n");
espaco();
    criterio_de_parada = PontoCritico(resultado_x0_menos_x1) / PontoCritico(vetor_x_um);

    printf("MAIOR VALOR DAS SUBTRACOES EM MODULO: %.2f\n", PontoCritico(resultado_x0_menos_x1));
    printf("VALOR  MAXIMO DE  X1 EM MODULO: %.2f\n", PontoCritico(vetor_x_um));

    printf("VALOR DO CRITERIO DE PARADA ATUAL GAUSS: %.5f\n", criterio_de_parada);
    printf("VALOR DA PRECISÃO: %.5f\n", precisao);
    printf("NUMERO DE INTERAÇOES GAUSS: %d\n ", numero_interacoes);
    printf("=======RESULTADOS DO CRITERIO DE PARADA GAUSS===============\n\n");
espaco();
    if (criterio_de_parada > precisao)
    {
        ZerarETroca(vetor_x_zero, vetor_x_um); //FUNCAO PARA ZERAR OS VALORES e trocar

        calculaIntegracaoGauss(diagonal, resultados_de_cada_linha, matriz, vetor_x_um, vetor_x_zero, numero_interacoes);
    }
}
