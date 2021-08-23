/* Evolves by a single time step using Yoshida simplectic integrator
   by T.M. Rocha Filho - ICCP-IF/UnB - marciano@fis.unb.br 0 November 2010 */

#include <stdio.h>

#define  B0   0.675603595979828813
#define  B1  -0.175603595979828813
#define  D0   1.35120719195965763
#define  D1  -1.70241438391931525

/* function prototype */
void force(long, double *, double *, double [], double []);


void timestep(long n, double dt, double *magx, double *magy, double r[], double p[], double f[])
{
   long i;
   double mx,my;

   for (i=0;i<n;i++)
   {
   p[i]=p[i]+B0*dt*f[i];
   r[i]=r[i]+D0*dt*p[i];
   };

   force(n,&mx,&my,r,f);
   for (i=0;i<n;i++)
   {
   p[i]=p[i]+B1*dt*f[i];
   r[i]=r[i]+D1*dt*p[i];
   };

   force(n,&mx,&my,r,f);
   for (i=0;i<n;i++)
   {
   p[i]=p[i]+B1*dt*f[i];
   r[i]=r[i]+D0*dt*p[i];
   };

   force(n,&mx,&my,r,f);
   for (i=0;i<n;i++)
   {
   p[i]=p[i]+B0*dt*f[i];
   };

   *magx=mx;
   *magy=my;


   return;
}
