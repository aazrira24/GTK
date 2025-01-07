#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Set_Childs\Set_Childs_To_HeadBar.h"

void Set_ComboBox_Childs(ComboBox *Ptr_ComboBox,Objet_ *Ptr_Objet)
{
    if( ! Ptr_ComboBox || ! Ptr_Objet)
    {
        printf("\n Set_ComboBox_Childs | Erreur D\'Adressage.");
        exit(0);
    }
    Option *Ptr_Courant = NULL;
    Ptr_Courant = Ptr_Objet->Ptr_Objet->Ptr_Option;
    while(Ptr_Courant)
    {
        
        Gtk_ComboBox_Insert_In_Position(Ptr_ComboBox,Ptr_Courant->Title_Option,Ptr_Courant->PositionDansComboBox);
        Ptr_Courant = Ptr_Courant->Svt;
    }
}
