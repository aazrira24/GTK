#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\Fenetre.h"

                                                /*
                                                    Structure De ComboBox
                                                */


#define Entry_ 0
#define IndiceActive_ 0                             /*   C a d Le Premier Option   */
#define NbrOfElmentsDansComboBox_ 0


typedef struct Op
{                                                     /* 
                                                          A Realiser **
                                                      */
    char *Title_Option[Max];
    short int PositionDansComboBox;
    struct Op *Svt;
}Option;





typedef struct 
{
    GtkWidget *ComboBx; 
    gchar *Id;                              
    gboolean Entry;
    gint IndiceActive;
    Position Position_ComboBox;
    gint NbrOfElmentsDansComboBox;

} ComboBox;
