#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\Onglets.h"

                                                /*
                                                    Structure De Donnes Head Bar
                                                */

#define Title_ "Hello World"
#define SubTitle_ "Hello World"
#define Close_Button_ FALSE
#define Icon_Path_ NULL
#define Custum_Gouche_ NULL
#define Decoration_Leyout_ NULL
                                                /*
                                                    Pour Decoration Leyout :

                                                        1. Controls Only on the Left

                                                            "menu:" - Menu button on the left, nothing on the right.
                                                            "_:" - Minimize button on the left.
                                                            "^:" - Maximize button on the left.
                                                            "x:" - Close button on the left.
                                                            "menu,_:" - Menu and minimize buttons on the left.
                                                            "menu,^:" - Menu and maximize buttons on the left.
                                                            "menu,x:" - Menu and close buttons on the left.
                                                            "_^:" - Minimize and maximize buttons on the left.
                                                            "_x:" - Minimize and close buttons on the left.
                                                            "menu,_^x:" - Menu, minimize, maximize, and close buttons on the left.

                                                        2. Controls Only on the Right
                                                            ":menu" - Menu button on the right, nothing on the left.
                                                            ":_" - Minimize button on the right.
                                                            ":^" - Maximize button on the right.
                                                            ":x" - Close button on the right.
                                                            ":menu,_" - Menu and minimize buttons on the right.
                                                            ":menu,^" - Menu and maximize buttons on the right.
                                                            ":menu,x" - Menu and close buttons on the right.
                                                            ":_^" - Minimize and maximize buttons on the right.
                                                            ":_x" - Minimize and close buttons on the right.
                                                            ":menu,_^x" - Menu, minimize, maximize, and close buttons on the right.

                                                        3. Controls on Both Sides
                                                            "menu:x" - Menu button on the left, close button on the right.
                                                            "_:x" - Minimize button on the left, close button on the right.
                                                            "^:x" - Maximize button on the left, close button on the right.
                                                            "menu,_:^" - Menu and minimize buttons on the left, maximize button on the right.
                                                            "menu,^:_x" - Menu and maximize buttons on the left, minimize and close buttons on the right.
                                                            "menu,_^:x" - Menu, minimize, and maximize buttons on the left, close button on the right.
                                                            "_^:menu,x" - Minimize and maximize buttons on the left, menu and close buttons on the right.
                                                            "menu,_^x:_^x" - Menu, minimize, maximize, and close buttons on both sides. 

                                                */
    
#define Custum_Droit_ NULL
#define Custum_Gouche_ NULL


typedef struct 
{
    GtkWidget *HeadBar;                     // Widget principal de la barre d'en-tête
    gchar *Id;
    gchar *Title;                           // Titre principal
    gchar *SubTitle;                        // Sous-titre
    gboolean Show_Close_Button;             // Indique si le bouton de fermeture est affiché
    gchar *Icon_Path;                       // Nom de l'icône
    gchar *Decoration_Layout;               // Mise en page des décorations
    GtkWidget *Custom_Gouche;               // Widget personnalisé au début (gauche)
    GtkWidget *Custom_Droit;                // Widget personnalisé à la fin (droite)

} HeaderBar;
