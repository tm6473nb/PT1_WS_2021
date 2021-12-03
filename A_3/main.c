#include <stdio.h>
#include "string-utils.h"

int main()
{

//  printf("%d = %c \n %c +10 = %c",
//    'A','A',
//    'A', 'A'+33
//  );
  int num;
  int c = 0;
  char ZK[21];
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

    if (Auswahl == '0')
    {
      c = 1;
      break;
    }
    else
    {
      printf("Geben Sie max. 20 Zeichen ein: ");
      fgets(ZK, (21), stdin);

      switch (Auswahl)
      {
        case '1':
          num = num_chars(ZK);
          printf("\nEs sind %d Zeichen in der Zeichenkette.\n", num);
          break;
        case '2':
          *ZK = to_uppercase(ZK);
          printf("\nDie Zeichenkette lautet: %s\n", ZK);
          break;
        case '3':
          *ZK = invert(ZK);
          printf("\nDie Zeichenkette lautet: %s\n", ZK);
          break;
        default:
          printf("\nDie Eingabe war nicht korrekt!\n");
          break;
      }
    }
  }
  
  printf("[ Shutting down ]\n");
  return 0;
}