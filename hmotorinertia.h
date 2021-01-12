//This header file contains the functions used in the Horizontal Motor Sizing Tab
#include "infostruct.h"
#include <gtk/gtk.h>

#ifndef DL_HMOTORINERTIA_H_
#define DL_HMOTORINERTIA_H_

#define triangle 0
#define sine 1

//Function to get the velocity profile...
int hmsGetVelocityProfile( s_widget * sp_widget );

//Function to get the cycle time...
int hmsGetCycleTime( s_widget * sp_widget );

//Function to get the # of servo moves...
int hmsGetServoMoves( s_widget * sp_widget );

//Function to get the load...
int hmsGetLoad( s_widget * sp_widget );

//Function to get the carriage...
int hmsGetCarriage( s_widget * sp_widget );

//Function to get the pulley dimension...
int hmsGetPulleyDim( s_widget * sp_widget );

//Function to get the pulley inertia...
int hmsGetPulleyInertia( s_widget * sp_widget );

//Function to get the # of servo moves...
int hmsGetReduction( s_widget * sp_widget );

//Function to get the travel distance...
int hmsGetTravelDistance( s_widget * sp_widget );

//Function to get the travel time...
int hmsGetTravelTime( s_widget * sp_widget );

//Function to get the acceleration time...
int hmsGetAccelTime( s_widget * sp_widget );

//Function to get the deceleration time...
int hmsGetDecelTime( s_widget * sp_widget );

//Function to get losses...
int hmsGetLosses( s_widget * sp_widget );

int hmsGetAllInputs( s_widget * sp_widget );

void hmsSetOutputs( s_widget * sp_widget );

//Function to get all inputs and update all outputs whenever something is changed
void hmsDoItAll( s_widget * sp_widget );

//Function to connect the objects in the "Cylinder Force" tab to the application
void connectHMSObj( s_widget * sp_widget, GtkBuilder * builder );

//If Radio button is toggled
void on_rb_hms_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget );

//If Cycle Time entry box is changed or 'enter' key is pressed...
void on_e_hms_cycle_time_activate( GtkWidget * e_hms_cycle_time, s_widget * sp_widget );
void on_e_hms_cycle_time_changed( GtkWidget * e_hms_cycle_time, s_widget * sp_widget );

//If #-of-Servo-Moves entry box is changed or 'enter' key is pressed...
void on_e_hms_servo_moves_activate( GtkWidget * e_hms_servo_moves, s_widget * sp_widget );
void on_e_hms_servo_moves_changed( GtkWidget * e_hms_servo_moves, s_widget * sp_widget );

//If Load entry box is changed or 'enter' key is pressed...
void on_e_hms_load_activate( GtkWidget * e_hms_load, s_widget * sp_widget );
void on_e_hms_load_changed( GtkWidget * e_hms_load, s_widget * sp_widget );

//If Carriage entry box is changed or 'enter' key is pressed...
void on_e_hms_carriage_activate( GtkWidget * e_hms_carriage, s_widget * sp_widget );
void on_e_hms_carriage_changed( GtkWidget * e_hms_carriage, s_widget * sp_widget );

//If Pulley Dim entry box is changed or 'enter' key is pressed...
void on_e_hms_pulley_dim_activate( GtkWidget * e_hms_pulley_dim, s_widget * sp_widget );
void on_e_hms_pulley_dim_changed( GtkWidget * e_hms_pulley_dim, s_widget * sp_widget );

//If Pulley Inertia entry box is changed or 'enter' key is pressed...
void on_e_hms_pulley_inertia_activate( GtkWidget * e_hms_pulley_inertia, s_widget * sp_widget );
void on_e_hms_pulley_inertia_changed( GtkWidget * e_hms_pulley_inertia, s_widget * sp_widget );

//If Gear Reduction entry box is changed or 'enter' key is pressed...
void on_e_hms_reduction_activate( GtkWidget * e_hms_reduction, s_widget * sp_widget );
void on_e_hms_reduction_changed( GtkWidget * e_hms_reduction, s_widget * sp_widget );

