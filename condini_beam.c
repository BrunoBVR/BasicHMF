/* MODIFIED: Initial conditions from a spatial homogeneous sequence of
   monokinetic one-particle beams.
   04/04/2013 - Bruno Vieira Ribeiro  */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


/* Function prototypes */

float ran2(long *);


void condini(long n, long *idum, double p0, double theta0, double r[], double p[])
{

   long i;
   double ptot;
 
   for (i=0;i<n;i++)
       {
       r[i]=((double) ran2(idum))*theta0;

       };


   ptot=0.0;
 
  for (i=0;i<n;i++)
       {
       p[i]= ((double)i + 0.5)/(cbrt((double)n)) - (pow((double)n , 2./3.))/2.;
//	p0 is the velocity of the slowest beam.
       ptot+=p[i];     
       };

   printf("Total initial momentum: %lf\n",ptot);

   return;
}
