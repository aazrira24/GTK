#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\Fenetre.h"

                                            
/*
    La Fonction Fenetre_Set_BackGround_Image Pour Ajoute Un Image Comme BackGround D'une Window
    Les Entres : 
                    Pointeur De Type Fenetre, Chaine De Caracteres 
    Les Sorties :
                    Rien
*/
void Fenetre_Set_BackGround_Image(Fenetre *F_Ptr,gchar *BackGroundPath)                
{
    /*
        Test D'Exsitance
    */
    if (!F_Ptr)
    {
        printf("Erreur Dans L'Adress Fenetre. ");
        exit(0);
    }

    /*
        Test D'Exsitance
    */
    if(!F_Ptr->Wind)
    {
        printf("Erruer Dans L'Adress Wind.");
        exit(0);
    }

    /*
        Création D'un Conteneur GtkOverlay Joue Le Role Comme Box Ou Fixed Pour Encapsule L'image
    */
    GtkWidget *overlay = gtk_overlay_new();
    /*
        Affecter Notre Overlay Cree A Notre Fenetre Pass En Parametres 
    */
    gtk_container_add(GTK_CONTAINER(F_Ptr->Wind), overlay);

    F_Ptr->BackGround = BackGroundPath;

    /* 
        Chargement L'image A Traiter
    */
    GtkWidget *Image = gtk_image_new_from_file(F_Ptr->BackGround);

    /*
        Ajout de l'image au conteneur GtkOverlay
    */
    gtk_overlay_add_overlay(GTK_OVERLAY(overlay),Image);

}

/*
    La Fonction Fenetre_Set_BackGround_Color Pour Ajoute Une Color Comme BackGround D'une Window
    Les Entres : 
                    Pointeur De Type Fenetre, Chaine De Caracteres 
    Les Sorties :
                    Rien
*/

void Fenetre_Set_BackGround_Color(Fenetre *F_Ptr,char *ColorBg)                
{
    /*
        Test D'Exsitance
    */
    if (!F_Ptr)
    {
        printf("Erreur Dans L'Adress Fenetre. ");
        exit(0);
    }
    /*
        Test D'Exsitance
    */
    if(!F_Ptr->Wind)
    {
        printf("Erruer Dans L'Adress Wind.");
        exit(0);
    }   

    /*
        Initailiser Un Objet De Type Color  
    */

    GdkColor Color;
    /*
        Affecter Le Color A Notre Objet Initailiser 
    */
    gdk_color_parse(ColorBg, &Color); 

    /*
        Affecter Le Color Au Window
    */

    gtk_widget_modify_bg(F_Ptr->Wind, GTK_STATE_NORMAL, &Color);

    F_Ptr->ColorBg = ColorBg;

}

/*
    La Fonction cree_fenetre Pour Creation Dynamique D'une Fenetre.
    Les Entres : 
                    Rien 
    Les Sorties :
                    Pointeur De Type Fenetre
*/

Fenetre* cree_fenetre()
{
    Fenetre* Fentr = (Fenetre*) malloc(sizeof(Fenetre));

    if(!Fentr)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    /*
        Peux Avoir Les Valeurs Par Defauts Ici.
    */
    // fen->wind=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    return ( Fenetre* )Fentr;
}

/*
    La Fonction set_window_type Pour Donnes Une Type  Fenetre Soit TOPLEVEL ( Avec Les Buttons Close.. ), Soit POPUP ( Sans Les Buttons )
    Les Entres : 
                    Rien 
    Les Sorties :
                    Pointeur De Type Fenetre
*/

void set_window_type(Fenetre* fen,gboolean type)
{
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    if(type)    ( fen->Wind = gtk_window_new(GTK_WINDOW_TOPLEVEL) );

    else        ( fen->Wind = gtk_window_new(GTK_WINDOW_POPUP) ); 

    fen->Type=type;

}

/*
    Les Fonction Pour Affecter Et Recuperer La Position Et La Taille 
*/ 

void definir_taille(Fenetre *f, gint largeur, gint hauteur) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    f->Size.X = largeur;
    f->Size.Y = hauteur;

    gtk_window_set_default_size(GTK_WINDOW(f->Wind), largeur, hauteur);

}

void recuperer_taille(Fenetre *f, gint *largeur, gint *hauteur) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    *largeur = f->Size.X;
    *hauteur = f->Size.Y;
}

void definir_position(Fenetre *f, gint x, gint y) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    f->Position.X = x;
    f->Position.Y = y;
    gtk_window_move(GTK_WINDOW(f->Wind), x, y);
}

Position recuperer_position(Fenetre *f) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    Position pos;

    gtk_window_get_position(GTK_WINDOW(f->Wind), &pos.X, &pos.Y);
    
    return ( Position ) pos;
}

/*
    Fonction Si La Fenetre Est Resizable ( Redimensionnable ) Ou Non
*/

void definir_redimensionnable(Fenetre *f, gboolean resizable) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    f->Resizable = resizable;

    gtk_window_set_resizable(GTK_WINDOW(f->Wind), resizable);

}



void definir_position_par_def(Fenetre *f, gint position) 
{
    if(!f)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }

    f->PositionParDf = position;

    switch (position) 
    {
        case 0:
            gtk_window_set_position(GTK_WINDOW(f->Wind), GTK_WIN_POS_NONE);
            break;
        case 1:
            gtk_window_set_position(GTK_WINDOW(f->Wind), GTK_WIN_POS_CENTER);
            break;
        case 2:
            gtk_window_set_position(GTK_WINDOW(f->Wind), GTK_WIN_POS_MOUSE);
            break;
        case 3:
            gtk_window_set_position(GTK_WINDOW(f->Wind), GTK_WIN_POS_CENTER_ALWAYS);
            break;
        case 4:
            gtk_window_set_position(GTK_WINDOW(f->Wind), GTK_WIN_POS_CENTER_ON_PARENT);
            break;
        default:
            printf("\n Erreur Position N\'est Pas Indique.");
            break;
    }
}

/*
    Fonction Pour Iniatliser Le Programe 
*/

void Program_Begin(int Arv,char *Arg[])
{
    gtk_init(&Arv,&Arg);
}

/* 
    Show All Widgets
*/

void Show_Programm(Fenetre *F_Ptr)
{
    gtk_widget_show_all(F_Ptr->Wind);
}

void Main_Boucle()
{
    gtk_main();
}

void on_button_quit_clicked(GtkWidget *widget, gpointer data) 
{
    /*
        Quitter le programme
    */
    gtk_main_quit();
}
/*
void Gtk_Signal_Connect(GtkWidget *,gchar *Signale,gchar *Fnct,)
{
    g_signal_connect(Ptr->Wind, "destroy", G_CALLBACK(gtk_main_quit), NULL);
}

*/

