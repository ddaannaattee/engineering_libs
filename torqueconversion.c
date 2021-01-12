#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <gtk/gtk.h>
#include "infostruct.h"
#include "../dl_lib/engineering.h"
#include "formfunctions.h"
#include "torqueconversion.h"

int torqueConvGetForce( s_widget * sp_widget )
{
	bool rb_is_force;
	rb_is_force = isThisRadioButtonActive( sp_widget->rb_torque_force );

	if( rb_is_force == true ){
		//Do not try and get force values
		//Set desired output to calculate for force
		sp_widget->sp_torque_conv_data->desired_output = i_want_force;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_torque_force);
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to force
		sp_widget->sp_torque_conv_data->input_force = getEntry( sp_widget->e_torque_force );
	}
	//Save combo-box unit selections to ..._force_units
	sp_widget->sp_torque_conv_data->input_force_units = getCBox( sp_widget->cbox_in_force_units );

	return 0;
}

int torqueConvGetDist( s_widget * sp_widget )
{
	bool rb_is_dist;
	rb_is_dist = isThisRadioButtonActive( sp_widget->rb_torque_dist );

	if( rb_is_dist == true ){
		//Do not try and get force values
		//Set desired output to calculate for force
		sp_widget->sp_torque_conv_data->desired_output = i_want_dist;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_torque_dist);
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to input distance
		sp_widget->sp_torque_conv_data->input_dist = getEntry( sp_widget->e_torque_dist );
	}

	//Save combo-box unit selections to ..._dist_units
	sp_widget->sp_torque_conv_data->input_dist_units = getCBox( sp_widget->cbox_in_dist_units );
	
	return 0;
}

int torqueConvGetTorque( s_widget * sp_widget )
{
	bool rb_is_torque;
	rb_is_torque = isThisRadioButtonActive( sp_widget->rb_torque_torque );

	if( rb_is_torque == true ){
		//Do not try and get force values
		//Set desired output to calculate for force
		sp_widget->sp_torque_conv_data->desired_output = i_want_torque;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_torque_torque);
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to pressure
		sp_widget->sp_torque_conv_data->output_torque = getEntry( sp_widget->e_torque_torque );
	}

	//Save combo-box unit selection to pressure_units
	sp_widget->sp_torque_conv_data->output_force_units = getCBox( sp_widget->cbox_out_force_units );
	sp_widget->sp_torque_conv_data->output_dist_units = getCBox( sp_widget->cbox_out_dist_units );

	return 0;
}

int torqueConvGetAllInputs( s_widget * sp_widget )
{
	int val;

	val = torqueConvGetForce( sp_widget );
	if( val != 0 ){
		//printf( "Torque check failed.\n" );
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_force ), "-" );
		return 1;
	}
	val = torqueConvGetDist( sp_widget );
	if( val != 0 ){
		//printf( "Distance check failed.\n" );
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_dist ), "-" );
		return 2;
	}
	val = torqueConvGetTorque( sp_widget );
	if( val != 0 ){
		//printf( "Torque check failed.\n" );
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_torque ), "-" );
		return 3;
	}

	return 0;
}

void torqueConvSetOutputs( GtkWidget * entry_box, double value )
{
	//Display in entry box
	char buff[50];
	char * p_buff = &buff[0];
	int i;
	i = snprintf( p_buff, 50, "%.3f", value );
	if( i > 0 ){ } //awesome, i used the variable 'i'
	gtk_entry_set_text( GTK_ENTRY( entry_box ), p_buff );
}

