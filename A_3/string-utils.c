#include <stdio.h>
#include <ctype.h>

#include "string-utils.h"

int num_chars(char * nc_ZK)
{
  int nc_num = 0;
  int nc_c = 0;

  while (nc_c == 0)
  {
    if (*nc_ZK == '\n')
    {
      nc_c = 1;
      break;
    }
    else
    {
        nc_num++;
    }
    nc_ZK++;
  }
  return nc_num;
}

char to_uppercase(char * tu_ZK)
{
  int tu_c = 0;
  int z = 0;

  while (tu_c == 0)
  {
    if (*tu_ZK == '\n')
    {
      tu_c = 1;
      *tu_ZK = '\0';
    }
    else
    {
      if ((*tu_ZK >= 97) && (*tu_ZK <= 122))
      {
        *tu_ZK -= 32;
      }
    }
  tu_ZK++;
  z++;
  }
  tu_ZK-= z;
  return *tu_ZK;
}

char invert(char * ni_ZK)
{
  int i_num;
  i_num = num_chars(ni_ZK);
  
  ni_ZK += i_num;
  *ni_ZK = '\0';
  ni_ZK -= i_num;

  int i_z = 0;

  char i_ZK[20];

  for (int i = (i_num - 1); i >= 0; i--)
  {
    ni_ZK += i;
    i_ZK[i_z] = *ni_ZK;
    ni_ZK-= i;
    i_z++;
  }

//Funktioniert noch nicht

  return *i_ZK;
}