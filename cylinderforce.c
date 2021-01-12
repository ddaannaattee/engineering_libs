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
#include "cylinderforce.h"

int cylGetPressure( s_widget * sp_widget )
{
	bool rb_is_pressure;
	rb_is_pressure = isThisRadioButtonActive( sp_widget->rb_cyl_pressure );

	if( rb_is_pressure == true ){
		//Do not try and get pressure values
		//Set desired output to calculate for pressure
		sp_widget->sp_cyl_data->desired_output = i_want_pressure;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_cyl_pressure );
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to pressure
		sp_widget->sp_cyl_data->pressure = getEntry( sp_widget->e_cyl_pressure );
	}

	//Save combo-box unit selection to pressure_units
	sp_widget->sp_cyl_data->pressure_units = getCBox( sp_widget->cbox_cyl_pressure );

	return 0;
}

int cylGetBore( s_widget * sp_widget )
{
	bool rb_is_bore;
	rb_is_bore = isThisRadioButtonActive( sp_widget->rb_cyl_bore );

	if( rb_is_bore == true ){
		//Do not try and get bore values
		//Set desired output to calculate for bore
		sp_widget->sp_cyl_data->desired_output = i_want_bore;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_cyl_bore );
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to bore
		sp_widget->sp_cyl_data->bore = getEntry( sp_widget->e_cyl_bore );
	}

	//Save combo-box unit selection to bore_units
	sp_widget->sp_cyl_data->bore_units = getCBox( sp_widget->cbox_cyl_bore );

	return 0;
}

int cylGetRod( s_widget * sp_widget )
{
	//Validate the entry length
	bool entry_is_valid;
	entry_is_valid = validateEntryLength( sp_widget->e_cyl_rod );
	if( entry_is_valid == false ){
		return 1;
	}

	//Convert entry text into a double and save to rod
	sp_widget->sp_cyl_data->rod = getEntry( sp_widget->e_cyl_rod );
	
	//Save combo-box unit selection to rod_units
	sp_widget->sp_cyl_data->rod_units = getCBox( sp_widget->cbox_cyl_rod );

	return 0;
}

int cylGetQty( s_widget * sp_widget )
{
	//Validate the entry length
	bool entry_is_valid;
	entry_is_valid = validateEntryLength( sp_widget->e_cyl_qty );
	if( entry_is_valid == false ){
		return 1;
	}

	//Convert entry text into a double and save to qty
	sp_widget->sp_cyl_data->qty = getEntry( sp_widget->e_cyl_qty );

	if( sp_widget->sp_cyl_data->qty < 0.0 ){
		return 1;
	}
	
	return 0;
}

int cylGetForce( s_widget * sp_widget )
{
	bool rb_is_force;
	rb_is_force = isThisRadioButtonActive( sp_widget->rb_cyl_force );

	if( rb_is_force == true ){
		//Do not try and get force values
		//Set desired output to calculate for force
		sp_widget->sp_cyl_data->desired_output = i_want_force;
	} else {
		//Validate the entry length
		bool entry_is_valid;
		entry_is_valid = validateEntryLength( sp_widget->e_cyl_force );
		if( entry_is_valid == false ){
			return 1;
		}

		//Convert entry text into a double and save to force
		sp_widget->sp_cyl_data->force = getEntry( sp_widget->e_cyl_force );
	}

	//Save combo-box unit selection to force_units
	sp_widget->sp_cyl_data->force_units = getCBox( sp_widget->cbox_cyl_force );

	return 0;
}

int cylGetAllInputs( s_widget * sp_widget )
{
	int val;

	val = cylGetPressure( sp_widget );
	if( val != 0 ){
		printf( "cylGetPressure error.\n" );
		return 1;
	}
	val = cylGetBore( sp_widget );
	if( val != 0 ){
		printf( "cylGetBore error.\n" );
		return 2;
	}
	val = cylGetRod( sp_widget );
	if( val != 0 ){
		printf( "cylGetRod error.\n" );
		return 3;
	}
	val = cylGetQty( sp_widget );
	if( val != 0 ){
		printf( "cylGetQty error.\n" );
		return 4;
	}
	val = cylGetForce( sp_widget );
	if( val != 0 ){
		printf( "cylGetForce error.\n" );
		return 5;
	}

	return 0;
}

