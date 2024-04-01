#include "arbre.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int hauteur(Arbre ar) {
    if (ar == NULL) return 0;
    return 1 + max(hauteur(ar->sad), hauteur(ar->sag));
}

Arbre creer_noeud(chaine ID_salle , int capacite, Arbre gauche, Arbre droit) {
    Arbre noeud = (Arbre)malloc(sizeof(Noeud));
    if (noeud != NULL) {
        strcpy(noeud->ID_salle ,ID_salle);
        noeud->capacite = capacite;
        noeud->sag = gauche;
        noeud->sad = droit;
    }
    return noeud;
}

Arbre inserer_hauteur(Arbre ar, chaine ID_salle, int valeur) {
    if(ar == NULL){
        ar = creer_noeud( ID_salle ,valeur , NULL , NULL ) ;
    }else{
        if(ar->sad == NULL)
            ar->sad = creer_noeud(ID_salle ,valeur , NULL , NULL ) ;
        else {
            if(ar->sag == NULL){
                ar->sag = creer_noeud(ID_salle ,valeur , NULL , NULL ) ;
            }else{
                if(hauteur(ar->sad) > hauteur(ar->sag))
                    ar->sag = inserer_hauteur(ar->sag , ID_salle , valeur) ;
                else
                    ar->sad = inserer_hauteur(ar->sad , ID_salle , valeur) ;
            }
         }
        
    }
    return ar;
}

Arbre inserer_random(Arbre ar, chaine ID_salle, int valeur) {

    if(ar == NULL){

        ar = creer_noeud(ID_salle ,valeur , NULL , NULL ) ;

    }else{
        int random = rand()%2 ; 
        if(random == 0 )
            ar->sag =    inserer_hauteur(ar->sag , ID_salle , valeur) ;
        else
            ar->sad =    inserer_hauteur(ar->sag , ID_salle , valeur) ;
    }
    return ar ;
}

Arbre inserer_abr(Arbre ar, chaine ID_salle, int valeur)  {

    if (ar == NULL) {

         ar = creer_noeud(ID_salle ,valeur , NULL , NULL );

    } else 
        if (strcmp(ID_salle, ar->ID_salle) <0) {
       
              ar->sag = inserer_abr(ar->sag , ID_salle , valeur);

        } else 

            ar->sad = inserer_abr(ar->sad , ID_salle , valeur);

    
    
    return ar;
}

int recherche(Arbre ar , chaine id){

    if(ar== NULL)   return  0 ;
    if(strcmp(id , ar->ID_salle)== 0 )  return  1 ;
    if(strcmp(id , ar->ID_salle)<0) 
        return recherche(ar->sag , id) ;
    else
        return recherche(ar->sad , id) ;

    

}

        

void affiche(Arbre ar) {
    if(ar == NULL) return;
    affiche(ar->sag);
    printf("\n    %s  |  %d     \n ",ar->ID_salle , ar->capacite);
    affiche(ar->sad);
    
}