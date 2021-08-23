/* computes the force array for the repulsive case */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void force(long n, double *mx, double *my, double r[], double f[])
{
   long i;
   double a1,a2;
   
   double *as=(double*)malloc(n*sizeof(double));
   double *ac=(double*)malloc(n*sizeof(double));


   *mx=0.0;
   *my=0.0;
   for (i=0;i<n;i++)
   {
       a1=sin(r[i]);
       a2=cos(r[i]);
       *mx+=a2;
       *my+=a1;
       as[i]=a1;
       ac[i]=a2;
   };
   *mx=*mx/((double) n);
   *my=*my/((double) n);

   for (i=0;i<n;i++)
   {
       f[i]=-ac[i]*(*my)+as[i]*(*mx);    /*Repulsive force*/
   };

   return;
}
