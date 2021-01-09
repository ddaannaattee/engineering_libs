#include <gtk/gtk.h>

#ifndef DL_COMPONENTS_H_
#define DL_COMPONENTS_H_

//Pulley
typedef struct pulley{
    double diam; //pitch diameter
    double radius; //pitch radius
    int n; //number of teeth
    double inertia; //inertia about axis of rotation
} s_pulley;

//Air cylinder
typedef struct air_cyl{
    double pressure; //MPa
    double outer_diam; //mm
    double inner_diam; //mm
    double area; //mm^2
    double stroke; //mm
} s_air_cyl;