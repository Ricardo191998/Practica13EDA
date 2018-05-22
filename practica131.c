#include<stdio.h>
#include<omp.h>
#define NRA 500
#define NCA 500
#define NRB 500
#define NCB 500

/*void imprimeMatriz(int c[3][3]){
    for(int i =0;i<3;i++){
       printf("\n");
       for(int j = 0 ; j<3;j++)
          printf("%d ", c[i][j]);
    }
     printf("\n");
}*/

void calculoMatriz(int a[NRA][NCA],int b [NRB][NCB],int c[NCA][NRB]){
    int i, j, k;
    #pragma omp parallel for private (j,k)
    for (i=0; i<NRA; i++)
    {
       for(j=0; j<NCB; j++){
           for (k=0; k<NCA; k++)
               c[i][j] += a[i][k] * b[k][j];
       }
    }
}

int main(){
    int a[500][500];
    int b[500][500];
    int c[500][500];
    double empezar,terminar;

    for(int i; i<500;i++){
       for(int j; j <500 ;j++){
          a[i][j] = 1;
          b[i][j]=1;
       }
     }
    empezar=omp_get_wtime( );
    calculoMatriz(a,b,c);
    terminar=omp_get_wtime( );

    printf("TIEMPO=%lf\n",empezar-terminar);
}