void cylSetOutputs( GtkWidget * entry_box, double value )
{
	//Display in entry box
	char buff[50];
	char * p_buff = &buff[0];
	int i;
	i = snprintf( p_buff, 50, "%.3f", value );
	if( i > 0 ){ } //awesome, i used the variable 'i'
	gtk_entry_set_text( GTK_ENTRY( entry_box ), p_buff );
}

void cylDoItAll( s_widget * sp_widget )
{
	int err_val;
	err_val = cylGetAllInputs( sp_widget );
	
	switch ( sp_widget->sp_cyl_data->desired_output )
	{
		case i_want_force:
			//If results from cylGetAllInputs are good, or if the Force entry box has an error...
			//it's okay to proceed. If not, set the text to "-" and leave the switch.
			if( err_val != 0 && err_val != 5 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_force ), "-" );
				break;
			}
			//Convert Pressure value to MPa
			printf( "Pressure val (input): %f\n", sp_widget->sp_cyl_data->pressure );
			printf( "Type: %d\n", units_pressure );
			printf( "Input units: %d\n", sp_widget->sp_cyl_data->pressure_units );
			printf( "Output units: %d\n", MPa );
			err_val = convertUnits( units_pressure,
									sp_widget->sp_cyl_data->pressure_units,
									sp_widget->sp_cyl_data->pressure,
									MPa,
									&sp_widget->sp_cyl_data->output );
			sp_widget->sp_cyl_data->pressure = sp_widget->sp_cyl_data->output;
			
			printf( "Convert pressure err val: %d\n", err_val );
			printf( "Pressure val (MPa): %f\n", sp_widget->sp_cyl_data->pressure );
			
			//Convert bore value to mm
			err_val = convertUnits( units_linear,
									sp_widget->sp_cyl_data->bore_units,
									sp_widget->sp_cyl_data->bore,
									mm,
									&sp_widget->sp_cyl_data->bore );
			//printf( "Convert bore err val: %d\n", err_val );
			//printf( "Bore val (mm): %f\n", sp_widget->sp_cyl_data->bore );

			//Convert rod value to mm
			err_val = convertUnits( units_linear,
									sp_widget->sp_cyl_data->rod_units,
									sp_widget->sp_cyl_data->rod,
									mm,
									&sp_widget->sp_cyl_data->rod );
			//printf( "Convert rod err val: %d\n", err_val );
			//printf( "Rod val (mm): %f\n", sp_widget->sp_cyl_data->rod );

			//Calculate cylinder force

			cylForceCalc( sp_widget->sp_cyl_data->pressure,
						  sp_widget->sp_cyl_data->bore,
						  sp_widget->sp_cyl_data->rod,
						  sp_widget->sp_cyl_data->qty,
						  &sp_widget->sp_cyl_data->force);

			err_val = convertUnits( units_force,
									sp_widget->sp_cyl_data->force_units,
									sp_widget->sp_cyl_data->force,
									N,
									&sp_widget->sp_cyl_data->force );

			err_val = convertUnits( units_force,
									N,
									sp_widget->sp_cyl_data->force,
									sp_widget->sp_cyl_data->force_units,
									&sp_widget->sp_cyl_data->force );
			//If the bore diameter is less than the rod diameter...
			//set the text to "-" and leave the switch, because this is not sense.
			if( sp_widget->sp_cyl_data->bore < sp_widget->sp_cyl_data->rod ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_force ), "-" );
				break;
			}
			//If the value of Force is finite and a number, it's okay to set outputs...
			if( isfinite( sp_widget->sp_cyl_data->force ) ){
				cylSetOutputs( sp_widget->e_cyl_force, sp_widget->sp_cyl_data->force );
			} else { //Or else if it's not finite or it's not a number...
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_force ), "-" );
				break;
			}
			break;
		case i_want_bore:
			if( err_val != 0 && err_val != 2 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_bore ), "-" );
				break;
			}
			//Convert Pressure value to MPa
			err_val = convertUnits( units_pressure,
									sp_widget->sp_cyl_data->pressure_units,
									sp_widget->sp_cyl_data->pressure,
									MPa,
									&sp_widget->sp_cyl_data->pressure );

			//Convert rod value to mm
			err_val = convertUnits( units_linear,
									sp_widget->sp_cyl_data->rod_units,
									sp_widget->sp_cyl_data->rod,
									mm,
									&sp_widget->sp_cyl_data->rod );

			//Convert cylinder force to N
			err_val = convertUnits( units_force,
									sp_widget->sp_cyl_data->force_units,
									sp_widget->sp_cyl_data->force,
									N,
									&sp_widget->sp_cyl_data->force );

			//Calculate bore value in mm
			cylBoreCalc( sp_widget->sp_cyl_data->pressure,
						 sp_widget->sp_cyl_data->rod,
						 sp_widget->sp_cyl_data->qty,
						 sp_widget->sp_cyl_data->force,
						 &sp_widget->sp_cyl_data->bore );
			
			//Convert bore value to request bore units
			err_val = convertUnits(	units_linear,
									mm,
									sp_widget->sp_cyl_data->bore,
									sp_widget->sp_cyl_data->bore_units,
									&sp_widget->sp_cyl_data->bore );

			if( isfinite( sp_widget->sp_cyl_data->bore ) ){
				cylSetOutputs( sp_widget->e_cyl_bore, sp_widget->sp_cyl_data->bore );
			} else {
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_bore ), "-" );
				break;
			}
			break;
		case i_want_pressure:
			if( err_val != 0 && err_val != 1 ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_pressure ), "-" );
				break;
			}
			//Convert rod value to mm
			err_val = convertUnits( units_linear,
									sp_widget->sp_cyl_data->rod_units,
									sp_widget->sp_cyl_data->rod,
									mm,
									&sp_widget->sp_cyl_data->rod );

			//Convert cylinder force to N
			err_val = convertUnits( units_force,
									sp_widget->sp_cyl_data->force_units,
									sp_widget->sp_cyl_data->force,
									N,
									&sp_widget->sp_cyl_data->force );
			
			//Convert bore value to mm
			err_val = convertUnits( units_linear,
									sp_widget->sp_cyl_data->bore_units,
									sp_widget->sp_cyl_data->bore,
									mm,
									&sp_widget->sp_cyl_data->bore );

			//Calculate Pressure value in MPa
			cylPressureCalc( sp_widget->sp_cyl_data->bore,
							 sp_widget->sp_cyl_data->rod,
							 sp_widget->sp_cyl_data->qty,
							 sp_widget->sp_cyl_data->force,
							 &sp_widget->sp_cyl_data->pressure );

			//Convert pressure value to requested pressure units
			err_val = convertUnits( units_pressure,
									MPa,
									sp_widget->sp_cyl_data->pressure,
									sp_widget->sp_cyl_data->pressure_units,
									&sp_widget->sp_cyl_data->pressure );

			//If the bore diameter is less than the rod diameter...
			//set the text to "-" and leave the switch, because this is not sense.
			if( sp_widget->sp_cyl_data->bore <= sp_widget->sp_cyl_data->rod ){
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_pressure ), "-" );
				break;
			}
			if( isfinite( sp_widget->sp_cyl_data->pressure ) ){
				cylSetOutputs( sp_widget->e_cyl_pressure, sp_widget->sp_cyl_data->pressure );
			} else {
				gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_pressure ), "-" );
				break;
			}
			break;
		default:
			printf( "Default case in cylDoItAll function reached.\n" );
		break;
	}
}

