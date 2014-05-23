#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f1(double t, double yt)
{
  return -2*yt + t*t -2*t + 3;
}

double f2(double t, double yt)
{
  return -yt*(3*t*t+1);
}

double* eulerExplicite(double a, double b, double f(double,double), int n, double ci)
{
  double h = (b-a)/n;
  double tmp;
  double *res = NULL;
  int i;

  res = malloc(n*sizeof(double));

  res[0] = ci;

  for(i=1;i<n;i++)
  {
    tmp = a + i*h;
    res[i] = res[i-1] + h*f(tmp, res[i-1]);
  }

  return res;
}

void exemple1EulerExplicite()
{
  int n = 1000, i;
  double a = 0, b = 5;
  double h = (b-a)/n;
  double tmp;
  double* res;

  /*
   * y'(x) = 2*y(x) + x et y(0) = 1
   * solution : y(x) = exp(-5/4*exp(-2x) + x^2/2 -3*x/2 + 9/4
   */

  printf("Exemple 1\n");
  res = eulerExplicite(a,b,f1,n,1);
  for(i=0;i<n;i++)
  {
    tmp = a + i*h;
    printf("x: %g \t fexp(x) - fth(x): %g\n",tmp,res[i] - (-5/4*exp(-2*tmp)+tmp*tmp/2-3*tmp/2+9/4));
  }
}

void exemple2EulerExplicite(void)
{
  int n = 1000, i;
  double a = 0, b = 5;
  double h = (b-a)/n;
  double tmp;
  double* res;

  /*
   * y'(x) = 4*y(x) et y(0) = 7
   * solution : y(x) = 7exp(4x)
   */

  res = eulerExplicite(a,b,f2,n,5);
  printf("Exemple 2\n");
  for(i=0;i<n;i++)
  {
    tmp = a + i*h;
    printf("x: %g \t fexp(x) - fth(x): %g\n",tmp, res[i] - 5*exp(-tmp*tmp*tmp - tmp));
  }
}

