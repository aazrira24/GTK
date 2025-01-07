#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Applique_Les_Attributs\Applique_Les_Attributs_ComboBox.h"

void Applique_Les_Attributs_Button(Button *Ptr,List_Attributs *Ptr_List)
{
    if(!Ptr)
    {
        printf("\n Applique_Les_Attributs_Button | Erreur D\'Adressage");
        exit(0);
    }
    while(Ptr_List)
    {
        if( ! strcmp("Mnemonic",Ptr_List->Attribut_Name.Nom_Attribut))
        {
            if( ! strcmp("FALSE",Ptr_List->Attribut_Name.Valeur_Attribut))
            {
                free(Ptr->Ptr_Button);
                Gtk_Button_New_Objet(Ptr,FALSE);
            }
            /*
                Car Dans La Construction de Notre Button par Defaut On Le Construit Avec Mnemonic
            */
        }
        else if( ! strcmp("Always_Show_Image",Ptr_List->Attribut_Name.Nom_Attribut))
        {
            if( ! strcmp("TRUE",Ptr_List->Attribut_Name.Valeur_Attribut))
                            Gtk_Button_Always_Show_Image_Or_Not(Ptr,TRUE);
            else Gtk_Button_Always_Show_Image_Or_Not(Ptr,FALSE);
        }
        else if( ! strcmp("Position",Ptr_List->Attribut_Name.Nom_Attribut))
        {
                            Ptr->Position_.X = atoi(Ptr_List->Attribut_Name.Valeur_Attribut); 
                            Ptr->Position_.Y = atoi(Ptr_List->Attribut_Name.Valeur_Attribut);
        }
        else if( ! strcmp("Label",Ptr_List->Attribut_Name.Nom_Attribut))
        {
                                        printf("\n %sjjjjj\n",Ptr_List->Attribut_Name.Valeur_Attribut);
                                        Gtk_Button_Set_Label(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);

        }
        else if( ! strcmp("Image",Ptr_List->Attribut_Name.Nom_Attribut))  
                                        Gtk_Button_Set_Image(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut,30,30);
                                        /*
                                            30 Valeur Pour Image
                                        */
        else if( !strcmp("Color",Ptr_List->Attribut_Name.Nom_Attribut))
                                        Gtk_Button_Set_Color(Ptr,Ptr_List->Attribut_Name.Valeur_Attribut);
        Ptr_List = Ptr_List->Svt;
    }
}
