/* Modified -- Bruno Vieira Ribeiro, IF/UnB - 2013  */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "ran2.c"
#include "kinetic.c"
#include "timestep.c"

/* Function prototypes */

void condini(long, long *, double, double, double [], double[]);
void force(long, double *, double *, double [], double []);



int main()
{
   long n,seed,seq,i,j,idum;
   double dt,tf,ts,energ,energ0,p0,theta0,pr,kin,potential,time,tcount,err,
          magx,magy;
   FILE *arq1,*enrg,*ferr,*fmag, *phasep;
   char ener[60], magne[60], inic[60], finc[60];
   
   mkdir("./evol", 0700);
   mkdir("./figs", 0700);   

/* Reads input parameters */

   arq1 = fopen("data.in","r");
   fscanf(arq1,"%lf",&dt);
   fscanf(arq1,"%lf",&tf);
   fscanf(arq1,"%lf",&ts);
   fscanf(arq1,"%lf",&p0);
   fscanf(arq1,"%lf",&theta0);
   fscanf(arq1,"%li",&n);
   fscanf(arq1,"%li",&seed);
   fclose(arq1);
   
   double *r=(double*)malloc(n*sizeof(double));
   double *p=(double*)malloc(n*sizeof(double));
   double *f=(double*)malloc(n*sizeof(double));

   

   printf("=============================================\n");
   printf("  dt,tf,ts= %lf  %lf  %lf\n",dt,tf,ts);
   printf("  p0=  %lf\n",p0);
   printf("  n= %li\n",n);
   printf("=============================================\n\n");

   idum=-seed;

/* Prepares initial conditions */

   condini(n,&idum,p0,theta0,r,p);
   
	phasep = fopen("InitPhase--atr.dat","w");
   
	for (j=0; j<n; ++j)
    {
    	while (r[j]<=-M_PI) r[j]=r[j] + 2.*M_PI;
    	while (r[j] > M_PI) r[j]=r[j] - 2.*M_PI;
                   
		fprintf(phasep,"%le  %le\n",r[j] ,p[j]);			/*Plot phase diagram*/
	}
	
	fclose(phasep);


/* Compute initial kinetic and potential energies */


   force(n,&magx,&magy,r,f);

   kinetic(&kin,n,p);
   kin=kin/(double) n;
   potential=(1.0-magx*magx-magy*magy)/2.0;         /*Atractive potential V -> -V*/

   printf("Initial kinetic and potential energies per particle:\n\n");
   printf("K= %lf  V= %lf\n\n",kin,potential);


   energ0=kin+potential;

/*			Energy and Magnetization			*/
   enrg = fopen("energy.dat","w");
   ferr = fopen("error.dat","w");
   fmag = fopen("mag.dat","w");
   sprintf(ener, "ENERGY-n_%li-p0_%g--ATR", n,p0);
   sprintf(magne, "MAG-n_%li-p0_%g--ATR", n,p0);
   
/*			Phase Portraits			*/      
   sprintf(inic, "Initial-n_%li-p0_%g--ATR", n,p0);
   sprintf(finc, "Final-n_%li-p0_%g--ATR", n,p0);   
   
   time=0.0;
   fprintf(enrg,"%le  %le  %le\n",time,kin,potential);
   fprintf(fmag,"%le  %le  %le\n",time,magx,magy);
   tcount=0.0;



/* time loop */
   while(time<=tf)
   {
     
      timestep(n,dt,&magx,&magy,r,p,f);

      time=time+dt;
      tcount=tcount+dt;

      if (tcount>=ts)
         {
         kinetic(&kin,n,p);
         kin=kin/(double) n;
         potential=(1.0-magx*magx-magy*magy)/2.0;     /*Atractive potential*/
         energ=kin+potential;
         err=(energ-energ0)/energ0;
         err=fabs(err);  
         tcount=0.0;

         fprintf(enrg,"%le  %le  %le\n",time,kin,potential);
         fprintf(ferr,"%le  %le\n",time,err);
         fprintf(fmag,"%le  %le  %le  %le\n",time,magx,magy, sqrt(magx*magx+magy*magy));
         }

   };
   
	phasep = fopen("FinalPhase--atr.dat","w");
   
	for (j=0; j<n; ++j)
    {
    	r[j]-=1.2;
    	while (r[j]<=-M_PI) r[j]=r[j] + 2.*M_PI;
    	while (r[j] > M_PI) r[j]=r[j] - 2.*M_PI;
                   
		fprintf(phasep,"%le  %le\n",r[j] ,p[j]);			/*Plot phase diagram*/
	}
	
	fclose(phasep);



   fclose(enrg);
   fclose(ferr);
   fclose(fmag);


/*		Plotting		*/
  FILE *pipe = popen("gnuplot","w");
  fprintf(pipe, "call 'exportEN.gp' '%s' 'energy.dat'\n",ener);
  fprintf(pipe, "call 'exportMAG.gp' '%s' 'mag.dat'\n",magne);  
  fprintf(pipe, "call 'exportPP.gp' '%s' 'InitPhase--atr.dat'\n",inic);
  fprintf(pipe, "call 'exportPP.gp' '%s' 'FinalPhase--atr.dat'\n",finc);    
  fclose(pipe);



   return;

}
