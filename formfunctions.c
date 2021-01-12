#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "formfunctions.h"

//This function takes a radio button and returns "true" if it is active, and "false" if not
bool isThisRadioButtonActive( GtkRadioButton * radiobtn )
{
	bool eval = gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON( radiobtn ) );
	return eval;
}

//This function takes an entry box and returns "true" if the length of the contents is >= 0...
//and "false" if less than zero.
bool validateEntryLength( GtkWidget * entry_box )
{
	int temp_len;
	temp_len = gtk_entry_get_text_length( GTK_ENTRY( entry_box ) );
	if( temp_len < 0 ){
		printf( "Entry length is less than zero.\n" );
		return false;
	}
	return true;
}

//This function takes an entry box and returns the double-type value contained within...
//It uses atof(), and returns values as interpreted by that function.
double getEntry( GtkWidget * entry_box )
{
	//Make better input filter

	
	const char * temp;
	double value;
	temp = gtk_entry_get_text( GTK_ENTRY( entry_box ) );
	value = atof( temp );
	return value;
}

//This function takes a combo box and returns the index of the selected list item...
//The combo boxes are essentially used to select units, thus the variable name.
int getCBox( GtkWidget * combo_box )
{
	int units;
	units = gtk_combo_box_get_active( GTK_COMBO_BOX( combo_box ) );
	if( units < 0 ){
		printf( "No active combo box selected.\n" );
		return 1;
	}
	return units;
}

//This function takes a label and a value and outputs it to a label...
void setLabelOutput( GtkWidget * label, double value )
{
	//Redo this function


	//Display in label
	char buff[50];
	char * p_buff = &buff[0];
	int i;
	i = snprintf( p_buff, 50, "%.3f", value );
	if( i > 0 ){ } //awesome, i used the variable 'i'
	gtk_label_set_text( GTK_LABEL( label ), p_buff );
}

//This function takes an entry box and a value and outputs it to a label...
void setEntryOutput( GtkWidget * entry_box, double value )
{
	//Redo this function


	//Display in entry box
	char buff[50];
	char * p_buff = &buff[0];
	int i;
	i = snprintf( p_buff, 50, "%.3f", value );
	if( i > 0 ){ } //awesome, i used the variable 'i'
	gtk_entry_set_text( GTK_ENTRY( entry_box ), p_buff );
}