#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\HeaderBar.h"

                                                /*
                                                    Les Cnstants
                                                */
#define Icon_ NULL
                                                /*
                                                    Les Types De Windows:
                                                    TOPLEVEL = NORMAL
                                                    POPUP = NOT_NORMAL
                                                */

#define Normal GTK_WINDOW_TOPLEVEL 
#define Not_Normal GTK_WINDOW_POPUP

#define Resizable_ 0
#define ColorBg_ NULL
#define BackGround_ NULL
                                                /*
                                                    Les Position Par Defauts
                                                */

#define Aucune_Pos              GTK_WIN_POS_NONE
#define Pos_Centre              GTK_WIN_POS_CENTER
#define Pos_du_curseur          GTK_WIN_POS_MOUSE
#define Pos_Tjrs_centrer        GTK_WIN_POS_CENTER_ALWAYS
#define Pos_Centrer_parent      GTK_WIN_POS_CENTER_ON_PARENT    

#define HeadBar_                false   
#define Icon_Type_              true


typedef struct
{
    GtkWidget *Wind;                            // Pointeur Sur L'Objet Window 
    gchar *Title;                               // Title Of The Window
    gchar *Icon;                                // Icon Of The Window
    gboolean Icon_Type;                         // Icon De Theme ( Predefinie Sur GTK ) Ou D'une Image Avec Sa Propre Path
    GtkWindowType Type;                         // Type Of The Window ( Normal = TopLevel, Not_Normal = Popup )
    gboolean Resizable;                         // If Window Resizable Or Not
    Taille Size;                                // Size Of The Window
    gchar *ColorBg;                             // Color Of BackGround
    Position Position;                          // Position Of The Window

    gint PositionParDf;                         // Position Par Defaut

                                                /*
                                                    0. GTK_WIN_POS_NONE: No automatic positioning.
                                                    1. GTK_WIN_POS_CENTER: Center the window on the screen.
                                                    2. GTK_WIN_POS_MOUSE: Position the window at the mouse cursor.
                                                    3. GTK_WIN_POS_CENTER_ALWAYS: Always center the window.
                                                    4. GTK_WIN_POS_CENTER_ON_PARENT: Center the window relative to its parent window.
                                                */

    gchar *Id;                                  // Unique identifier for the window
    gchar *BackGround;                          // Image De Back Ground (PATH)
    gboolean Headbar;

}Fenetre;
