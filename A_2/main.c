#include <stdio.h>
#include <stdlib.h>

int greatest_common_divisor(int gcd_a, int gcd_b)
{
  int c = 0; /*c = counter*/
  if (gcd_a != gcd_b)
  {
    while(c == 0)
    {
      if (gcd_a > gcd_b)
      {
        gcd_a = gcd_a - gcd_b;
        if (gcd_a == 0)
        {
          gcd_a = gcd_b;
          c = 1;
        }
      }
      else
      {
        gcd_b = gcd_b - gcd_a;
        if (gcd_b == 0)
        {
          c = 1;
        }
      }
    }
  }
  return gcd_a;
}

int main ()
{
  int z1;
  int z2;
  int d;

  printf("Zahl 1: ");
  scanf("%i", &z1);
  printf("Zahl 2: ");
  scanf("%i", &z2);
  z1=abs(z1);
  z2=abs(z2);
  d = greatest_common_divisor(z1, z2);
  printf("Der groesste gemeinsame Teiler ist: %i", d);
  return 0;
}
