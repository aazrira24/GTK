#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Applique_Les_Attributs\Applique_Les_Attributs_ProgressBar.h"


void Applique_Les_Attributs_Option(Option *Ptr,List_Attributs *Ptr_Attributs)
{
    if(!Ptr)
    {
        printf("\n Applique_Les_Attributs_Option | Erreur D\'Adressage");
        exit(0);
    }

    List_Attributs *Ptr_Courant = NULL;
    
    Ptr_Courant = Ptr_Attributs;

    while(Ptr_Courant)
    {
        if ( ! strcmp("Titre",Ptr_Courant->Attribut_Name.Nom_Attribut))
            strcpy(Ptr->Title_Option,Ptr_Courant->Attribut_Name.Valeur_Attribut);
        else if ( ! strcmp("Position",Ptr_Courant->Attribut_Name.Nom_Attribut))
            Ptr->PositionDansComboBox = atoi(Ptr_Courant->Attribut_Name.Valeur_Attribut);
        Ptr_Courant = Ptr_Courant->Svt;
    }
}
