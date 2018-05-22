#include<stdio.h>
#include<omp.h>
#include <stdlib.h>
#define NG 5
#define N 6

for(i=0; i<NG; i++)
histo[i] = 0;
/*Calculo del histograma de IMAGEN*/
#pragma omp parallel private(histop) num_threads(2)
{
for(i=0; i< NG; i++)
     histop[i]=0;
#pragma omp for private(j)
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
             histop[IMA[i][j]] ++;
    }
#pragma omp critical
{
for( i=0 ; i < NG ; i++)
histo[i]+=histop[i];
}
}

int main(){
  int IMA[N][N];
  for(int n=0 ; n<N;n++){
      for(int j=0 ; j<N; j++)
          IMA[n][j] = rand() % (N-1);
  }
  empezar=omp_get_wtime( );
  calculaHisto(IMA);
  terminar=omp_get_wtime( );

  printf("TIEMPO=%lf\n",terminar-empezar);

}