void torqueConvDoItAll( s_widget * sp_widget )
{
	int val;
	val = torqueConvGetAllInputs( sp_widget );

	switch ( sp_widget->sp_torque_conv_data->desired_output )
	{
		case i_want_force:
			//If results from torqueConvGetAllInputs are good, or if the Force entry box has an error...
			//it's okay to proceed. If not, set the text to "-" and leave the switch.
			if( val != 0 && val != 1 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_force ), "-" );
				break;
			}
			//Convert Distance value to mm
			val = convertUnits( units_linear,
								sp_widget->sp_torque_conv_data->input_dist_units,
								sp_widget->sp_torque_conv_data->input_dist,
								mm,
								&sp_widget->sp_torque_conv_data->input_dist );

			//Convert Torque value to N-mm?
			val = convertUnits( units_linear,
								sp_widget->sp_torque_conv_data->output_dist_units,
								sp_widget->sp_torque_conv_data->output_torque,
								mm,
								&sp_widget->sp_torque_conv_data->output_torque );
			val = convertUnits( units_force,
								sp_widget->sp_torque_conv_data->output_force_units,
								sp_widget->sp_torque_conv_data->output_torque,
								N,
								&sp_widget->sp_torque_conv_data->output_torque );

			//Calculate Force in N
			sp_widget->sp_torque_conv_data->input_force = 	sp_widget->sp_torque_conv_data->output_torque /
															sp_widget->sp_torque_conv_data->input_dist;

			//Convert Force to requested output units
			val = convertUnits( units_force,
								N,
								sp_widget->sp_torque_conv_data->input_force,
								sp_widget->sp_torque_conv_data->input_force_units,
								&sp_widget->sp_torque_conv_data->input_force );

			//If the value of Force is finite and a number, it's okay to set outputs...
			if( isfinite( sp_widget->sp_torque_conv_data->input_force ) ){
				torqueConvSetOutputs( sp_widget->e_torque_force, sp_widget->sp_torque_conv_data->input_force );
			} else { //Or else if it's not finite or it's not a number...
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_force ), "-" );
				break;
			}
			break;

		case i_want_dist:
			if( val != 0 && val != 2 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_dist ), "-" );
				break;
			}
			//Convert Force value to N
			val = convertUnits( units_force,
								sp_widget->sp_torque_conv_data->input_force_units,
								sp_widget->sp_torque_conv_data->input_force,
								N,
								&sp_widget->sp_torque_conv_data->input_force );

			//Convert Torque value to N-mm
			val = convertUnits( units_linear,
								sp_widget->sp_torque_conv_data->output_dist_units,
								sp_widget->sp_torque_conv_data->output_torque,
								mm,
								&sp_widget->sp_torque_conv_data->output_torque );
			val = convertUnits( units_force,
								sp_widget->sp_torque_conv_data->output_force_units,
								sp_widget->sp_torque_conv_data->output_torque,
								N,
								&sp_widget->sp_torque_conv_data->output_torque );

			//Calculate Distance value in mm
			sp_widget->sp_torque_conv_data->input_dist = 	sp_widget->sp_torque_conv_data->output_torque /
															sp_widget->sp_torque_conv_data->input_force;
			
			//Convert Distance to requested output units
			val = convertUnits( units_linear,
								mm,
								sp_widget->sp_torque_conv_data->input_dist,
								sp_widget->sp_torque_conv_data->input_dist_units,
								&sp_widget->sp_torque_conv_data->input_dist );

			if( isfinite( sp_widget->sp_torque_conv_data->input_dist ) ){
				torqueConvSetOutputs( sp_widget->e_torque_dist, sp_widget->sp_torque_conv_data->input_dist );
			} else {
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_dist ), "-" );
				break;
			}
			break;

		case i_want_torque:
			if( val != 0 && val != 3 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_torque ), "-" );
				break;
			}
			//Convert Force value to N
			val = convertUnits( units_force,
								sp_widget->sp_torque_conv_data->input_force_units,
								sp_widget->sp_torque_conv_data->input_force,
								N,
								&sp_widget->sp_torque_conv_data->input_force );

			//Convert Distance value to mm
			val = convertUnits( units_linear,
								sp_widget->sp_torque_conv_data->input_dist_units,
								sp_widget->sp_torque_conv_data->input_dist,
								mm,
								&sp_widget->sp_torque_conv_data->input_dist );
			
			//Calculate Torque value in N-mm
			sp_widget->sp_torque_conv_data->output_torque = sp_widget->sp_torque_conv_data->input_force *
															sp_widget->sp_torque_conv_data->input_dist;
			
			//Convert Torque to requested units
			val = convertUnits( units_linear,
								mm,
								sp_widget->sp_torque_conv_data->output_torque,
								sp_widget->sp_torque_conv_data->output_dist_units,
								&sp_widget->sp_torque_conv_data->output_torque );
			val = convertUnits( units_force,
								N,
								sp_widget->sp_torque_conv_data->output_torque,
								sp_widget->sp_torque_conv_data->output_force_units,
								&sp_widget->sp_torque_conv_data->output_torque );
			
			if( isfinite( sp_widget->sp_torque_conv_data->output_torque ) ){
				torqueConvSetOutputs( sp_widget->e_torque_torque, sp_widget->sp_torque_conv_data->output_torque );
			} else {
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_torque_torque ), "-" );
				break;
			}
			break;
		default:
			printf( "Default case in torqueConvDoItAll function reached.\n" );
		break;
	}
}

