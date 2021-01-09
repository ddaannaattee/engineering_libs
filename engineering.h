//This header file contains function that convert units and perform calculations
#ifndef DL_ENGINEERING_H_
#define DL_ENGINEERING_H_

//Desired output
#define i_want_force 0
#define i_want_bore 1
#define i_want_pressure 2
#define i_want_dist 3
#define i_want_torque 4

//Time units
#define units_time 0

#define msec 0
#define sec 1
#define min 2
#define hr 3

//Pressure units
#define units_pressure 1

#define psi 0
#define MPa 1
#define kPa 2
#define Pa 3
#define bar 4
#define mmHg 5
#define inHg 6

//Linear units
#define units_linear 2

#define mm 0
#define in 1
#define m 2
#define ft 3
#define cm 4
#define yd 5

#define diameter 1

//Angle units
#define units_angle 3

#define rad 0
#define deg 1
#define rev 2

//Mass units
#define units_mass 4

#define kgm 0
#define lbm 1

//Force units
#define units_force 5

#define N 0
#define lbs 1
#define oz 2
#define kgf 3

typedef struct vector{
    double mag;
    double x;
    double y;
    double z;
} s_vec;

typedef struct point{
    double x;
    double y;
    double z;
} s_point;

//Evaluate whether requested units are in the bounds of the conversion array
int areUnitsInBounds( int input_units, int output_units, int rows, int cols );

//Input units (see definitions above), input val, desired output units, and output val container...
//Saves output to output val, returns error value
int convertUnits(int type, int input_units, double input_val, int output_units, double * output_val );

//Input pressure in MPa, bore in mm, rod in mm, and qty...
//Saves force value in N
void cylForceCalc( double pressure, double bore, double rod, double qty, double * force );

//Input pressure in MPa, rod in mm, qty, and force in N...
//Saves bore in mm
void cylBoreCalc( double pressure, double rod, double qty, double force, double * bore );

//Input bore in mm, rod in mm, qty, and force in N...
//Saves pressure in MPa
void cylPressureCalc( double bore, double rod, double qty, double force, double * pressure );

//Input points in s_point structure format
void calcDistance( s_point point1, s_point point2, double * distance );

//Input points in s_point structure format
void linearInterpolation( s_point p_curr, s_point p_target, s_point midpoint );

#endif
