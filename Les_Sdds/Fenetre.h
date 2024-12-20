#include <gtk/gtk.h>
#include "Position.h"

                                                /*
                                                    Les Cnstants
                                                */
#define Title_ "Hello Gtk"
#define Icon_ NULL
#define Type_ 0
#define Resizable_ 0
#define ColorBg_ NULL
                                                /*
                                                    Les Position Par Defauts
                                                */
#define GTK_WIN_POS_NONE                
#define GTK_WIN_POS_CENTER              En_Centre_De_Ecran
#define GTK_WIN_POS_MOUSE               Cursor_En_Centre_De_Window
#define GTK_WIN_POS_CENTER_ALWAYS       Tjr_En_Centre
#define GTK_WIN_POS_CENTER_ON_PARENT    En_Centre_De_Son_Parent






typedef struct
{
    GtkWidget *Wind;                            // Pointeur Sur L'Objet Window 
    gchar *Title;                               // Title Of The Window
    gchar *Icon;                                // Icon Of The Window
    gboolean Type;                              // Type Of The Window ( TRUE for toplevel, FALSE for popup )
    gboolean Resizable;                         // If Window Resizable Or Not
    Taille Size;                                // Size Of The Window
    gchar *ColorBg;                             // Color Of BackGround
    Position Position;                          // Position Of The Window

    gint PositionParDf;                         // Position Par Defaut

                                                /*
                                                    GTK_WIN_POS_NONE: No automatic positioning.
                                                    GTK_WIN_POS_CENTER: Center the window on the screen.
                                                    GTK_WIN_POS_MOUSE: Position the window at the mouse cursor.
                                                    GTK_WIN_POS_CENTER_ALWAYS: Always center the window.
                                                    GTK_WIN_POS_CENTER_ON_PARENT: Center the window relative to its parent window.
                                                */

    gchar *Id;                                  // Unique identifier for the window
    gchar *BackGround;                          // Image De Back Ground (PATH)
    gfloat Transparant;

}Fenetre;
