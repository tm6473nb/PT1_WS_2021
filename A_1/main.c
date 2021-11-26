#include <stdio.h>
#include <math.h>

/*
Maximaler Tankinhalt  --> max_fuel
Kraftstoffverbrauch   --> fuel_con
Gefahrene Strecke     --> driven_dist
Restlicher Kraftstoff --> fuel_rest
Rest in Prozent       --> fuel_rest_p
*/

int max_fuel;
float fuel_con;
float driven_dist;
float fuel_rest;
float fuel_rest_p;


float calculation (int fuel_0, float con_0, float dist_0, float rest_0)
{
  rest_0 = (fuel_0 - ((con_0/100) * dist_0));
  return rest_0;
}

float calculation_percentage (int fuel_1, float rest_1, float rest_p_1)
{
  rest_p_1 = ((rest_1/fuel_1)*100);
  return rest_p_1;
}

int main()
{
  printf("Maximaler Tankinhalt in L: ");
  scanf("%d", &max_fuel);
  printf("Kraftstoffverbrauch in L / 100 km: ");
  scanf("%f", &fuel_con);
  printf("Gefahrene Strecke in km: ");
  scanf("%f", &driven_dist);

  fuel_rest = calculation(max_fuel, fuel_con, driven_dist, fuel_rest);

  fuel_rest_p = calculation_percentage(max_fuel, fuel_rest, fuel_rest_p);

  int fuel_rest_r = round(fuel_rest);

  int fuel_rest_p_r = round(fuel_rest_p);

  printf("Verbleibender Tankinhalt: %d (%d Prozent)\n", fuel_rest_r, fuel_rest_p_r);

  return 0;
}