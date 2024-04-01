#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine[256] ;

typedef struct noeud{

    chaine ID_salle ;
    int capacite ;
    struct noeud* sag ;
    struct noeud* sad ;
} Noeud ;

typedef Noeud* Arbre ;

int max(int a, int b);
int hauteur(Arbre ar);
Arbre creer_noeud(chaine , int , Arbre , Arbre );
Arbre inserer_hauteur(Arbre ar, chaine ID_salle, int valeur) ;
Arbre inserer_random(Arbre ar, chaine ID_salle, int valeur) ;
Arbre inserer_abr(Arbre ar, chaine ID_salle, int valeur) ;
void affiche(Arbre ar);

#endif
