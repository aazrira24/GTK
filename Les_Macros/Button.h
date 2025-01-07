#include "C:\Users\LENOVO\Desktop\GTK\GTK\Les Macros\Calendrier.h"


void Gtk_Button_New_Objet(Button *Ptr,bool Mnemonic)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_New_Objet | Erreur D\'Adressage");
        exit(0);
    }
    if(Mnemonic)    Ptr->Ptr_Button = gtk_button_new_with_mnemonic(NULL);
    else Ptr->Ptr_Button = gtk_button_new();
}

void Gtk_Button_Always_Show_Image_Or_Not(Button *Ptr,bool Always_Show_Image)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_Always_Show_Image_Or_Not | Erreur D\'Adressage");
        exit(0);
    }

    gtk_button_set_always_show_image(GTK_BUTTON(Ptr->Ptr_Button),Always_Show_Image);
}

char Gtk_Button_Mnemonic_Get_Charactere(Button *Ptr)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_Mnemonic_Get_Charactere | Erreur D\'Adressage");
        exit(0);
    }
    int Cntr = 0 ;
    char MneMo ;
    if(!Ptr->Label)
    {
        while (Ptr->Label[Cntr] != '\0')
        {
            if(Ptr->Label[Cntr]=='_') break;
            Cntr += 1;
        }
        if(Ptr->Label[Cntr] == '\0')
        {
            printf("\n Macro : Gtk_Button_Mnemonic_Get_Charactere | Erruer De Trouver Le Carectere");
            exit(0);
        }
    
        Ptr->Mnemonic_Car = Ptr->Label[Cntr+1];
    }
    return (char ) (Ptr->Mnemonic_Car);
} 

void Gtk_Button_Set_Label(Button *Ptr, char *Lable)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_Set_Label | erreur D\'Adressage.");
        exit(0);
    }
    gtk_button_set_label(GTK_BUTTON(Ptr->Ptr_Button),Lable);
    Ptr->Label = (char *) Alloue(Max);
    int Cntr = 0;
    for ( ; Cntr < Max ; Ptr->Label[Cntr] = Lable[Cntr++]);
}

GdkPixbuf *Gtk_Resize_Picture(char *Image_Path,int X,int Y)
{
    GdkPixbuf *Image = gdk_pixbuf_new_from_file_at_scale(Image_Path, X, Y, TRUE, NULL);
    if(!Image)
    {
        printf("\n Macro : Gtk_Resize_Picture | Erreur D\'Allocation.");
        exit(0);
    }
    return (GdkPixbuf *) Image;
}

void Gtk_Button_Set_Image(Button *Ptr, char *Path_Image,int X,int Y)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_Set_Image | erreur D\'Adressage.");
        exit(0);
    }

    Ptr->Image = Path_Image;

    GdkPixbuf *Ptr_ = Gtk_Resize_Picture(Path_Image,X,Y);

    GtkWidget *Image = gtk_image_new_from_pixbuf(Ptr_);

    gtk_button_set_image(GTK_BUTTON(Ptr->Ptr_Button),Image);
}


void Gtk_Button_Set_Color(Button *Ptr,char *Color)
{
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_Set_Color | Erreur D\'Adressage.");
        exit(0);
    }

    GdkRGBA Color_;
    gdk_rgba_parse(&Color_, Color); 
    // Parse the color string into a GdkRGBA structure

    // Apply the background color to all states of the button
    gtk_widget_override_background_color(Ptr->Ptr_Button, GTK_STATE_FLAG_NORMAL, &Color_);

    // Normal state
    gtk_button_set_relief(GTK_BUTTON(Ptr->Ptr_Button), GTK_RELIEF_NONE);
}




Button *Gtk_Button_New(char *Id)
{
    Button *Ptr = (Button *) Alloue(Button);
    if(!Ptr)
    {
        printf("\n Macro : Gtk_Button_New | Erreur D\'Adressage.");
        exit(0);
    }

    Gtk_Button_New_Objet(Ptr,_Mnemonic);

    Gtk_Button_Always_Show_Image_Or_Not(Ptr,_Always_Show_Image);
    if(_Label)
                Gtk_Button_Set_Label(Ptr,_Label);

    if(_Mnemonic)
                Gtk_Button_Mnemonic_Get_Charactere(Ptr);

    if(_Image)
                Gtk_Button_Set_Image(Ptr,_Image,30,30);
    if(_Color)
                Gtk_Button_Set_Color(Ptr,_Color);
    
    return (Button *) Ptr;
}






