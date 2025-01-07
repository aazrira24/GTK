#include <gtk/gtk.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
                                        /*
                                            Structure Position Et Taille Pour Mettre En Position (Et La Taille) De Mon Objet  (Window Button Box ....)
                                        */

#define Max 25
#define Alloue(X)   malloc(sizeof(X))

typedef struct 
{
                                    /*
                                        X Design Soit L'Abscisse X Pour La Position 
                                        Soit La Htr 
                                    */
    int X;
                                    /*
                                        Y Design Soit L'Ordonner Y Pour La Position 
                                        Soit La Largeur 
                                    */
    int Y;
    
}Taille,Position;