//If Total Distance entry box is changed or 'enter' key is pressed...
void on_e_hms_total_dist_activate( GtkWidget * e_hms_total_dist, s_widget * sp_widget );
void on_e_hms_total_dist_changed( GtkWidget * e_hms_total_dist, s_widget * sp_widget );

//If Total Travel Time entry box is changed or 'enter' key is pressed...
void on_e_hms_travel_time_activate( GtkWidget * e_hms_travel_time, s_widget * sp_widget );
void on_e_hms_travel_time_changed( GtkWidget * e_hms_travel_time, s_widget * sp_widget );

//If Acceleration Time entry box is changed or 'enter' key is pressed...
void on_e_hms_accel_time_activate( GtkWidget * e_hms_accel_time, s_widget * sp_widget );
void on_e_hms_accel_time_changed( GtkWidget * e_hms_accel_time, s_widget * sp_widget );

//If Deceleration Time entry box is changed or 'enter' key is pressed...
void on_e_hms_decel_time_activate( GtkWidget * e_hms_decel_time, s_widget * sp_widget );
void on_e_hms_decel_time_changed( GtkWidget * e_hms_decel_time, s_widget * sp_widget );

//If Losses entry box is changed or 'enter' key is pressed...
void on_e_hms_losses_activate( GtkWidget * e_hms_losses, s_widget * sp_widget );
void on_e_hms_losses_changed( GtkWidget * e_hms_losses, s_widget * sp_widget );

//If Cycle Time combo box is changed...
void on_cbox_hms_cycle_time_changed( GtkWidget * cbox_hms_cycle_time, s_widget * sp_widget );
//If Load combo box is changed...
void on_cbox_hms_load_changed( GtkWidget * cbox_hms_load, s_widget * sp_widget );
//If Carriage combo box is changed...
void on_cbox_hms_carriage_changed( GtkWidget * cbox_hms_carriage, s_widget * sp_widget );
//If Pulley Dim combo box is changed...
void on_cbox_hms_pulley_dim_changed( GtkWidget * cbox_hms_pulley_dim, s_widget * sp_widget );
//If Pulley Measure combo box is changed...
void on_cbox_hms_pulley_dim_type_changed( GtkWidget * on_cbox_hms_pulley_dim_type, s_widget * sp_widget );
//If Pulley Inertia combo box is changed...
void on_cbox_hms_pulley_inertia_changed( GtkWidget * cbox_hms_pulley_inertia, s_widget * sp_widget );
//If Total Distance combo box is changed...
void on_cbox_hms_travel_dist_changed( GtkWidget * cbox_hms_travel_dist, s_widget * sp_widget );
//If Total Travel Time combo box is changed...
void on_cbox_hms_travel_time_changed( GtkWidget * cbox_hms_travel_time, s_widget * sp_widget );
//If Acceleration Time combo box is changed...
void on_cbox_hms_accel_time_changed( GtkWidget * cbox_hms_accel_time, s_widget * sp_widget );
//If Deceleration Time combo box is changed...
void on_cbox_hms_decel_time_changed( GtkWidget * cbox_hms_decel_time, s_widget * sp_widget );
//If Motor Force combo box is changed...
void on_cbox_hms_motor_force_changed( GtkWidget * cbox_hms_motor_force, s_widget * sp_widget );
//If Motor Distance (torque arm) combo box is changed...
void on_cbox_hms_motor_dist_changed( GtkWidget * cbox_hms_motor_dist, s_widget * sp_widget );
//If Motor (Angular) Position combo box is changed...
void on_cbox_hms_motor_pos_changed( GtkWidget * cbox_hms_motor_pos, s_widget * sp_widget );
//If Motor (Angular Displacement) Time combo box is changed...
void on_cbox_hms_motor_time_changed( GtkWidget * cbox_hms_motor_time, s_widget * sp_widget );
//If Motor-Side Inertia combo box is changed...
void on_cbox_hms_motor_side_inertia_changed( GtkWidget * cbox_hms_motor_side_inertia, s_widget * sp_widget );

#endif