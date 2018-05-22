#include<stdio.h>
#include<omp.h>

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
