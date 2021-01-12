#include <gtk/gtk.h>

#ifndef DL_INFOSTRUCT_H_
#define DL_INFOSTRUCT_H_

//Structure Declarations
typedef struct cyl_force {
	int desired_output;
	double pressure;
	int pressure_units;
	double bore;
	int bore_units;
	double rod;
	int rod_units;
	double qty;
	double force;
	int force_units;
	double output;
} s_cyl_data;

typedef struct torque_conv {
	int desired_output;
	double input_force;
	int input_force_units;
	double input_dist;
	int input_dist_units;
	int output_force_units;
	int output_dist_units;
	double output_torque;
} s_torque_conv_data;

typedef struct hms {
	int velocity_profile;
	double cycle_time;
	int cycle_time_units;
	
	double servo_moves;
	
	double load;
	int load_units;
	double carriage;
	int carriage_units;

	double pulley_dim;
	int pulley_dim_units;
	int pulley_dim_type;
	double pulley_inertia;
	int pulley_inertia_units;

	double reduction;

	double travel_dist;
	int travel_dist_units;
	double travel_time;
	int travel_time_units;
	double accel_time;
	int accel_time_units;
	double decel_time;
	int decel_time_units;

	double accel_max; // m/s^2
	double v_max; // m/s

	double losses;

	double max_force;
	double max_torque;
	double motor_force;
	int motor_force_units;
	double motor_dist;
	int motor_dist_units;
	double motor_torque;

	int motor_pos_units;
	int motor_time_units;
	double motor_speed;

	double duty_cycle;

	double seen_inertia;
	int seen_inertia_units;

} s_hms_data;

typedef struct {
	//Radio buttons: rb_
	//Entry boxes: e_
	//Combo boxes: cbox_
	//Labels: l_

	//Cylinder Force Widgets
	GtkRadioButton * rb_cyl_force;
	GtkRadioButton * rb_cyl_bore;
	GtkRadioButton * rb_cyl_pressure;
	GtkWidget * e_cyl_pressure;
	GtkWidget * e_cyl_bore;
	GtkWidget * e_cyl_rod;
	GtkWidget * e_cyl_qty;
	GtkWidget * e_cyl_force;
	GtkWidget * cbox_cyl_pressure;
	GtkWidget * cbox_cyl_bore;
	GtkWidget * cbox_cyl_rod;
	GtkWidget * cbox_cyl_force;
	
	//Torque Converter Widgets
	GtkRadioButton * rb_torque_force;
	GtkRadioButton * rb_torque_dist;
	GtkRadioButton * rb_torque_torque;
	GtkWidget * e_torque_force;
    GtkWidget * e_torque_dist;
	GtkWidget * e_torque_torque;
    GtkWidget * cbox_in_force_units;
    GtkWidget * cbox_in_dist_units;
    GtkWidget * cbox_out_force_units;
	GtkWidget * cbox_out_dist_units;

	//Horizontal Motor Drive Sizing Widgets
	GtkRadioButton * rb_hms_triangular;
	GtkRadioButton * rb_hms_sine;
	GtkWidget * e_hms_cycle_time;
	GtkWidget * e_hms_servo_moves;
	GtkWidget * e_hms_load;
	GtkWidget * e_hms_carriage;
	GtkWidget * e_hms_pulley_dim;
	GtkWidget * e_hms_pulley_inertia;
	GtkWidget * e_hms_reduction;
	GtkWidget * e_hms_total_dist;
	GtkWidget * e_hms_travel_time;
	GtkWidget * e_hms_accel_time;
	GtkWidget * e_hms_decel_time;
	GtkWidget * e_hms_losses;
	GtkWidget * cbox_hms_cycle_time;
	GtkWidget * cbox_hms_load;
	GtkWidget * cbox_hms_carriage;
	GtkWidget * cbox_hms_pulley_dim;
	GtkWidget * cbox_hms_pulley_dim_type;
	GtkWidget * cbox_hms_pulley_inertia;
	GtkWidget * cbox_hms_travel_dist;
	GtkWidget * cbox_hms_travel_time;
	GtkWidget * cbox_hms_accel_time;
	GtkWidget * cbox_hms_decel_time;
	GtkWidget * cbox_hms_motor_force;
	GtkWidget * cbox_hms_motor_dist;
	GtkWidget * cbox_hms_motor_pos;
	GtkWidget * cbox_hms_motor_time;
	GtkWidget * cbox_hms_motor_side_inertia;
	GtkWidget * l_hms_motor_torque;
	GtkWidget * l_hms_motor_speed;
	GtkWidget * l_hms_duty_cycle;
	GtkWidget * l_hms_motor_inertia;

	//Data structures for each set of widgets
	s_cyl_data * sp_cyl_data;
	s_torque_conv_data * sp_torque_conv_data;
	s_hms_data * sp_hms_data;
} s_widget;

#endif