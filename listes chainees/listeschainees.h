#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char chaine[30] ;

typedef struct personne{
    chaine nom ;
    int age ;
    struct personne *suiv ;
}Personne ;

typedef struct tpersonne{
    chaine nom ;
    int age ;
}tpersonne ;

typedef personne *listePersonne ;
typedef tpersonne *tableauPersonne ;

listePersonne creer_maillon (chaine,int) ;
listePersonne detruire_maillon (listePersonne) ;
listePersonne saisie_liste(int) ;
listePersonne detruire_liste (listePersonne) ;
listePersonne inserer_tete (listePersonne , chaine , int) ;
listePersonne inserer_queue (listePersonne , chaine , int) ;
listePersonne inserer_position (listePersonne , chaine , int) ;
void afficher_maillon (listePersonne) ;
void afficher_liste (listePersonne) ;
void afficher_liste_rec (listePersonne) ;
int longueur_liste (listePersonne) ;
listePersonne supprimer_tete (listePersonne) ;
listePersonne supprimer_queue (listePersonne) ;
listePersonne supprimer_position (listePersonne , int ) ;
listePersonne TTL(tableauPersonne , int ) ;
tableauPersonne TLT(listePersonne , chaine ) ;
void TLF (listePersonne , chaine) ;
listePersonne TFL (chaine) ;
int Age_Max_rec(listePersonne) ;


