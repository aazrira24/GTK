#include "C:\Users\LENOVO\Desktop\GTK\GTK\Fichie_TXT\Set_Childs\Set_Childs_To_ComboBox.h"

void Set_Child_To_Fenetre(Fenetre* fen,Objet_* Child)
{
    if (! strcmp(Child->Nom_Objet,"VBox") || ! strcmp(Child->Nom_Objet,"HBox"))
        gtk_container_add(GTK_CONTAINER(fen->Wind),Child->Ptr_Objet->Ptr_Box->MyBox);
    else if(! strcmp(Child->Nom_Objet,"ScrollBar"))
        gtk_container_add(GTK_CONTAINER(fen->Wind),Child->Ptr_Objet->Ptr_ScrollBar->scrolled_window);
    else if(! strcmp(Child->Nom_Objet,"Fixed"))
        gtk_container_add(GTK_CONTAINER(fen->Wind),Child->Ptr_Objet->Ptr_Fixed->fix);
    else if(! strcmp(Child->Nom_Objet,"Onglets"))
        gtk_container_add(GTK_CONTAINER(fen->Wind),Child->Ptr_Objet->Ptr_Onglets->notebook);
    else if( ! strcmp(Child->Nom_Objet,"HeadBar"))
        gtk_window_set_titlebar(GTK_WINDOW(fen->Wind),Child->Ptr_Objet->Ptr_HeadBar->HeadBar);
    else if( ! strcmp(Child->Nom_Objet,"Button"))
            gtk_container_add(GTK_CONTAINER(fen->Wind),Child->Ptr_Objet->Ptr_Button->Ptr_Button);

}
