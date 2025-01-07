#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Macros\Onglets.h"


/*
        Fonction Pour Affecter Une Titre Pour Le Head Bar

                Entre :
                        Pointeur Sur HeaderBar, Chaine De Caracteres
                Sortie :
                        Rien
*/

void Header_Set_Title(HeaderBar *Bar_Ptr,char *Title)
{
    if(!Bar_Ptr)
    {
        printf("Erreur Dans Adress Header Bar.");
        exit(0);
    }

    Bar_Ptr->Title = g_strdup(Title);

    gtk_header_bar_set_title(GTK_HEADER_BAR(Bar_Ptr->HeadBar), Title);
}

/*
        Fonction Pour Affecter Une Sous Titre Pour Le Head Bar

                Entre :
                        Pointeur Sur HeaderBar, Chaine De Caracteres
                Sortie :
                        Rien
*/

void Header_Set_Sous_Title(HeaderBar *Bar_Ptr,char *Sous_Title)
{
    if(!Bar_Ptr)
    {
        printf("Erreur Dans Adress Header Bar Structure .");
        exit(0);
    }

    Bar_Ptr->SubTitle = g_strdup(Sous_Title);

    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(Bar_Ptr->HeadBar), Sous_Title);
}

/*
        Fonction Pour Affecter Un Icon Pour Le Head Bar

                Entre :
                        Pointeur Sur HeaderBar, Chaine De Caracteres
                Sortie :
                        Rien
*/

void Header_Set_Icon(HeaderBar *Bar_Ptr,const char *Icon)
{
    if(!Bar_Ptr)
    {
        printf("Erreur Dans Adress Header Bar.");
        exit(0);
    }

    if(Icon)
    {

        GtkWidget *Image = gtk_image_new_from_file(Icon);

        Bar_Ptr->Icon_Path = g_strdup(Icon);

        gtk_container_add(GTK_CONTAINER(Bar_Ptr->HeadBar),Image);
    }

}

/*
        Fonction Pour Affecter Les Buttons ( Close,Maximaz,Minimaz ) Pour Le Head Bar

                Entre :
                        Pointeur Sur HeaderBar, Bool Valeur
                Sortie :
                        Rien
*/

void Header_Set_Close_Button(HeaderBar *Bar_Ptr,gboolean Show_Button)
{
    if (!Bar_Ptr)
    {
        printf("Erreur Dans Adress Header Bar Sructure.");
        exit(0);
    }

    Bar_Ptr->Show_Close_Button = TRUE;

    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(Bar_Ptr->HeadBar), TRUE);
}

/*
        Fonction Pour Affecter Une Widget ( Souvent Des Buttons Menus ) Pour Le Head Bar A Gouche.

                Entre :
                        Pointeur Sur HeaderBar, Pointeur sur L'Objet Widget
                Sortie :
                        Rien
*/

void Header_Bar_Set_Custum_Gouche(HeaderBar *Ptr_Hd,GtkWidget *PtrWidget)
{
    if(!Ptr_Hd)
    {
        printf("\n Erruer Dans L\'Adressage.");
        exit(0);
    }

    Ptr_Hd->Custom_Gouche = PtrWidget;

    if (PtrWidget) gtk_header_bar_pack_start (GTK_HEADER_BAR(Ptr_Hd->HeadBar),PtrWidget);
}

/*
        Fonction Pour Affecter Une Widget ( Souvent Des Buttons Menus ) Pour Le Head Bar A Droite

                Entre :
                        Pointeur Sur HeaderBar, Pointeur sur L'Objet Widget
                Sortie :
                        Rien
*/

void Header_Bar_Set_Custum_Droit(HeaderBar *Ptr_Hd,GtkWidget *PtrWidget)
{
    if(!Ptr_Hd )
    {
        printf("\n Erruer Dans L\'Adressage.");
        exit(0);
    }

    Ptr_Hd->Custom_Droit = PtrWidget;

    if (PtrWidget)     gtk_header_bar_pack_end(GTK_HEADER_BAR(Ptr_Hd->HeadBar),PtrWidget);
}

/*
        Fonction Pour Affecter Une Decoration ( Organiser Les Button Dans L'Entete De Head Bar Pour Mieux Comprendre Voir 
                                                Fichier .h De Structure HeadBar ) Pour Le Head Bar

                Entre :
                        Pointeur Sur HeaderBar, Chaine De Caracteres
                Sortie :
                        Rien
*/

void HeadrBar_Set_Decoration_Lyout(HeaderBar *Ptr_Hd,const char *Decoration)
{
    if( !Ptr_Hd )
    {
        printf("\n Erruer Dans L\'Adressage.");
        exit(0);
    }

    if(Decoration)
    {
        Ptr_Hd->Decoration_Layout = g_strdup(Decoration);

        gtk_header_bar_set_decoration_layout(GTK_HEADER_BAR(Ptr_Hd->HeadBar),Decoration);
    }

}

/*
        Fonction Pour Affecter Touts Les Champs Precedents A Notre HeadBar Soit Par Defaut Soit Indique Par L'utilisateur

                Entre :
                        Touts Les Champs De Structure HeadBar
                Sortie :
                        Pointeur Sur HeadBar 
*/



HeaderBar *Init_Headr_Bar( char *Id )
{
    HeaderBar *Nw_Header = (HeaderBar *) malloc(sizeof(HeaderBar));

    if(!Nw_Header)
    {
        printf("Erreur Dans Allocation Memoire Pour SDD Header Bar.");
        exit(0);
    }

    Nw_Header->HeadBar = gtk_header_bar_new();

    if(!Nw_Header->HeadBar)
    {
        printf("Erreur D'Allocation Memoire Pour Le Head Bar Widget .");
        exit(0);
    }

    Nw_Header->Id = g_strdup(Id);
    
    Header_Set_Title(Nw_Header,Title_);

    Header_Set_Sous_Title(Nw_Header,SubTitle_);

    Header_Set_Close_Button(Nw_Header,Close_Button_);

    Header_Set_Icon(Nw_Header,Icon_Path_);

    HeadrBar_Set_Decoration_Lyout(Nw_Header,Decoration_Leyout_);

    Header_Bar_Set_Custum_Gouche(Nw_Header,Custum_Gouche_);

    Header_Bar_Set_Custum_Droit(Nw_Header,Custum_Droit_);

    return (HeaderBar *) Nw_Header;
}



