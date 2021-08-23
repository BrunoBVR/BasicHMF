/* Prepares the initial condition from a spatial homogeneous water-bag
   distribution width p0 in momentum.
   By T.M. Rocha Filho - ICCMP-IF/UnB - marciano@fis.unb.br - November 2010  */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


/* Function prototypes */

float ran2(long *);


void condini(long n, long *idum, double p0, double theta0, double r[], double p[])
{

   long i;
   double ptot;
   FILE *inpt;

   inpt = fopen("phase.dat","r");
 
   ptot=0.0;
   for (i=0;i<n;i++)
       {
        fscanf(inpt,"%lf %lf",&r[i],&p[i]);
        ptot+=p[i];
       };

   printf("Total initial momentum: %lf\n",ptot);

   return;
}
