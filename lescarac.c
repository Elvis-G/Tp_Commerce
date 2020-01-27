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
    char* nom;
    int prix;
    int poids;
    int quantite;
};

typedef struct Inventaire Inventaire_t;
struct Inventaire
{
    int inventaire;
    int inventairemax;
    int poids;
    int poidsMax;
    int argent;
};



int main (){

int jeu = 0;
char coffre;

Inventaire_t herosInventaire ={0, 10, 0, 25, 150};

Items_t bouclier ={"Bouclier", 30, 4, 3};
Items_t epee ={"Épée", 50, 3, 5};
Items_t plastron ={"Plastron", 40, 5, 2};
Items_t potiondeSoin ={"Potion de Soin", 30, 1, 15};
Items_t potiondeRez ={"Potion de Resurrection", 200, 1, 5};

Items_t shop[5];
shop[0] = bouclier;
shop[1] = epee;
shop[2] = plastron;
shop[3] = potiondeSoin;
shop[4] = potiondeRez;

while (jeu == 0){

SetColor(8);

printf("%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                       SHOP DU COMMERCANT                    |");
printf("%s\n", "                           |_____________________________________________________________|");



printf("\n%s\n\n", "******************  Bouclier  ******************");
printf("%s%d\n", "Prix : ", bouclier.prix);
printf("%s%d\n", "Poids : ", bouclier.poids);
printf("%s%d\n", "Quantite : ", bouclier.quantite);

printf("\n%s\n\n", "******************  Epee  ******************");
printf("%s%d\n", "Prix : ", epee.prix);
printf("%s%d\n", "Poids : ", epee.poids);
printf("%s%d\n", "Quantite : ", epee.quantite);

printf("\n%s\n\n", "******************  Plastron  ******************");
printf("%s%d\n", "Prix : ", plastron.prix);
printf("%s%d\n", "Poids : ", plastron.poids);
printf("%s%d\n", "Quantite : ", plastron.quantite);

printf("\n%s\n\n", "******************  Potion de Soin  ******************");
printf("%s%d\n", "Prix : ", potiondeSoin.prix);
printf("%s%d\n", "Poids : ", potiondeSoin.poids);
printf("%s%d\n", "Quantite : ", potiondeSoin.quantite);

printf("\n%s\n\n", "******************  Potion de Resurrection  ******************");
printf("%s%d\n", "Prix : ", potiondeRez.prix);
printf("%s%d\n", "Poids : ", potiondeRez.poids);
printf("%s%d\n\n", "Quantite : ", potiondeRez.quantite);

SetColor(15);

Sleep(2000);


SetColor(3);

printf("\n\n%s\n", "                            _____________________________________________________________ ");
printf("%s\n", "                           |                                                             |");
printf("%s\n", "                           |                        VOTRE INVENTAIRE                     |");
printf("%s\n", "                           |_____________________________________________________________|");



printf("\n%s\n\n", "******************  Inventaire  ******************");
printf("%s%d%s%d\n", "Espace libre dans votre inventaire : ", herosInventaire.inventaire, "/", herosInventaire.inventairemax);
printf("%s%d%s%d\n", "Poids libre dans votre inventaire : ", herosInventaire.poids, "/", herosInventaire.poidsMax);
printf("%s%d%s\n\n", "Votre argent : ", herosInventaire.argent, " Pesos");

SetColor(15);
Sleep(1000);
printf("%s\n\n", "----------------------------------------------------");
printf("%s\n", "Avez vous un items qui correspond a vos attentes ? Si oui taper le nom de l'objet souhaite ci-dessous, si non, entrer [rien]");
printf("\n%s\n", "[Bouclier ; Epee ; Plastron ; Potion de Soin ; Potion de Resurrection]");
printf("%s", "Item : ");
scanf("%s", &coffre);

if (coffre == *shop->nom) {
  printf("\n%s\n", "Vous venez d'acheter un Bouclier");
bouclier.quantite = bouclier.quantite - 1;
herosInventaire.argent = herosInventaire.argent - bouclier.prix;
herosInventaire.poids = herosInventaire.poids + bouclier.poids;
}

SetColor(8);
printf("\n\n%s\n\n", "******************  Bouclier  ******************");
printf("%s%d\n", "Prix : ", bouclier.prix);
printf("%s%d\n", "Poids : ", bouclier.poids);
printf("%s%d\n", "Quantite : ", bouclier.quantite);
SetColor(15);


SetColor(3);
printf("\n\n%s\n\n", "******************  Inventaire  ******************");
printf("%s%d%s%d\n", "Espace libre dans votre inventaire : ", herosInventaire.inventaire, "/", herosInventaire.inventairemax);
printf("%s%d%s%d\n", "Poids libre dans votre inventaire : ", herosInventaire.poids, "/", herosInventaire.poidsMax);
printf("%s%d%s\n\n", "Votre argent : ", herosInventaire.argent, " Pesos");
SetColor(15);

if (coffre == *"rien"){
  jeu == 1;
}

}

return 0;
}
