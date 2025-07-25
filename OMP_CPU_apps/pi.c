/*

This program will numerically compute the integral of

                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
gives us an easy way to check the answer.

The is the original sequential program.  It uses the timer
from the OpenMP runtime library

*/
#include <stdio.h>
#include <omp.h>
static long num_steps = 100000000;
double step;
int main ()

{
	  int i;
	  double pi, sum = 0.0;
	  double start_time, run_time;

	  step = 1.0/(double) num_steps;

        	 
	  start_time = omp_get_wtime();
    //omp_set_num_threads(24);
    #pragma omp parallel for reduction (+:sum)
	  for (i=1;i<= num_steps; i++){
		  double x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }

	  pi = step * sum;
	  run_time = omp_get_wtime() - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
}	  

