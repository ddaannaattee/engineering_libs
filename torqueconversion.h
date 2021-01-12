#include "infostruct.h"

#ifndef DL_TORQUECONVERSION_H_
#define DL_TORQUECONVERSION_H_

void connectTorqueConvObj( s_widget * sp_widget, GtkBuilder * builder );

int torqueConvGetForce( s_widget * sp_widget );

int torqueConvGetDist( s_widget * sp_widget );

int torqueConvGetAllInputs( s_widget * sp_widget );

void torqueConvSetOutputs( GtkWidget * entry_box, double value );

void torqueConvDoItAll( s_widget * sp_widget );

//If Any radio button is toggled...
void on_rb_torque_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget );

//If Force entry box is changed or 'enter' key is pressed...
void on_e_torque_force_activate( GtkWidget * e_torque_force, s_widget * sp_widget );

void on_e_torque_force_changed( GtkWidget * e_torque_force, s_widget * sp_widget );

//If Distance entry box is changed or 'enter' key is pressed...
void on_e_torque_dist_activate( GtkWidget * e_torque_dist, s_widget * sp_widget );

void on_e_torque_dist_changed( GtkWidget * e_torque_dist, s_widget * sp_widget );

//If Torque entry box is changed or 'enter' key is pressed...
void on_e_torque_torque_activate( GtkWidget * e_torque_torque, s_widget * sp_widget );

void on_e_torque_torque_changed( GtkWidget * e_torque_torque, s_widget * sp_widget );

//If Inputs Force Units combo box is changed...
void on_cbox_in_force_units_changed( GtkWidget * cbox_in_force_units, s_widget * sp_widget );

//If Distance Units combo box is changed...
void on_cbox_in_dist_units_changed( GtkWidget * cbox_in_dist_units, s_widget * sp_widget );

//If Output Force Units combo box is changed...
void on_cbox_out_force_units_changed( GtkWidget * cbox_out_force_units, s_widget * sp_widget );

//If Output Distance Units combo box is changed...
void on_cbox_out_dist_units_changed( GtkWidget * cbox_out_dist_units, s_widget * sp_widget );

#endif