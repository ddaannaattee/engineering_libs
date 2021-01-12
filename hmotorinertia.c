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
#include "hmotorinertia.h"

//Function to get the velocity profile...
int hmsGetVelocityProfile( s_widget * sp_widget )
{
    printf( "hmsGetVelocityProfile\n" );
	if( isThisRadioButtonActive( sp_widget->rb_hms_sine ) )
    {
        printf( "Sine\n" );
		sp_widget->sp_hms_data->velocity_profile = sine;
	}
    else if( isThisRadioButtonActive( sp_widget->rb_hms_triangular ) )
    {
        printf( "Triangle\n" );
        sp_widget->sp_hms_data->velocity_profile = triangle;
	}
    else
    {
        printf( "No radio button selected?" );
        return 1;
    }

	return 0;
}

//Function to get the cycle time...
int hmsGetCycleTime( s_widget * sp_widget )
{
    printf( "hmsGetCycleTime\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_cycle_time);
    if( entry_is_valid == false )
    {
        return 10;
    }
    
    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->cycle_time = getEntry( sp_widget->e_hms_cycle_time );
    if( sp_widget->sp_hms_data->cycle_time <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->cycle_time_units = getCBox( sp_widget->cbox_hms_cycle_time );

	return 0;
}

//Function to get the # of servo moves...
int hmsGetServoMoves( s_widget * sp_widget )
{
    printf( "hmsGetServoMoves\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_servo_moves);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->servo_moves = getEntry( sp_widget->e_hms_servo_moves );
    if( sp_widget->sp_hms_data->servo_moves <= 0 )
    {
        return 20;
    }

	return 0;
}

//Function to get the load...
int hmsGetLoad( s_widget * sp_widget )
{
    printf( "hmsGetLoad\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_load);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->load = getEntry( sp_widget->e_hms_load );
    if( sp_widget->sp_hms_data->load <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->load_units = getCBox( sp_widget->cbox_hms_load );

	return 0;
}

//Function to get the carriage...
int hmsGetCarriage( s_widget * sp_widget )
{
    printf( "hmsGetCarriage\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_carriage);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->carriage = getEntry( sp_widget->e_hms_carriage );
    if( sp_widget->sp_hms_data->carriage <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->carriage_units = getCBox( sp_widget->cbox_hms_carriage );

	return 0;
}

//Function to get the pulley dimension...
int hmsGetPulleyDim( s_widget * sp_widget )
{
    printf( "hmsGetPulleyDim\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_pulley_dim);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to...
    sp_widget->sp_hms_data->pulley_dim = getEntry( sp_widget->e_hms_pulley_dim );
    if( sp_widget->sp_hms_data->pulley_dim <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...
	sp_widget->sp_hms_data->pulley_dim_units = getCBox( sp_widget->cbox_hms_pulley_dim );
    //Save combo-box unit selections to ...
	sp_widget->sp_hms_data->pulley_dim_type = getCBox( sp_widget->cbox_hms_pulley_dim_type );

	return 0;
}

//Function to get the pulley inertia...
int hmsGetPulleyInertia( s_widget * sp_widget )
{
    printf( "hmsGetPulleyInertia\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_pulley_inertia);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to...
    sp_widget->sp_hms_data->pulley_inertia = getEntry( sp_widget->e_hms_pulley_inertia );
    if( sp_widget->sp_hms_data->pulley_inertia <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...
	sp_widget->sp_hms_data->pulley_inertia_units = getCBox( sp_widget->cbox_hms_pulley_inertia );

	return 0;
}

//Function to get the # of servo moves...
int hmsGetReduction( s_widget * sp_widget )
{
    printf( "hmsGetReduction\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_reduction);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->reduction = getEntry( sp_widget->e_hms_reduction );
    if( sp_widget->sp_hms_data->reduction <= 0 )
    {
        return 20;
    }

	return 0;
}

//Function to get the travel distance...
int hmsGetTravelDistance( s_widget * sp_widget )
{
    printf( "hmsGetTravelDistance\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_total_dist);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->travel_dist = getEntry( sp_widget->e_hms_total_dist );
    if( sp_widget->sp_hms_data->travel_dist <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->travel_dist_units = getCBox( sp_widget->cbox_hms_travel_dist );

	return 0;
}

//Function to get the travel time...
int hmsGetTravelTime( s_widget * sp_widget )
{
    printf( "hmsGetTravelTime\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_travel_time);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->travel_time = getEntry( sp_widget->e_hms_travel_time );
    if( sp_widget->sp_hms_data->travel_time <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->travel_time_units = getCBox( sp_widget->cbox_hms_travel_time );

	return 0;
}

//Function to get the acceleration time...
int hmsGetAccelTime( s_widget * sp_widget )
{
    printf( "hmsGetAccelTime\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_accel_time);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->accel_time = getEntry( sp_widget->e_hms_accel_time );
    if( sp_widget->sp_hms_data->accel_time <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->accel_time_units = getCBox( sp_widget->cbox_hms_accel_time );

	return 0;
}

//Function to get the deceleration time...
int hmsGetDecelTime( s_widget * sp_widget )
{
    printf( "hmsGetDecelTime\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_decel_time);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->decel_time = getEntry( sp_widget->e_hms_decel_time );
    if( sp_widget->sp_hms_data->decel_time <= 0 )
    {
        return 20;
    }

	//Save combo-box unit selections to ...cycle chron_t
	sp_widget->sp_hms_data->decel_time_units = getCBox( sp_widget->cbox_hms_decel_time );

	return 0;
}

//Function to get losses...
int hmsGetLosses( s_widget * sp_widget )
{
    printf( "hmsGetLosses\n" );
    //Validate the entry length
    bool entry_is_valid;
    entry_is_valid = validateEntryLength( sp_widget->e_hms_losses);
    if( entry_is_valid == false )
    {
        return 10;
    }

    //Convert entry text into a double and save to cycle time
    sp_widget->sp_hms_data->losses = getEntry( sp_widget->e_hms_losses );
    if( sp_widget->sp_hms_data->losses <= 0 )
    {
        return 20;
    }

	return 0;
}

int hmsGetAllInputs( s_widget * sp_widget )
{
    printf( "hmsGetAllInputs\n" );
    hmsGetVelocityProfile( sp_widget );

	int val;

	val = hmsGetCycleTime( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_cycle_time ), "-" );
		val = 1;
	}
	val = hmsGetServoMoves( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_servo_moves ), "-" );
		val = 2;
	}
    val = hmsGetLoad( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_load ), "-" );
		val = 3;
	}
    val = hmsGetCarriage( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_carriage ), "-" );
		val = 4;
	}
    val = hmsGetPulleyDim( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_pulley_dim ), "-" );
		val = 5;
	}
    val = hmsGetPulleyInertia( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_pulley_inertia ), "-" );
		val = 6;
	}
    val = hmsGetReduction( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_reduction ), "-" );
		val = 7;
	}
    val = hmsGetTravelDistance( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_total_dist ), "-" );
		val = 8;
	}
    val = hmsGetTravelTime( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_travel_time ), "-" );
		val = 9;
	}
    val = hmsGetAccelTime( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_accel_time ), "-" );
		val = 10;
	}
    val = hmsGetDecelTime( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_decel_time ), "-" );
		val = 11;
	}
    val = hmsGetLosses( sp_widget );
    printf( "Val: %d\n", val );
	if( val != 0 )
    {
		gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_losses ), "-" );
		val = 12;
	}

	return val;
}

