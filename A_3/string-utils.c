#include <stdio.h>
#include <ctype.h>

#include "string-utils.h"

void num_chars()
{
  char nc_ZK[ZK_Size] = {'\0'};

  printf("Geben Sie max. %d Zeichen ein: ", ZK_Size);
  fgets(nc_ZK, (ZK_Size + 1), stdin);
  int num = 0;
  
  int i;
  for (i = 0; i < ZK_Size ; i++)
  {
    if (nc_ZK[i] != '\0' && nc_ZK[i] != '\n')
      num++;
  }
  printf("\nEs sind %d Zeichen in der Zeichenkette.\n", num);
}

void to_uppercase()
{
  char tu_ZK[ZK_Size] = {'\0'};

  printf("Geben Sie max. %d Zeichen ein: ", ZK_Size);
  fgets(tu_ZK, (ZK_Size + 1), stdin);

  char ZK_Up[ZK_Size];

  printf("\nDie Zeichenfolge lautet: ");
  int i;
  for (i = 0; i < ZK_Size ; i++)
  {
    ZK_Up[i] = toupper(tu_ZK[i]);
    printf("%c", ZK_Up[i]);
  }
}

void invert()
{
  char inv_ZK[ZK_Size] = {'\0'};

  printf("Geben Sie max. %d Zeichen ein: ", ZK_Size);
  fgets(inv_ZK, (ZK_Size + 1), stdin);
  
  printf("\nDie Zeichenfolge lautet: ");

  int i;
  for (i = ZK_Size; i >= 0 ; i--)
  {
    if (inv_ZK[i] != '\0' && inv_ZK[i] != '\n')
    {
      printf("%c", inv_ZK[i]);
    }
  }
  printf("\n");
}