/* Computes kinetic and potential energies per particle */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "dimmax.inc"

void kinetic(double *kin, long n, double p[])
{
   long i,j;

   *kin=0.0;
   for (i=0;i<n;i++)
       {
       *kin=*kin+p[i]*p[i];
       };
       *kin=*kin/2.0;

   return;
}
