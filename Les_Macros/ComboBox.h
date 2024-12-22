#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Macros\Fenetre.h"




void Gtk_ComboBox_New(ComboBox *Ptr,gboolean Type_With_Entry_Or_Not)
{
    if(!Ptr)
    {
        printf("\n\n Macro : Gtk_ComboBox_New | Erreur Dans L\'Adressage.");
        exit(0);
    }
    
    if(Type_With_Entry_Or_Not)   Ptr->ComboBx = gtk_combo_box_text_new_with_entry();
    else Ptr->ComboBx = gtk_combo_box_text_new();

    Ptr->Entry = Type_With_Entry_Or_Not;
}

void Gtk_ComboBox_Ajouter_Option(ComboBox *Ptr,const gchar *Title)
{
    if(!Ptr)
    {
        printf("\n\n Macor : Gtk_ComboBox_Ajouter_Option | Erreur D\'Adresage ");
        exit(0);
    }

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(Ptr->ComboBx),Title);
}

void Gtk_ComboBox_Set_Active(ComboBox *Ptr,const gint Index_Of_Option_Activated)
{
                                                 // Souvent Le Premiere Elem
    if(!Ptr)
    {
        printf("\n\n Macor : Gtk_ComboBox_Set_Active | Erreur D\'Adresage ");
        exit(0);
    }

    Ptr->IndiceActive = Index_Of_Option_Activated;

    gtk_combo_box_set_active(GTK_COMBO_BOX(Ptr->ComboBx), Index_Of_Option_Activated);

}

void Gtk_ComboBox_Insert_In_Position(ComboBox *Ptr,const gchar *Title,const int PositionOfText)
{

                                        /*
                                            On Peux Travail Juste Avec Ce Fonction 
                                                Soit On Indique La Position 
                                                            0 Premier 
                                                            .
                                                            .
                                                            .
                                                            .
                                                            Ou Une Indice Valide 
                                                            Si On Veux Inserer Une Option A La Dernier Position Et On Ne Sait 
                                                            Pas Le Nbrs D'Element Dans Le ComboBox On Peux Mettre -1 Comme PositionOfText 
                                                            Et Le Gtk Va Faire La Tache
                                        */

    if(!Ptr)
    {
        printf("\n\n Macor : Gtk_ComboBox_Insert_In_Position | Erreur D\'Adresage ");
        exit(0);
    }

    gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(Ptr->ComboBx),PositionOfText,Title);

}

void Gtk_ComBoBox_Remove_Option_By_Index(ComboBox *Ptr,const gint PositionOfOption)
{
    if(!Ptr)
    {
        printf("\n\n Macor : Gtk_ComBoBox_Remove_Option_By_Index | Erreur D\'Adresage ");
        exit(0);
    }

    gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(Ptr->ComboBx),PositionOfOption);
}

void Gtk_ComBoBox_Remove_All_Option(ComboBox *Ptr)
{
    if(!Ptr)
    {
        printf("\n\n Macor : Gtk_ComBoBox_Remove_All_Option | Erreur D\'Adresage ");
        exit(0);
    }

    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(Ptr->ComboBx));

}


ComboBox *Gtk_New_ComboBox(
                            gchar *Id
                            ,const gboolean Entry 
                            ,const gint IndiceActive
                            ,const gint X
                            ,const gint Y
                            ,const gint NbrsElemntDansComboBox
                            )
{
    ComboBox *Ptr = (ComboBox *) Alloue(ComboBox);
    if(!Ptr)
    {
        printf("\n\n Macro : Gtk_New_ComboBox | Erreur D\'Allocation Memoire.");
        exit(0);
    }

    Gtk_ComboBox_New(Ptr,Entry);

    Gtk_ComboBox_Set_Active(Ptr,IndiceActive);

    Ptr->Position_ComboBox.X = X;
    Ptr->Position_ComboBox.Y = Y;

    Ptr->NbrOfElmentsDansComboBox = NbrsElemntDansComboBox;

    return (ComboBox *) Ptr;
}



Option *Cree_Option_ComboBox(gchar *Title,const short int PositionDeOption)
{

    Option *Ptr = (Option *) Alloue(Option);

    if(!Ptr)
    {
        printf("\n\n Macro : Cree_Option_ComboBox | Erreur D\'Allocation Dynamique ");
        exit(0);
    }    

    int Cntr = 0;
    for ( ; Cntr < Max ; Ptr->Title_Option[Cntr++] = '\0');

    Cntr = 0;

    for( ; Cntr < Max && Title[Cntr] != '\0' ; Ptr->Title_Option[Cntr] = Title[Cntr++]);

    Ptr->PositionDansComboBox = PositionDeOption;

    Ptr->Svt = NULL;

    return (Option *) Ptr;

}

Option *Inserer_Option_Dans_List(Option *Ptr_List,Option *New_Option)
{

                                /*
                                    Inserer A La Fin
                                */

    if(!New_Option) return (Option *) Ptr_List;
    if(!Ptr_List) return (Option *) Cree_Option_ComboBox(New_Option->Title_Option,New_Option->PositionDansComboBox);
    Ptr_List ->Svt = Inserer_Option_Dans_List(Ptr_List->Svt,New_Option);
    return (Option *) Ptr_List;
}

int NbreElmentListOption(Option *Ptr_List)
{
    if(!Ptr_List) return (int) 0;
    return (int) ( 1 + NbreElmentListOption(Ptr_List->Svt) );
}

void Inserer_List_Option_Dans_ComboBox(ComboBox *Ptr_ComboBox,Option *Ptr_List)
{
    if(!Ptr_ComboBox || !Ptr_List)
    {
        printf("\n\n Macro : Inserer_List_Option_Dans_ComboBox | Erreur D\'Adressage ");
        exit(0);
    }    

    while (Ptr_List)
    {
        Gtk_ComboBox_Ajouter_Option(Ptr_ComboBox,Ptr_List->Title_Option);
        Ptr_List = Ptr_List->Svt;
    }
}

