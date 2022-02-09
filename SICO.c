#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double MySin(double x, double E)
{
  double sum, an, n;
  sum = x;
  an = x;
  n = 0;

  while (an > E || an < -E)
  {
    an *= (-1) * x * x / ((2 * n + 2) * (2 * n + 3));
    sum += an;
    n++;
  }

  return sum;
}

double MyCos(double x, double E)
{
  double sum, an, n;
  sum = 1;
  an = 1;
  n = 1;

  while (an > E || an < -E)
  {
    an *= (-1) * x * x / ((2 * n - 1) * (2 * n));
    sum += an;
    n++;
  }

  return sum;
}

void main ( void )
{
  double x;
  int i;
  printf("Input a number: ");
  scanf("%lf", &x);
  printf("\nDegrees: %f\n", x);

  double PI = 3.14159265358979;
  x = x * PI / 180;
  printf("\nRadians: %f\n", x);
  
  printf("Math sin(x) = %.15f, Math cos(x) = %.15f\n", sin(x), cos(x));

  for (i = 1; i < 15; i++)
  {
    double E = 1 / pow(10,i);
    printf("I = %i\n", i);
    printf("sin(x) = %.15f, cos(x) = %.15f, accuracy is %.15f\n", MySin(x, E), MyCos(x, E), E);
  }
}



