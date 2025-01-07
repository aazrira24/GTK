#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\Fenetre.h"

                                                /*
                                                    Structure De ComboBox
                                                */


#define _Entry 0
#define _IndiceActive 0                             /*   C a d Le Premier Option   */
#define _NbrOfElmentsDansComboBox 0


typedef struct Op
{
    char *Title_Option;                             /*   Le Max Des Caracters Est Max = 25   */
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
