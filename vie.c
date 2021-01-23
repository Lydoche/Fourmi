#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLONNES 20
#define LIGNES 20

// STRUCTURE -------------------------
typedef enum Direction{
	N, E, O, S
	}Direction;

typedef enum Couleur {
	blanc, noir
	}Couleur;
	
typedef enum Occupation {
	vide, fourmi
	}Occupation;

typedef struct Coordonnees{
	int x;
	int y;
	}Coordonnees;
	
typedef struct Spot{
	Coordonnees coordonnees;
	Occupation occupation; 
	Couleur couleur;
	}Spot;
	

typedef struct Fourmi{
	Coordonnees coordonnees;
	Direction direction;
	}Fourmi;

// PROTOTYPES FONCTIONS -------------------------

void place_fourmi(Spot tab[LIGNES][COLONNES],int a, int b);
void case_couleur(Spot tab[LIGNES][COLONNES]);
void reperage_fourmi(Spot tab[LIGNES][COLONNES]);
void affiche_tableau(Spot tab[LIGNES][COLONNES]);
void deplacement(Spot tab[LIGNES][COLONNES]);

// FONCTION MAIN -------------------------

int main () {

int continuer=1;
int x, y;
Fourmi f;
Spot matrice[LIGNES][COLONNES];





printf("où mettre la fourmi ?\n");
scanf("%d, %d", &x, &y);


case_couleur(matrice);
place_fourmi(matrice, x, y);
affiche_tableau(matrice);

printf("Continuer ? 1/0\n");
scanf("%d", &continuer);

if (continuer == 1) {


while (continuer == 1) {
reperage_fourmi(matrice);
deplacement(matrice);
affiche_tableau(matrice);


printf("Continuer ? 1/0\n");
scanf("%d", &continuer);
}

continuer=0;
}


return 0;

}

// IMPLEMENTATION FONCTIONS ----------------------------------

void place_fourmi(Spot tab[LIGNES][COLONNES], int a, int b) {
int i, j;
Fourmi f;

//place la fourmi
for (i=0; i<LIGNES; i++) { 
	for (j=0; j<COLONNES; j++) {
			tab[i][j].occupation=vide;
			}
		}
	
tab[a][b].occupation=fourmi;

f.coordonnees.y=b;
f.coordonnees.x=a;
}

void case_couleur(Spot tab[LIGNES][COLONNES]) {

int i, j, r;

//donne des couleurs aléatoires aux cases
for (i=0; i<LIGNES; i++) {
	for (j=0; j<COLONNES; j++) {
		r=rand()%10;
		if (r < 1) {
		tab[i][j].couleur=noir;
		} else {
		tab[i][j].couleur=blanc;
		}
		
		}
	}
}
	

void reperage_fourmi(Spot tab[LIGNES][COLONNES]) {
int i, j;
Fourmi f;

for (i=0; i<LIGNES; i++) {
	for (j=0; j<COLONNES; j++) {
		if (tab[i][j].occupation==fourmi) {
			f.coordonnees.x=j;
			f.coordonnees.y=i;
			}
		}
	}
}

void deplacement(Spot tab[LIGNES][COLONNES]) {
int i, j;
Fourmi f;
f.direction=N;

for (i=0; i<LIGNES; i++) {
	for (j=0; j<COLONNES; j++) {
		if (tab[i][j].occupation==fourmi && tab[i][j].couleur==blanc && f.direction==N) {
			f.coordonnees.y++;
			f.direction=E;
			}
		else if (tab[i][j].occupation==fourmi && tab[i][j].couleur==blanc && f.direction==E) {
			f.coordonnees.x++;
			f.direction=S;
			}
		
		}
	}

}


void affiche_tableau(Spot tab[LIGNES][COLONNES]) {
int i, j;
Fourmi f;

//affichage du tableau avec cases noires, blanches, et fourmi
for (i=0; i<LIGNES; i++) {
	for (j=0; j<COLONNES; j++) {
		if (tab[i][j].couleur==noir && tab[i][j].occupation==vide) {
			printf("1|");
			} else if (tab[i][j].couleur==blanc && tab[i][j].occupation==vide) {
			printf(" |");
			} else if (i == f.coordonnees.y && j == f.coordonnees.x) {
			printf("F|");
			}
			
		}
	printf("\n");
}
}






