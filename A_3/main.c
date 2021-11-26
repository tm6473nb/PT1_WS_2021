#include <stdio.h>

#include "string-utils.h"

int main()
{
  int c = 0;
  char Auswahl;

  while (c == 0)
  {
    printf("\nZeichenkettenoperationen\n");
    printf("--------------------------------\n");
    printf("1 Anzahl Zeichen ermitteln\n");
    printf("2 In Grosschreibung konvertieren\n");
    printf("3 Reihenfolge umkehren\n");
    printf("0 Beenden\n");
    printf("--------------------------------\n");
    printf("Ihre Auswahl: ");
    scanf("%c", &Auswahl);
    getchar();
    switch (Auswahl)
    {
      case '1':
        num_chars();
        break;
      case '2':
        to_uppercase();
        break;
      case '3':
        invert();
        break;
      case '0':
        c = 1;
        break;
      default:
        printf("\nDie Eingabe war nicht korrekt!\n");
        break;
    }
  }
  
  printf("[ Shutting down ]\n");
  return 0;
}