void hmsSetOutputs( s_widget * sp_widget )
{
    printf( "hmsSetOutputs\n" );
    setLabelOutput( sp_widget->l_hms_motor_torque,
                    sp_widget->sp_hms_data->motor_torque );
    setLabelOutput( sp_widget->l_hms_motor_speed,
                    sp_widget->sp_hms_data->motor_speed );
    setLabelOutput( sp_widget->l_hms_duty_cycle,
                    sp_widget->sp_hms_data->duty_cycle );
    setLabelOutput( sp_widget->l_hms_motor_inertia,
                    sp_widget->sp_hms_data->seen_inertia );
}

//Function to get all inputs and update all outputs whenever something is changed
void hmsDoItAll( s_widget * sp_widget )
{
    printf( "hmsDoItAll\n" );
    int val;
	val = hmsGetAllInputs( sp_widget );

    //Convert cycle time to sec
    val = convertUnits( units_time,
                        sp_widget->sp_hms_data->cycle_time_units,
                        sp_widget->sp_hms_data->cycle_time,
                        sec,
                        &sp_widget->sp_hms_data->cycle_time );

    //Convert Load to kg
    val = convertUnits( units_mass,
                        sp_widget->sp_hms_data->load_units,
                        sp_widget->sp_hms_data->load,
                        kgm,
                        &sp_widget->sp_hms_data->load );

    //Convert Carriage to kg
    val = convertUnits( units_mass,
                        sp_widget->sp_hms_data->carriage_units,
                        sp_widget->sp_hms_data->carriage,
                        kgm,
                        &sp_widget->sp_hms_data->carriage );

    //Convert Pulley Dimension to a radius in m
    val = convertUnits( units_linear,
                        sp_widget->sp_hms_data->pulley_dim_units,
                        sp_widget->sp_hms_data->pulley_dim,
                        m,
                        &sp_widget->sp_hms_data->pulley_dim );

    if( sp_widget->sp_hms_data->pulley_dim_type == diameter )
    {
        sp_widget->sp_hms_data->pulley_dim = sp_widget->sp_hms_data->pulley_dim / 2.0;
    }

    //Convert Pulley Inertia to kg-m2
    val = convertUnits( units_linear,
                        m,
                        sp_widget->sp_hms_data->pulley_inertia,
                        sp_widget->sp_hms_data->pulley_inertia_units,
                        &sp_widget->sp_hms_data->pulley_inertia );

    val = convertUnits( units_mass,
                        kgm,
                        sp_widget->sp_hms_data->pulley_inertia,
                        sp_widget->sp_hms_data->pulley_inertia_units,
                        &sp_widget->sp_hms_data->pulley_inertia );
 

    //Convert Total Travel Distance to m
    val = convertUnits( units_linear,
                        sp_widget->sp_hms_data->travel_dist_units,
                        sp_widget->sp_hms_data->travel_dist,
                        m,
                        &sp_widget->sp_hms_data->travel_dist );

    //Convert Total Travel Time to sec
    val = convertUnits( units_time,
                        sp_widget->sp_hms_data->travel_time_units,
                        sp_widget->sp_hms_data->travel_time,
                        sec,
                        &sp_widget->sp_hms_data->travel_time );

    //Convert Accel Time to sec
    val = convertUnits( units_time,
                        sp_widget->sp_hms_data->accel_time_units,
                        sp_widget->sp_hms_data->accel_time,
                        sec,
                        &sp_widget->sp_hms_data->accel_time );

    //Convert Decel Time to sec
    val = convertUnits( units_time,
                        sp_widget->sp_hms_data->decel_time_units,
                        sp_widget->sp_hms_data->decel_time,
                        sec,
                        &sp_widget->sp_hms_data->decel_time );

    ///////////////////////////
    //Calculate Duty Cycle ---> number of servo moves per cycle * travel time per move
    sp_widget->sp_hms_data->duty_cycle = sp_widget->sp_hms_data->cycle_time /
                                       ( sp_widget->sp_hms_data->travel_time *
                                         sp_widget->sp_hms_data->servo_moves );

    //Calculate Minimum Motor Torque required to move load + carriage
    sp_widget->sp_hms_data->max_force = ( 1 + sp_widget->sp_hms_data->losses / 100.0 ) * //Losses multiplier
                                        ( sp_widget->sp_hms_data->load + sp_widget->sp_hms_data->carriage ) * //mass
                                        sp_widget->sp_hms_data->accel_max; //acceleration

    sp_widget->sp_hms_data->max_torque =    sp_widget->sp_hms_data->max_force *
                                            sp_widget->sp_hms_data->pulley_dim;

    sp_widget->sp_hms_data->motor_torque =  sp_widget->sp_hms_data->max_torque /
                                            sp_widget->sp_hms_data->reduction;

    //Calculate Minimum Motor Speed in rad/s
    sp_widget->sp_hms_data->motor_speed =   sp_widget->sp_hms_data->v_max * 60.0 / sp_widget->sp_hms_data->pulley_dim;

    //Calculate System Inertia at Gearbox Input
    sp_widget->sp_hms_data->seen_inertia =  sp_widget->sp_hms_data->pulley_inertia + 
                                          ( sp_widget->sp_hms_data->load + sp_widget->sp_hms_data->carriage ) * 
                                            sp_widget->sp_hms_data->pulley_dim;

    //Convert Minimum Motor Torque to requested output units
    val = convertUnits( units_force,
                        N,
                        sp_widget->sp_hms_data->motor_torque,
                        sp_widget->sp_hms_data->motor_force_units,
                        &sp_widget->sp_hms_data->motor_torque );

    val = convertUnits( units_linear,
                        m,
                        sp_widget->sp_hms_data->motor_torque,
                        sp_widget->sp_hms_data->motor_dist_units,
                        &sp_widget->sp_hms_data->motor_torque );

    //Convert Minimum Motor Speed to requested output units
    val = convertUnits( units_angle,
                        rad,
                        sp_widget->sp_hms_data->motor_speed,
                        sp_widget->sp_hms_data->motor_pos_units,
                        &sp_widget->sp_hms_data->motor_speed );

    val = convertUnits( units_time,
                        sec,
                        sp_widget->sp_hms_data->motor_speed,
                        sp_widget->sp_hms_data->motor_time_units,
                        &sp_widget->sp_hms_data->motor_speed );

    //If the value of _____ is finite and a number, it's okay to set outputs...
    hmsSetOutputs( sp_widget );
    if( isfinite( sp_widget->sp_hms_data->duty_cycle ) )
    {
    }
    else
    { //Or else if it's not finite or it's not a number...
        gtk_label_set_text( GTK_LABEL( sp_widget->l_hms_duty_cycle ), "-" );
    }

    if( isfinite( sp_widget->sp_hms_data->seen_inertia ) )
    {
    }
    else
    { //Or else if it's not finite or it's not a number...
        gtk_label_set_text( GTK_LABEL( sp_widget->l_hms_motor_inertia ), "-" );
    }

    if( isfinite( sp_widget->sp_hms_data->motor_torque ) )
    {
    }
    else
    { //Or else if it's not finite or it's not a number...
        gtk_label_set_text( GTK_LABEL( sp_widget->l_hms_motor_torque ), "-" );
    }

    if( isfinite( sp_widget->sp_hms_data->motor_speed ) )
    {
    }
    else
    { //Or else if it's not finite or it's not a number...
        gtk_label_set_text( GTK_LABEL( sp_widget->l_hms_motor_speed ), "-" );
    }
    

}