//Function to connect the objects in the "Cylinder Force" tab to the application
void connectCylObj( s_widget * sp_widget, GtkBuilder * builder )
{
	//printf( "connectCylObj\n" );
	//Initialize data values so there aren't any problems in calculations
	sp_widget->sp_cyl_data->pressure = 0.0;
	sp_widget->sp_cyl_data->pressure_units = 0;
	sp_widget->sp_cyl_data->bore = 0.0;
	sp_widget->sp_cyl_data->bore_units = 0;
	sp_widget->sp_cyl_data->rod = 0.0;
	sp_widget->sp_cyl_data->rod_units = 0;
	sp_widget->sp_cyl_data->qty = 0.0;
	sp_widget->sp_cyl_data->force_units = 0;

	//Connect objects to their callback (function) signals
	sp_widget->e_cyl_pressure = GTK_WIDGET( gtk_builder_get_object( builder, "e_cyl_pressure" ) );
    sp_widget->e_cyl_bore = GTK_WIDGET( gtk_builder_get_object( builder, "e_cyl_bore" ) );
    sp_widget->e_cyl_rod = GTK_WIDGET( gtk_builder_get_object( builder, "e_cyl_rod" ) );
    sp_widget->e_cyl_qty = GTK_WIDGET( gtk_builder_get_object( builder, "e_cyl_qty" ) );
    sp_widget->e_cyl_force = GTK_WIDGET( gtk_builder_get_object( builder, "e_cyl_force" ) );

    sp_widget->cbox_cyl_pressure = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_cyl_pressure" ) );
    sp_widget->cbox_cyl_bore = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_cyl_bore" ) );
    sp_widget->cbox_cyl_rod = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_cyl_rod" ) );
	sp_widget->cbox_cyl_force = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_cyl_force" ) );

	sp_widget->rb_cyl_force = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_cyl_force" ) );
	sp_widget->rb_cyl_bore = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_cyl_bore" ) );
	sp_widget->rb_cyl_pressure = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_cyl_pressure" ) );
}

