//This header file contains the functions used in the Cylinder Force tab
#include "infostruct.h"
#include <gtk/gtk.h>

#ifndef DL_CYLINDERFORCE_H_
#define DL_CYLINDERFORCE_H_

int cylGetPressure( s_widget * sp_widget );

int cylGetBore( s_widget * sp_widget );

int cylGetRod( s_widget * sp_widget );

int cylGetQty( s_widget * sp_widget );

int cylGetForce( s_widget * sp_widget );

int cylGetAllInputs( s_widget * sp_widget );

void cylSetOutputs( GtkWidget * entry_box, double value );

void cylDoItAll( s_widget * sp_widget );

//Function to connect the objects in the "Cylinder Force" tab to the application
void connectCylObj( s_widget * sp_widget, GtkBuilder * builder );

//If Radio button is toggled...
void on_rb_cyl_toggled( GtkToggleButton * togglebutton, s_widget * sp_widget );

//If Pressure entry box is changed or 'enter' key is pressed...
void on_e_cyl_pressure_activate( GtkWidget * e_cyl_pressure, s_widget * sp_widget );
void on_e_cyl_pressure_changed( GtkWidget * e_cyl_pressure, s_widget * sp_widget );

//If Bore entry box is changed or 'enter' key is pressed...
void on_e_cyl_bore_activate( GtkWidget * e_cyl_bore, s_widget * sp_widget );
void on_e_cyl_bore_changed( GtkWidget * e_cyl_bore, s_widget * sp_widget );

//If Rod entry box is changed or 'enter' key is pressed...
void on_e_cyl_rod_activate( GtkWidget * e_cyl_rod, s_widget * sp_widget );
void on_e_cyl_rod_changed( GtkWidget * e_cyl_rod, s_widget * sp_widget );

//If Quantity entry box is changed or 'enter' key is pressed...
void on_e_cyl_qty_activate( GtkWidget * e_cyl_qty, s_widget * sp_widget );
void on_e_cyl_qty_changed( GtkWidget * e_cyl_qty, s_widget * sp_widget );

//If Force entry box is changed or 'enter' key is pressed...
void on_e_cyl_force_activate( GtkWidget * e_cyl_force, s_widget * sp_widget );
void on_e_cyl_force_changed( GtkWidget * e_cyl_force, s_widget * sp_widget );

//If Pressure combo box is changed...
void on_cbox_cyl_pressure_changed( GtkWidget * cbox_cyl_pressure, s_widget * sp_widget );

//If Bore combo box is changed...
void on_cbox_cyl_bore_changed( GtkWidget * cbox_cyl_bore, s_widget * sp_widget );

//If Rod combo box is changed...
void on_cbox_cyl_rod_changed( GtkWidget * cbox_cyl_rod, s_widget * sp_widget );

//If Rod combo box is changed...
void on_cbox_cyl_force_changed( GtkWidget * cbox_cyl_force, s_widget * sp_widget );

#endif