//Function to connect the objects in the "Cylinder Force" tab to the application
void connectHMSObj( s_widget * sp_widget, GtkBuilder * builder )
{
    printf( "connectHMSObj\n" );
    //Initialize data values so there aren't any problems in calculations?
	//sp_widget->sp_hms_data->... = 0.0;

	//Connect objects to their callback (function) signals
	sp_widget->e_hms_cycle_time = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_cycle_time" ) );
    sp_widget->e_hms_servo_moves = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_servo_moves" ) );
    sp_widget->e_hms_load = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_load" ) );
    sp_widget->e_hms_carriage = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_carriage" ) );
    sp_widget->e_hms_pulley_dim = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_pulley_dim" ) );
    sp_widget->e_hms_pulley_inertia = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_pulley_inertia" ) );
    sp_widget->e_hms_reduction = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_reduction" ) );
    sp_widget->e_hms_total_dist = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_total_dist" ) );
    sp_widget->e_hms_travel_time = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_travel_time" ) );
    sp_widget->e_hms_accel_time = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_accel_time" ) );
    sp_widget->e_hms_decel_time = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_decel_time" ) );
    sp_widget->e_hms_losses = GTK_WIDGET( gtk_builder_get_object( builder, "e_hms_losses" ) );

    sp_widget->cbox_hms_cycle_time = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_cycle_time" ) );
    sp_widget->cbox_hms_load = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_load" ) );
    sp_widget->cbox_hms_carriage = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_carriage" ) );
    sp_widget->cbox_hms_pulley_dim = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_pulley_dim" ) );
    sp_widget->cbox_hms_pulley_inertia = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_pulley_inertia" ) );
    sp_widget->cbox_hms_travel_dist = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_travel_dist" ) );
    sp_widget->cbox_hms_travel_time = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_travel_time" ) );
    sp_widget->cbox_hms_accel_time = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_accel_time" ) );
    sp_widget->cbox_hms_decel_time = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_decel_time" ) );
    sp_widget->cbox_hms_motor_force = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_motor_force" ) );
    sp_widget->cbox_hms_motor_dist = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_motor_dist" ) );
    sp_widget->cbox_hms_motor_pos = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_motor_pos" ) );
    sp_widget->cbox_hms_motor_time = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_motor_time" ) );
    sp_widget->cbox_hms_motor_side_inertia = GTK_WIDGET( gtk_builder_get_object( builder, "cbox_hms_motor_side_inertia" ) );

	sp_widget->rb_hms_triangular = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_hms_triangular" ) );
	sp_widget->rb_hms_sine = GTK_RADIO_BUTTON( gtk_builder_get_object( builder, "rb_hms_sine" ) );

    sp_widget->l_hms_motor_torque = GTK_WIDGET( gtk_builder_get_object( builder, "l_hms_motor_torque" ) );
    sp_widget->l_hms_motor_speed = GTK_WIDGET( gtk_builder_get_object( builder, "l_hms_motor_speed" ) );
    sp_widget->l_hms_duty_cycle = GTK_WIDGET( gtk_builder_get_object( builder, "l_hms_duty_cycle" ) );
    sp_widget->l_hms_motor_inertia = GTK_WIDGET( gtk_builder_get_object( builder, "l_hms_motor_inertia" ) );
}

