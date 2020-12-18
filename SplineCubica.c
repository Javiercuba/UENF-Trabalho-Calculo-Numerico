#include <stdio.h>
#include <stdbool.h>



int main(){
    // Inserção de dados
    int tamanho_indice=4;//n
    float Fx[5]={0,0.5,1,1.5,2}, Fy[5]={-(1),-(0.62),1,4.62,11};
    float alfa[5];
    int i;
    float diferenca_h=0.5; //x[i-1]-x[i]
    float  integral_h=1; //(x5-x0)/2 = 1
    float valor_integral;
    //Inicio do passo 2
    for(i=1;i<=tamanho_indice-1;i++){
        alfa[i] = ((3/diferenca_h)*(Fy[i+1] - Fy[i]) - (3/diferenca_h) * (Fy[i]-Fy[i-1]));
    }

    //Inicio do passo 3
    float l[5], u[5], z[5];
    l[0] = 1;
    u[0] = 0;
    z[0] = 0;

    //Inicio do passo 4
    for(i = 1; i<=tamanho_indice-1;i++){
        l[i] = ((2*(Fx[i+1]-Fx[i-1])) - (diferenca_h * u[i-1]));
        u[i] = diferenca_h/l[i];
        z[i] = ((alfa[i] - (diferenca_h * z[i-1]))/l[i]);
    }

    //Inicio do passo 5
    l[tamanho_indice] = 1;
    z[tamanho_indice] = 0;
    float c[5], b[5], d[5];
    c[tamanho_indice] = 0;

    //Inicio passo 6
    for(i = tamanho_indice-1; i>=0; i--){
        c[i] = z[i] - (u[i]*c[i+1]);
        b[i] = (((Fy[i+1]-Fy[i])/diferenca_h) - ((diferenca_h*(c[i+1]+2*c[i]))/3) );
        d[i] = ((c[i+1] - c[i])/ (3*diferenca_h));
    }

    for(i = 0; i <=tamanho_indice-1;i++){
        printf("s[%d] = %.1f + %.2f*(x-%.2f) + %.2f*(x-%.2f)^2 + %.2f(x-%.2f)^3\n",i, Fy[i], b[i], Fx[i], c[i], Fx[i],d[i],Fx[i]);
    }

  valor_integral=(integral_h/3)*(Fy[0]+(4*Fy[1])+(2*Fy[2])+(4*Fy[3])+(2*Fy[4]));
  printf("%f",valor_integral);

}
