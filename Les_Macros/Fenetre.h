#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Macros\HeadBar.h"

                                            
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
void Fenetre_Definir_Taille(Fenetre *f, gint x, gint y) 
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
Taille Fenetre_Recuperer_Taille(Fenetre *f) 
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


/*
    La Fonction Definir_Redimensionnable pour définir si une fenêtre peut être redimensionnée ou non.
    Les Entrées :
                    Pointeur de type Fenetre, valeur booléenne (TRUE ou FALSE).
    Les Sorties :
                    Rien.
*/

void Fenetre_Definir_Redimensionnable(Fenetre *f, gboolean resizable) 
{
     if(!f)
    {
    printf("la fentre n'exsite pas");
    exit(-1);
    }
    f->Resizable = resizable;
    gtk_window_set_resizable(GTK_WINDOW(f->Wind), resizable); // donner ala fenetre cette propriétés
}



/*
    La Fonction Definir_Position pour positionner la fenêtre aux coordonnées données.
    Les Entrées :
                    Pointeur de type Fenetre, coordonnées x et y.
    Les Sorties :
                    Rien.
*/
void Fenetre_Definir_Position(Fenetre *f, gint x, gint y) 
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
Position Fenetre_Recuperer_Position(Fenetre *f) 
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

void Fenetre_Definir_Position_Connu(Fenetre *f, gint position) 
{
    if(!f)
       {
        printf("la fentre n'exsite pas");
        exit(-1);
       }
    switch (position) 
    {
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
            printf("\n Erreur Dans Position Par Defaut.\n");
            break;
    }

    f->PositionParDf = position;
}

/*
    La Fonction mettre_en_plein_ecran pour mettre la fenêtre en plein écran.
    Les Entrées :
                    Pointeur de type Fenetre.
    Les Sorties :
                    Rien.
*/

void Fenetre_Mettre_En_Plein_Ecran(Fenetre *f) 
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
void Fenetre_Quitter_Plein_Ecran(Fenetre *f) 
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


void Fenetre_Set_Type(Fenetre* Fenetre,GtkWindowType Type = Normal)
{
    if(!Fenetre)   exit(-1);
    if(!Fenetre->Wind)
    {
        printf("Erruer Dans La Fenetre");
        exit(-1);
    }
    
    if( Type == Normal )    (   Fenetre->Wind=gtk_window_new(Type)  );

    else        (   Fenetre->Wind=gtk_window_new(Type) );

    Fenetre->Type = Type;
}


void Fenetre_Set_Decorate(Fenetre *fen,gboolean Headbar)
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
    // Applique la decoration en fonction du parametre decorate
    gtk_window_set_decorated(GTK_WINDOW(fen->Wind), Headbar);

    fen->Headbar = Headbar;
}

void Fenetre_Set_Icon(Fenetre *fen, const gchar *new_icon,gboolean is_theme)
{
   
    if (!fen || !new_icon) 
    {
        printf("set_fenetre_icon: Paramètres invalides.");
        exit(-1);
    }

    // Applique la nouvelle icône en fonction du type (thématique ou fichier)

    if (is_theme)   // Définit l'icône thématique pour la fenêtre   
                    gtk_window_set_icon_name(GTK_WINDOW(fen->Wind), new_icon);
    else
    {
        // Charge l'image depuis le fichier indiqué dans Icon
    	GError *error = NULL;
    	GdkPixbuf *icon = gdk_pixbuf_new_from_file(new_icon, &error);
    	if (!icon) 
        {
        	printf("Erreur lors du chargement de l'icône (%s) : %s",new_icon,error->message);
        	g_error_free(error);
        	exit(-1);
    	}

        // Définit l'icône de la fenêtre
        gtk_window_set_icon(GTK_WINDOW(fen->Wind), icon);

        // Libère la mémoire associée à l'objet GdkPixbuf
        g_object_unref(icon);
    
    }
    
    fen->Icon_Type = is_theme;

    fen->Icon = g_strdup(new_icon);
}

void Fenetre_Set_Title(Fenetre *fen, const gchar *new_title)
{
    // Vérifie si le pointeur vers la structure Fenetre est NULL
    if (!fen || !new_title)
    {
        // Affiche un message d'avertissement dans la console si la structure est invalide
        printf("update_fenetre_title: Paramètres invalides.");
        exit(-1);  // quitte immédiatement car il n'y a rien à modifier
    }

    // Met à jour le titre affiché dans la fenêtre GTK

    gtk_window_set_title(GTK_WINDOW(fen->Wind), new_title); 
    
    fen->Title = g_strdup(new_title);

}


Fenetre *New_Fenetre(
                    gchar *Id
                    ,GtkWindowType  Type = Normal
                    ,const gchar *Title = Title_
                    ,const gchar *Icon = Icon_ 
                    ,gboolean Icon_Type = Icon_Type_
                    ,gint PositionParDefaut = Pos_Centre
                    ,gchar *ColorBg = ColorBg_
                    ,gchar *BackGround = BackGround_
                    ,gboolean Resizable = Resizable_
                    ,gboolean Headbar = HeadBar_ 
                    ) 
{
    Fenetre *New_Wind = Cree_Fenetre();

    if(!New_Wind)
    {
        printf("Erreur D\'allocation Memoire Pour La Structure Fenetre.");
        exit(0);
    }

    New_Wind->Wind =  gtk_window_new(Type);

    if(!New_Wind->Wind)
    {
        printf("Erreur D\'allocation Memoire Pour Window .");
        exit(0);
    }

    Fenetre_Set_Title(New_Wind,Title);

    Fenetre_Set_Icon(New_Wind,Icon,Icon_Type);

    Fenetre_Set_Type(New_Wind,Type);

    Fenetre_Definir_Redimensionnable(New_Wind,Resizable);

    Fenetre_Set_BackGround_Color(New_Wind,ColorBg);

    Fenetre_Definir_Position_Connu(New_Wind,PositionParDefaut);

    Fenetre_Set_BackGround_Image(New_Wind,BackGround);

    Fenetre_Set_Decorate(New_Wind,Headbar);

    gtk_window_set_default_size(GTK_WINDOW(New_Wind->Wind),1000,1000);

    return (Fenetre *) New_Wind;

}