//If Radio button is toggled
void on_rb_hms_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Cycle Time entry box is changed or 'enter' key is pressed...
void on_e_hms_cycle_time_activate( GtkWidget * e_hms_cycle_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_cycle_time_changed( GtkWidget * e_hms_cycle_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If #-of-Servo-Moves entry box is changed or 'enter' key is pressed...
void on_e_hms_servo_moves_activate( GtkWidget * e_hms_servo_moves, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_servo_moves_changed( GtkWidget * e_hms_servo_moves, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Load entry box is changed or 'enter' key is pressed...
void on_e_hms_load_activate( GtkWidget * e_hms_load, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_load_changed( GtkWidget * e_hms_load, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Carriage entry box is changed or 'enter' key is pressed...
void on_e_hms_carriage_activate( GtkWidget * e_hms_carriage, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_carriage_changed( GtkWidget * e_hms_carriage, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Pulley Dim entry box is changed or 'enter' key is pressed...
void on_e_hms_pulley_dim_activate( GtkWidget * e_hms_pulley_dim, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_pulley_dim_changed( GtkWidget * e_hms_pulley_dim, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Pulley Inertia entry box is changed or 'enter' key is pressed...
void on_e_hms_pulley_inertia_activate( GtkWidget * e_hms_pulley_inertia, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_pulley_inertia_changed( GtkWidget * e_hms_pulley_inertia, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Gear Reduction entry box is changed or 'enter' key is pressed...
void on_e_hms_reduction_activate( GtkWidget * e_hms_reduction, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_reduction_changed( GtkWidget * e_hms_reduction, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Total Distance entry box is changed or 'enter' key is pressed...
void on_e_hms_total_dist_activate( GtkWidget * e_hms_total_dist, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_total_dist_changed( GtkWidget * e_hms_total_dist, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Total Travel Time entry box is changed or 'enter' key is pressed...
void on_e_hms_travel_time_activate( GtkWidget * e_hms_travel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_travel_time_changed( GtkWidget * e_hms_travel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Acceleration Time entry box is changed or 'enter' key is pressed...
void on_e_hms_accel_time_activate( GtkWidget * e_hms_accel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_accel_time_changed( GtkWidget * e_hms_accel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Deceleration Time entry box is changed or 'enter' key is pressed...
void on_e_hms_decel_time_activate( GtkWidget * e_hms_decel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_decel_time_changed( GtkWidget * e_hms_decel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Losses entry box is changed or 'enter' key is pressed...
void on_e_hms_losses_activate( GtkWidget * e_hms_losses, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
void on_e_hms_losses_changed( GtkWidget * e_hms_losses, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}

//If Cycle Time combo box is changed...
void on_cbox_hms_cycle_time_changed( GtkWidget * cbox_hms_cycle_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Load combo box is changed...
void on_cbox_hms_load_changed( GtkWidget * cbox_hms_load, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Carriage combo box is changed...
void on_cbox_hms_carriage_changed( GtkWidget * cbox_hms_carriage, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Pulley Dim combo box is changed...
void on_cbox_hms_pulley_dim_changed( GtkWidget * cbox_hms_pulley_dim, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Pulley Measure combo box is changed...
void on_cbox_hms_pulley_dim_type_changed( GtkWidget * cbox_hms_pulley_dim_type, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Pulley Inertia combo box is changed...
void on_cbox_hms_pulley_inertia_changed( GtkWidget * cbox_hms_pulley_inertia, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Total Distance combo box is changed...
void on_cbox_hms_travel_dist_changed( GtkWidget * cbox_hms_travel_dist, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Total Travel Time combo box is changed...
void on_cbox_hms_travel_time_changed( GtkWidget * cbox_hms_travel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Acceleration Time combo box is changed...
void on_cbox_hms_accel_time_changed( GtkWidget * cbox_hms_accel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Deceleration Time combo box is changed...
void on_cbox_hms_decel_time_changed( GtkWidget * cbox_hms_decel_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Motor Force combo box is changed...
void on_cbox_hms_motor_force_changed( GtkWidget * cbox_hms_motor_force, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Motor Distance (torque arm) combo box is changed...
void on_cbox_hms_motor_dist_changed( GtkWidget * cbox_hms_motor_dist, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Motor (Angular) Position combo box is changed...
void on_cbox_hms_motor_pos_changed( GtkWidget * cbox_hms_motor_pos, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Motor (Angular Displacement) Time combo box is changed...
void on_cbox_hms_motor_time_changed( GtkWidget * cbox_hms_motor_time, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}
//If Motor-Side Inertia combo box is changed...
void on_cbox_hms_motor_side_inertia_changed( GtkWidget * cbox_hms_motor_side_inertia, s_widget * sp_widget )
{
    hmsDoItAll( sp_widget );
}