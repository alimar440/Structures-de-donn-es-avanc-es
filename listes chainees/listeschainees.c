#include "listeschainees.h" 
listePersonne creer_maillon (chaine ch ,int n) {

    listePersonne m = (listePersonne)malloc(sizeof(Personne)) ;

    if(m){

        m->age = n ;
        strcpy(ch , m->nom) ; 
        m->suiv = NULL ;
        return m ;

    }else {
        printf("pas assez d'espace") ;
        exit(-1) ;
    }

}
listePersonne detruire_maillon (listePersonne m ) {
    if(m){

        free(m) ;
        m = NULL ;
        return ; ;
    }
}

listePersonne saisie_liste(int nb) {

    listePersonne tete , sauv , courant ;
    chaine nom ;  int age ; 

    if(nb>0){

        printf("Donnees de la tete \n") ;
        printf("nom : ") ;
        gets(nom) ;
        printf("\nage : ") ;
        scanf("%d" , &age) ;
        printf("\n") ;

        sauv = creer_maillon(nom , age) ;
        tete = sauv ;  courant = sauv ;

        for(int i = 1 ; i<nb ; i++){
            printf("Donnez l'element %d \n",i) ;
            printf("nom : ") ;
            gets(nom) ;
            printf("\nage : ") ;
            scanf("%d" , &age) ;
            printf("\n\n") ;

            sauv = creer_maillon(nom , age) ; 
            courant->suiv = sauv ;
            courant = courant->suiv ;
        }

        return tete ;

    }

}
listePersonne detruire_liste (listePersonne tete) {
    if(tete){

      listePersonne courant = tete;
    
      while(courant){

        courant = courant->suiv ;
        tete = detruire_maillon(tete) ;
        tete = courant ;
      }
    }
    return tete ;
}
listePersonne inserer_tete (listePersonne tete, chaine ch , int n) {

    listePersonne m = creer_maillon(ch , n ) ;

    m->suiv = tete ;
    tete = m ;
    return tete ;

}
listePersonne inserer_queue (listePersonne tete, chaine ch , int n) {

    listePersonne m = creer_maillon(ch , n ) ;

    if(!tete)
        return m ;
    else{

        listePersonne courant = tete ;
        while(courant->suiv != NULL) {
            courant = courant->suiv ;
        }
        courant->suiv = m ;

    }
    return tete ;

}
listePersonne inserer_position (listePersonne tete, chaine ch , int n , int nb) {

    listePersonne prec , courant , sauv ;
    sauv = creer_maillon(ch , n) ;

    if(!tete){
        tete = sauv ;
    }else{

        prec = tete ;    courant = tete ; 
        for(int i = 0 ; i<nb ; i++ ){
            prec = courant ;
            courant = courant->suiv ;
        }

        sauv->suiv = courant->suiv ;
        prec->suiv = sauv ;

    }

    return tete ;

} 
void afficher_maillon (listePersonne tete) {
    if(tete)
        printf("(%s : %d  )-->", tete->nom , tete->age ) ;

}
void afficher_liste (listePersonne tete) {

    listePersonne courant = tete ;

    while(courant){
        afficher_liste(courant) ; 
        courant = courant->suiv ;
    }
    printf("NULL\n\n") ;
}
void afficher_liste_rec (listePersonne tete) {
    if(tete){
        afficher_maillon(tete) ;
        afficher_liste_rec(tete->suiv) ;
    }
}
int Age_Max_rec(listePersonne tete) {
    
    if(!tete)
        return -1 ;
    else{
        if(!tete->suiv) 
            return 1 ;
        else {
            int m = Age_Max_rec(tete->suiv) ;
            return (tete->age > m ? tete->age : m) ;
        }
    }
}
int longueur_liste (listePersonne tete) {
    int i = 0 ; 
    while(tete){
        i++ ;
        tete = tete->suiv ;
    }
    return i ;
}
listePersonne supprimer_tete (listePersonne tete) {
    listePersonne p = tete ;
    if(tete){
      tete = tete->suiv ;
      p = detruire_maillon(p) ;
    }
    return tete ;
}
listePersonne supprimer_queue (listePersonne tete) {
    listePersonne courant ; 
    if(!tete){
        while(courant->suiv){
            courant = courant->suiv ; 
        }
        courant->suiv = detruire_maillon(courant->suiv) ;
        return tete ;
    }
}
listePersonne supprimer_position (listePersonne tete , int pos) {
    listePersonne prec , courant , p ;

    
  if(tete){
    prec = tete ;   courant = tete ;
    for(int i = 0 ; i<pos ; i++){

        prec = courant ;
        courant = courant->suiv ;

    }
    p = courant ;
    prec->suiv = courant->suiv ;
    p = detruire_maillon(p) ;

    return tete ;
  }
}
listePersonne TTL(tableauPersonne tab, int n ) {
    listePersonne tete ;

    for(int i = n-1 ; i>=0 ; i--){

        tete = inserer_tete(tete , tab[i].nom , tab[i].age ) ;

    }
    return tete ; 

}
tableauPersonne TLT(listePersonne tete, int *n){

    *n = longueur_liste(tete) ;
    tableauPersonne t = (tableauPersonne)malloc((*n)*sizeof(tpersonne)) ;
    int i = 0 ;

    while(tete){
        t[i].age = tete->age ;
        strcpy(t[i].nom , tete->nom) ;
        tete = tete->suiv ; 
        i++ ;

    }
} 
/*--------------------------------------------------------------------------------------------------------------------------------------------------------*/
