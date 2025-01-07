#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Applique_Les_Attributs\Applique_Les_Attributs_Option.h"


void Applique_Les_Attributs_HeaderBar(HeaderBar *Ptr,List_Attributs *Ptr_List)
{
    if(!Ptr)
    {
        printf("\n Applique_Les_Attributs_HeaderBar | Erreur D\'Adressage");
        exit(0);
    }

    while(Ptr_List)
    {
        if( ! strcmp("Titre",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Header_Set_Title(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut); 
        else if( ! strcmp("Icon",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Header_Set_Icon(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        else if( ! strcmp("SubTitle",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Header_Set_Sous_Title(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        else if( ! strcmp("Close Button",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Header_Set_Close_Button(Ptr,atoi(Ptr_List->Attribut_Name.Valeur_Attribut));
        else if( ! strcmp("Decoration",Ptr_List->Attribut_Name.Nom_Attribut))  
                                        HeadrBar_Set_Decoration_Lyout(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        Ptr_List = Ptr_List->Svt;
    }
}
