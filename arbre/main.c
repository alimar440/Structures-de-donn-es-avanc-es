#include "arbre.h" 

int main(){

    Arbre ar = creer_noeud("FS00",4,NULL,NULL) ;
    ar = inserer_abr(ar ,"FS01", 3) ;
    ar = inserer_abr(ar ,"FS03", 6) ;
    ar = inserer_abr(ar ,"FS02", 12) ;
    ar = inserer_abr(ar ,"FS05", 11) ;
    ar = inserer_abr(ar ,"FS04", 4) ;
    ar = inserer_abr(ar ,"FS06", 3) ;
    ar = inserer_abr(ar ,"FS07", 6) ;

    printf("\n\n\n");

    affiche(ar) ;

    printf("\n\n\nhauteur sad = %d    \n HAUTEUR sag = %d", hauteur(ar->sad ) , hauteur(ar->sag )) ;
    

    printf("\n\n\n");





    return 0 ;
}