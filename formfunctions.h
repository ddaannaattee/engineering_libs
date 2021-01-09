//This header file contains functions used by all tabs to interact with the objects contained within
#include <gtk/gtk.h>
#include <stdbool.h>

#ifndef DL_FORMFUNCTIONS_H_
#define DL_FORMFUNCTIONS_H_

//This function takes a radio button and returns "true" if it is active, and "false" if not
bool isThisRadioButtonActive( GtkRadioButton * radiobtn );

//This function takes an entry box and returns "true" if the length of the contents is >= 0...
//and "false" if less than zero.
bool validateEntryLength( GtkWidget * entry_box );

//This function takes an entry box and returns the double-type value contained within...
//It uses atof(), and returns values as interpreted by that function.
double getEntry( GtkWidget * entry_box );

//This function takes a combo box and returns the index of the selected list item...
int getCBox( GtkWidget * combo_box );

//This function takes a label and a value and outputs it to a label...
void setLabelOutput( GtkWidget * label, double value );

//This function takes an entry box and a value and outputs it to a label...
void setEntryOutput( GtkWidget * entry_box, double value );

#endif