//If Any radio button is toggled...
void on_rb_cyl_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Pressure entry box is changed or 'enter' key is pressed...
void on_e_cyl_pressure_activate( GtkWidget * e_cyl_pressure, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}
void on_e_cyl_pressure_changed( GtkWidget * e_cyl_pressure, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Bore entry box is changed or 'enter' key is pressed...
void on_e_cyl_bore_activate( GtkWidget * e_cyl_bore, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}
void on_e_cyl_bore_changed( GtkWidget * e_cyl_bore, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Rod entry box is changed or 'enter' key is pressed...
void on_e_cyl_rod_activate( GtkWidget * e_cyl_rod, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}
void on_e_cyl_rod_changed( GtkWidget * e_cyl_rod, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Quantity entry box is changed or 'enter' key is pressed...
void on_e_cyl_qty_activate( GtkWidget * e_cyl_qty, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}
void on_e_cyl_qty_changed( GtkWidget * e_cyl_qty, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Force entry box is changed or 'enter' key is pressed...
void on_e_cyl_force_activate( GtkWidget * e_cyl_force, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}
void on_e_cyl_force_changed( GtkWidget * e_cyl_force, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Pressure combo box is changed...
void on_cbox_cyl_pressure_changed( GtkWidget * cbox_cyl_pressure, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Bore combo box is changed...
void on_cbox_cyl_bore_changed( GtkWidget * cbox_cyl_bore, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Rod combo box is changed...
void on_cbox_cyl_rod_changed( GtkWidget * cbox_cyl_rod, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}

//If Rod combo box is changed...
void on_cbox_cyl_force_changed( GtkWidget * cbox_cyl_force, s_widget * sp_widget )
{
	cylDoItAll( sp_widget );
}