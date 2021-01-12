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
#include "torqueconversion.h"
#include "hmotorinertia.h"

//Function Declarations
GdkPixbuf * create_pixbuf(const gchar * filename);
void on_window1_destroy();

//Main Function!
int main( int argc, char *argv[] )
{ 
	s_widget * sp_widget = g_slice_new( s_widget );
	sp_widget->sp_cyl_data = &( struct cyl_force ){};
	sp_widget->sp_torque_conv_data = &( struct torque_conv ){};
    sp_widget->sp_hms_data = &( struct hms ){};

    GtkBuilder *builder1;
    GtkWidget *window;
	GdkPixbuf *icon;

	GError *error = NULL;
    gtk_init( &argc, &argv );

    builder1 = gtk_builder_new();
    if( !gtk_builder_add_from_file (builder1, "window_main.glade", &error) ){
    	g_warning( "%s", error->message );
    	g_free( error );
    	return 1;
    }    

    window = GTK_WIDGET( gtk_builder_get_object( builder1, "window1" ) );
	icon = create_pixbuf( "icecream.png" );
	gtk_window_set_icon(GTK_WINDOW( window ), icon);
    
    //Set up objects from each of the notebook tabs, connect signals
    connectCylObj( sp_widget, builder1 );
	connectTorqueConvObj( sp_widget, builder1 );
    connectHMSObj( sp_widget, builder1 );
    gtk_builder_connect_signals( builder1, sp_widget );
    g_object_unref( builder1 );

    sp_widget->sp_hms_data->velocity_profile = 0;

	//Pre-fill entry boxes for Cylinder Force Calculator
	gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_pressure ), "80" );
	gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_rod ), "0" );
	gtk_entry_set_text( GTK_ENTRY( sp_widget->e_cyl_qty ), "1" );

    //Pre-fill entry boxes for Horiz. Motor Sizing Calculator
    gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_servo_moves ), "2.0" );
    gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_pulley_inertia ), "0.0" );
    gtk_entry_set_text( GTK_ENTRY( sp_widget->e_hms_losses ), "15.0" );

	//Show window
    gtk_widget_show( window );  
	g_object_unref(icon);              
    gtk_main();

	g_slice_free( s_widget, sp_widget );
	
	return 0;
}

//Function to associate an icon with an application
GdkPixbuf * create_pixbuf(const gchar * filename)
{   
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   
   if (!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

// called when window is closed
void on_window1_destroy()
{
    gtk_main_quit();
}