//Function to connect the objects in the "Torque Conversion" tab to the application
void connectTorqueConvObj( s_widget * sp_widget, GtkBuilder * builder )
{
	//Initialize data values so there aren't any problems in calculations
	sp_widget->sp_torque_conv_data->input_force = 0.0;
	sp_widget->sp_torque_conv_data->input_force_units = 0;
	sp_widget->sp_torque_conv_data->input_dist = 0.0;
	sp_widget->sp_torque_conv_data->input_dist_units = 0;
	sp_widget->sp_torque_conv_data->output_force_units = 0;
	sp_widget->sp_torque_conv_data->output_dist_units = 0;
	sp_widget->sp_torque_conv_data->output_torque = 0.0;

	//Connect objects to their callback (function) signals
	sp_widget->e_torque_force = GTK_WIDGET( gtk_builder_get_object( builder, "e_torque_force" ) );
    sp_widget->e_torque_dist = GTK_WIDGET( gtk_builder_get_object( builder, "e_torque_dist" ) );
	sp_widget->e_torque_torque = GTK_WIDGET( gtk_builder_get_object( builder, "e_torque_torque" ) );
    
    sp_widget->cbox_in_force_units = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_in_force_units" ) );
    sp_widget->cbox_in_dist_units = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_in_dist_units" ) );
    sp_widget->cbox_out_force_units = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_out_force_units" ) );
	sp_widget->cbox_out_dist_units = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_out_dist_units" ) );
    
    sp_widget->rb_torque_force = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_torque_force" ) );
	sp_widget->rb_torque_dist = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_torque_dist" ) );
	sp_widget->rb_torque_torque = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_torque_torque" ) );
}

//If Any radio button is toggled...
G_MODULE_EXPORT void on_rb_torque_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}

//If Force entry box is changed or 'enter' key is pressed...
G_MODULE_EXPORT void on_e_torque_force_activate( GtkWidget * e_torque_force, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
G_MODULE_EXPORT void on_e_torque_force_changed( GtkWidget * e_torque_force, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}

//If Distance entry box is changed or 'enter' key is pressed...
G_MODULE_EXPORT void on_e_torque_dist_activate( GtkWidget * e_torque_dist, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
G_MODULE_EXPORT void on_e_torque_dist_changed( GtkWidget * e_torque_dist, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}

//If Torque entry box is changed or 'enter' key is pressed...
G_MODULE_EXPORT void on_e_torque_torque_activate( GtkWidget * e_torque_torque, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
G_MODULE_EXPORT void on_e_torque_torque_changed( GtkWidget * e_torque_torque, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}

//If Inputs Force Units combo box is changed...
G_MODULE_EXPORT void on_cbox_in_force_units_changed( GtkWidget * cbox_in_force_units, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
//If Distance Units combo box is changed...
G_MODULE_EXPORT void on_cbox_in_dist_units_changed( GtkWidget * cbox_in_dist_units, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
//If Output Force Units combo box is changed...
G_MODULE_EXPORT void on_cbox_out_force_units_changed( GtkWidget * cbox_out_force_units, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}
//If Output Distance Units combo box is changed...
G_MODULE_EXPORT void on_cbox_out_dist_units_changed( GtkWidget * cbox_out_dist_units, s_widget * sp_widget )
{
	torqueConvDoItAll( sp_widget );
}