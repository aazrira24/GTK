#include  "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Applique_Les_Attributs\Applique_Les_Attributs_Fixed.h"


void Applique_Les_Attributs_Fenetre(Fenetre *Ptr,List_Attributs *Ptr_List)
{
    if(!Ptr)
    {
        printf("\n Applique_Les_Attributs_Fenetre | Erreur D\'Adressage");
        exit(0);
    }
    while(Ptr_List)
    {
        if( ! strcmp("Titre",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Fenetre_Set_Title(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut); 
        else if( ! strcmp("Icon",Ptr_List->Attribut_Name.Nom_Attribut))
            Fenetre_Set_Icon(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut,0);
        else if( ! strcmp("Resizable",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Fenetre_Definir_Redimensionnable(Ptr,atoi(Ptr_List->Attribut_Name.Valeur_Attribut));
        else if( ! strcmp("ColorBg",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Fenetre_Set_BackGround_Color(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        else if( ! strcmp("BackGround",Ptr_List->Attribut_Name.Nom_Attribut))  
                                        Fenetre_Set_BackGround_Image(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        else if( !strcmp("Type",Ptr_List->Attribut_Name.Nom_Attribut))
        {
            if( !strcmp("Normal",Ptr_List->Attribut_Name.Valeur_Attribut) ) Fenetre_Set_Type(Ptr,Normal);
            else Fenetre_Set_Type(Ptr,Not_Normal);
        }
        else if( ! strcmp("Position",Ptr_List->Attribut_Name.Nom_Attribut))  
                                        Fenetre_Definir_Position(Ptr,atoi(Ptr_List->Attribut_Name.Valeur_Attribut),atoi(Ptr_List->Attribut_Name.Valeur_Attribut));
        else if( ! strcmp("Taille",Ptr_List->Attribut_Name.Nom_Attribut))  
                                        Fenetre_Definir_Taille(Ptr,atoi(Ptr_List->Attribut_Name.Valeur_Attribut),atoi(Ptr_List->Attribut_Name.Valeur_Attribut));
        Ptr_List = Ptr_List->Svt;
    }
}
