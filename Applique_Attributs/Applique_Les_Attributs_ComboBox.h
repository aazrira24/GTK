#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Applique_Les_Attributs\Applique_Les_Attributs_Fenetre.hxx"


void Applique_Les_Attributs_ComboBox(ComboBox *Ptr_ComboBox,List_Attributs *Ptr_Attris)
{
    if(!Ptr_ComboBox)
    {
        printf("\n Applique_Les_Attributs_ComboBox | Erreur D\'Adressage.");
        exit(0);
    }
    List_Attributs *Ptr_Courant = NULL;
    Ptr_Courant = Ptr_Attris;
    while(Ptr_Courant)
    {
        if( ! strcmp(Ptr_Courant->Attribut_Name.Nom_Attribut,"Active"))
                    Gtk_ComboBox_Set_Active(Ptr_ComboBox,atoi(Ptr_Courant->Attribut_Name.Valeur_Attribut));
        Ptr_Courant = Ptr_Courant->Svt;
    }

}
