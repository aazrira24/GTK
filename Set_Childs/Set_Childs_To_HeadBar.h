#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Sdd_FichierTXT\Sdd.h"


char *Chercher_Le_Cote_A_Inserer_Dans_HeadBar(Objet_ *Ptr_Objet)
{
    if( !Ptr_Objet )
    {
        printf("\n Chercher_Le_Cote_A_Inserer_Button_Dans_HeadBar | Erreur Dans L\'Adressage.");
        exit(0);
    }
    List_Attributs *Ptr_Courant = NULL;
    Ptr_Courant = Ptr_Objet->List_Attributs_;
    while(Ptr_Courant)
    {
        if( ! strcmp(Ptr_Courant->Attribut_Name.Nom_Attribut,"Cote")) break;
        Ptr_Courant = Ptr_Courant->Svt;
    }
    return (char *) Ptr_Courant->Attribut_Name.Valeur_Attribut; 
}


void Set_Childs_HeadBar(HeaderBar *Ptr_HeadBar,Objet_ *Ptr_Objet)
{
    if( ! Ptr_HeadBar || !Ptr_Objet)
    {
        printf("\n Set_Childs_HeadBar | Erruer D\'Addressage .\n");
        exit(0);
    }
    if( ! strcmp("Button",Ptr_Objet->Nom_Objet))
    {
        char *Cote = Chercher_Le_Cote_A_Inserer_Dans_HeadBar(Ptr_Objet);
        if( ! strcmp(Cote,"Droite") )  Header_Bar_Set_Custum_Droit(Ptr_HeadBar,Ptr_Objet->Ptr_Objet->Ptr_Button->Ptr_Button);
        else Header_Bar_Set_Custum_Gouche(Ptr_HeadBar,Ptr_Objet->Ptr_Objet->Ptr_Button->Ptr_Button);
    }
    else if( ! strcmp("ComboBox",Ptr_Objet->Nom_Objet))
    {
        char *Cote = Chercher_Le_Cote_A_Inserer_Dans_HeadBar(Ptr_Objet);
        if( ! strcmp(Cote,"Droite") )  Header_Bar_Set_Custum_Droit(Ptr_HeadBar,Ptr_Objet->Ptr_Objet->Ptr_ComboBox->ComboBx);
        else Header_Bar_Set_Custum_Gouche(Ptr_HeadBar,Ptr_Objet->Ptr_Objet->Ptr_ComboBox->ComboBx);
    }
}





