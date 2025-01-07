#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Sdds\Calendrier.h"




/*
    Structure of Buttons
*/


#define _Mnemonic 1
#define _Always_Show_Image 0
#define _Mnemonic_Car ' '
#define _Label  NULL
#define _Image NULL
#define _Color NULL


typedef struct 
{
    GtkWidget *Ptr_Button;
    char *Id;
    bool Mnemonic;
    bool Always_Show_Image;
    Position Position_;
    char Mnemonic_Car;
    char *Label;
    char *Image;
    char *Color;
    Taille Size;
}Button;
