/* Prepares the initial condition from a spatial homogeneous
   distribution and a monetum Gaussian distribution with inverse temperature beta.
   By T.M. Rocha Filho - ICCMP-IF/UnB - marciano@fis.unb.br - July 2012  */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>


/* Function prototypes */

float ran2(long *);


void condini(long n, long *idum, double p0, double theta0, double r[], double p[])
{

   long i;
   double lt,ptot,beta,pr,pr2;
   FILE *temp;

   temp=fopen("gauss.in","r");
   fscanf(temp,"%lf",&beta);
   fclose(temp);
   printf("initial temperature %lf\n\n",1/beta);
 
   for (i=0;i<n;i++)
       {
       r[i]=((double) ran2(idum))*theta0;
       };


   lt=0.0;
   i=0;
   while (i<n)
   {
      p[i]=2.0*(ran2(idum)-0.5)*p0;
      pr=exp(-beta*p[i]*p[i]/2.0);
      pr2=ran2(idum);
      if (pr2<pr)
      {
         lt+=p[i];
         i++;
      };
   };

   lt=lt/((double) n);

   ptot=0.0;
   for (i=0;i<n;i++)
   {
       p[i]=p[i]-lt;
       ptot+=p[i];     
   };

   printf("Total initial momentum: %lf\n",ptot);

   return;
}
