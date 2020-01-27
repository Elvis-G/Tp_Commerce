#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

void SetColor(int ForgC) {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

typedef struct Items Items_t;
struct Items
{
    char nom;
    int prix;
    int quantite;
};

typedef struct Inventaire Inventaire_t;
struct Inventaire
{
    char nom;
    int prix;
    int quantite;
};



int main (){

char decombat[4] = "123";
printf("%s\n", decombat);


char decombat[4] = "123";
printf("%s\n", decombat);


scanf("%d", &coffre);
return 0;
}
