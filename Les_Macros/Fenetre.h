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
    La Fonction Definir_Taille Pour donner une taille a la fentre
    Les Entres : 
                    Pointeur De Type Fenetre, cordonnee x , cordonne y 
    Les Sorties :
                    Rien
*/
void Definir_Taille(Fenetre *f, gint x, gint y) 
{
    f->Size.X = x;
    f->Size.Y = y;
    gtk_window_set_default_size(GTK_WINDOW(f->Wind), x, y);//donner a la fentre une taille de x et y
}

/*
    La Fonction Recuperer_Taille pour récupérer la taille actuelle de la fenêtre.
    Les Entrées : 
                    Pointeur de type Fenetre
    Les Sorties :
                    Largeur et hauteur via une variable Taille .
*/
Taille Recuperer_Taille(Fenetre *f) 
{
   Taille T;
    if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }
    T.X = f->Size.X;
    T.Y = f->Size.Y;
}

/********rezizable*******/
/*
    La Fonction Definir_Redimensionnable pour définir si une fenêtre peut être redimensionnée ou non.
    Les Entrées :
                    Pointeur de type Fenetre, valeur booléenne (TRUE ou FALSE).
    Les Sorties :
                    Rien.
*/
void Definir_Redimensionnable(Fenetre *f, gboolean resizable) 
{
     if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }
    f->Resizable = resizable;
    gtk_window_set_resizable(GTK_WINDOW(f->Wind), resizable); // donner ala fenetre cette propriétés
}


/******pos*********/
/*
    La Fonction Definir_Position pour positionner la fenêtre aux coordonnées données.
    Les Entrées :
                    Pointeur de type Fenetre, coordonnées x et y.
    Les Sorties :
                    Rien.
*/
void Definir_Position(Fenetre *f, gint x, gint y) 
{
     if(!f)
      {
      printf("la fentre n'exsite pas");
      exit(-1);
      }
    f->Position.X = x;
    f->Position.Y = y;
    gtk_window_move(GTK_WINDOW(f->Wind), x, y);
}

/*
    La Fonction Recuperer_Position pour récupérer la position actuelle de la fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Une structure Position contenant les coordonnées x et y.
*/
Position Recuperer_Position(Fenetre *f) 
{
     Position pos;
     if(!f)
       {
         printf("la fentre n'exsite pas");
         exit(-1);
       }
    gtk_window_get_position(GTK_WINDOW(f->Wind), &pos.X, &pos.Y);
    return pos;
}

/*
    La Fonction Definir_Position_Connu pour définir la position connue d'une fenêtre.
    Les Entrées :
                    Pointeur de type Fenetre, valeur entière correspondant à la position.
    Les Sorties :
                    Rien.
*/
void Definir_Position_Connu(Fenetre *f, gint position) 
{
    if(!f)
       {
        printf("la fentre n'exsite pas");
        exit(-1);
       }
    switch (position) {
        case 0:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Aucune_Pos);
            break;
        case 1:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centre);
            break;
        case 2:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_du_curseur);
            break;
        case 3:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Tjrs_centrer);
            break;
        case 4:
            gtk_window_set_position(GTK_WINDOW(f->Wind), Pos_Centrer_parent);
            break;
        default:
            // Gestion de l'erreur ou position par défaut si nécessaire
            break;
    }
}

/*
    La Fonction mettre_en_plein_ecran pour mettre la fenêtre en plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void Mettre_En_Plein_Ecran(Fenetre *f) 
{
    if(!f)
      {
       printf("la fentre n'exsite pas");
       exit(-1);
      }
    gtk_window_fullscreen(GTK_WINDOW(f->Wind));
}

/*
    La Fonction quitter_plein_ecran pour quitter le mode plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/
void Quitter_Plein_Ecran(Fenetre *f) 
{
    if(!f)
     {
      printf("la fentre n'exsite pas");
      exit(-1);
     }
    gtk_window_unfullscreen(GTK_WINDOW(f->Wind));
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

void Quit_Main(GtkWidget *widget, gpointer data) 
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

Fenetre* Cree_Fenetre()
{
    Fenetre* fen=(Fenetre*)malloc(sizeof(Fenetre));
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    return (Fenetre*)fen;
}


void Afficher_Fenetre(Fenetre* fen)
{
    if(!fen)
    {
        printf("Erreur dans la fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    gtk_widget_show_all(fen->Wind);
}




void Set_Window_Type(Fenetre* fen,gboolean type)
{
    if(!fen)   exit(-1);
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    if(type)    (fen->Wind=gtk_window_new(GTK_WINDOW_TOPLEVEL));
    else        (fen->Wind=gtk_window_new(GTK_WINDOW_POPUP));
    fen->Type=type;
}


void Set_Window_Decorate(Fenetre *fen,gboolean Headbar)
{
    if(!fen)
    {
        printf("Erreur dans l'adresse fenetre");
        exit(-1);
    }
    if(!fen->Wind)
    {
        printf("Erruer dans la fenetre");
        exit(-1);
    }
    // Applique la d�coration en fonction du param�tre decorate
    gtk_window_set_decorated(GTK_WINDOW(fen->Wind), Headbar);
    fen->Headbar = Headbar;
}


