#include <stdio.h>
#include <math.h>
#include "/home/artichoke/Documents/dl_lib/engineering.h"

int areUnitsInBounds( int input_units, int output_units, int rows, int cols )
{
	//This function checks if the requested units (input (rows) & output (cols))
	//are within the bounds of the specified array (rows x cols)

	int err_val = 0;

	if( input_units < 0 ||
		output_units < 0 )
	{
		//Invalid units requested
		err_val = -10001;
	}
	else if( rows < 0 ||
			 cols < 0 )
	{
		//Invalid array specified
		err_val = -10002;
	}
	else if( input_units >= rows ||
			 output_units >= cols )
	{
		//Unit request out of bounds of array
		err_val = -10003;
	}

	return err_val;	
}

int convertUnits(int type, int input_units, double input_val, int output_units, double * output_val )
{
	//This function converts an input unit (row) to an output unit (col)
	//based on the type of unit requested

	int err_val = 0;

	//[msec, sec, min, hr][msec, sec, min, hr]
	double time_table[4][4] = {
		{ 1.0,				0.001,			0.00001666667,		0.0000002777778 },
		{ 1000.0,			1.0,			0.01666666666,		0.0002777778 	},
		{ 60000.0,			60.0,			1.0,				0.016666668 	},
		{ 3600000.0,		3600.0,			60.0,				1.0 			},
		};

	//[psi, MPa, kPa, Pa, bar, mmHg, inHg][psi, MPa, kPa, Pa, bar, mmHg, inHg]
	double pressure_table[7][7] = {
		{ 1.0,			0.00689475909,	6.89475909,		6894.757,		0.06894757,	51.7149241,		2.0360205 },
		{ 145.037731575,1.0,			1000.0,			1000000.0,		10.0,		7500.6157585,	295.2998016 },
		{ 0.1450377,	0.001,			1.0,			1000.0,			0.01,		7.5006157585,	0.2952998016 },
		{ 0.0001450377,	0.000001,		0.001,			1.0,			0.00001,	0.0075006157,	0.0002952998016 },
		{ 14.50377,		0.1,			100.0,			100000.0,		1.0,		750.0615758,	29.52998016 },
		{ 0.0193368,	0.0001333,		0.1333,			133.3,			0.001333,	1.0,			0.0393701 },
		{ 0.4911542,	0.0033864,		3.3863887,		3386.3886667,	0.0338639,	25.4,			1.0 }
		};

	//[mm, in, m, ft, cm, yd][mm, in, m, ft, cm, yd]
	double linear_table[6][6] = {
		{ 1.0,			0.03937007874,		0.001,		0.00328084,		0.1,		0.001093613 	},
		{ 25.4,			1.0,				0.0254,		0.08333333,		2.54,		0.02777778 		},
		{ 1000.0,		39.37007874016,		1.0,		3.28084,		100.0,		1.093613 		},
		{ 304.8,		12.0,				0.3048,		1.0,			30.48,		0.33333333333 	},
		{ 10.0,			0.39370078740,		0.01,		0.0328084,		1.0,		0.01093613 		},
		{ 914.4,		36.0,				0.9144,		3.0,			91.44,		1.0 			}
		};

	//[rad, deg, rev][rad, deg, rev]
	double angle_table[3][3] = {
		{ 1.0,					57.29577951308,		0.63661977237	},
		{ 0.01745329252,		1.0,				0.00277777778	},
		{ 6.28318530718,		360.0,				1.0				},
		};

	//[kgm, lbm][kgm, lbm]
	double mass_table[2][2] = {
		{ 1.0,			0.45359236844386	},
		{ 2.2046226,	1.0					},
		};

	//[N, lbs, oz, kgf][N, lbs, oz, kgf]
	double force_table[4][4] = {
		{ 1.0,				0.22480894244319,	3.5969431019354,	0.101971621297793 	},
		{ 4.4482216282509,	1.0,				16.0,				0.45359236844386 	},
		{ 0.2780139,		0.0625,				1.0,				0.028349523027741 	},
		{ 9.80665,			2.2046226,			35.2739621,			1.0 				},
		};

	//Based on the type of conversion requested...
	//calculate the size of the corresponding array
	int rows;
	int cols;
	switch ( type )
	{
	case 0: //Time
		//printf( "Time reached.\n" );
		rows = sizeof(time_table) / sizeof(time_table[0]);
		cols = sizeof(time_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * time_table[input_units][output_units];	}
		break;
	case 1: //Pressure
		//printf( "Pressure reached.\n" );
		rows = sizeof(pressure_table) / sizeof(pressure_table[0]);
		cols = sizeof(pressure_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * pressure_table[input_units][output_units];	}
		break;
	case 2: //Linear
		//printf( "Linear reached.\n" );
		rows = sizeof(linear_table) / sizeof(linear_table[0]);
		cols = sizeof(linear_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * linear_table[input_units][output_units]; }
		break;
	case 3: //Angle
		//printf( "Angle reached.\n" );
		rows = sizeof(angle_table) / sizeof(angle_table[0]);
		cols = sizeof(angle_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * angle_table[input_units][output_units]; }
		break;
	case 4: //Mass
		//printf( "Mass reached.\n" );
		rows = sizeof(mass_table) / sizeof(mass_table[0]);
		cols = sizeof(mass_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * mass_table[input_units][output_units];	}
		break;
	case 5: //Force
		//printf( "Force reached.\n" );
		rows = sizeof(force_table) / sizeof(force_table[0]);
		cols = sizeof(force_table[0]) / sizeof(double);
		err_val = areUnitsInBounds( input_units, output_units, rows, cols );
		if( err_val == 0 ){	* output_val = input_val * force_table[input_units][output_units]; }
		break;
	default:
		break;
	}

	return err_val;
}

void cylForceCalc( double pressure, double bore, double rod, double qty, double * force )
{
    //Take inputs in MPa, mm, mm, and N
    //Calculate output force
	double area = (3.14159 / 4.0) * (bore * bore - rod * rod); //mm^2
	* force = pressure * area * qty; //Newtons
}

void cylBoreCalc( double pressure, double rod, double qty, double force, double * bore )
{
	//Take inputs in MPa, mm, int and N

	int err_val = 0;

	//Check for 0 (not allowed: divide-by-zero not allowed)
	if( pressure == 0 ||
		qty == 0 )
	{
		err_val = -10010;
	}
	//Check for negative values (square root of a negative number)
	else if( pressure < 0 ||
			 qty < 0 )
	{
		err_val = -10011;
	}
	//Calculate output bore
	else
	{
		double area = force / (pressure * qty);
		* bore = pow( ((4.0 / 3.14159) * area + rod * rod ), 0.5 );
	}
	
}

void cylPressureCalc( double bore, double rod, double qty, double force, double * pressure )
{
	//Take inputs in mm, mm, int and N; output MPa
	double area = (3.14159 / 4.0) * (bore * bore - rod * rod); //mm^2
	
	int err_val = 0;

	//Check for 0 (not allowed: divide-by-zero not allowed)
	if( area == 0 ||
		qty == 0 )
	{
		err_val = -10012;
	}
	//Check for negative values (not allowed: square root of a negative number)
	else if( area < 0 ||
			 qty < 0 )
	{
		err_val = -10013;
	}
	//Calculate output pressure in MPa
	else
	{
		* pressure = force / ( area * qty );
	}
}

void calcDistance( s_point point1, s_point point2, double * distance )
{
	// d = ( (x2-x1)^2 + (y2-y1)^2 + (z2-z1)^2 )^0.5
	* distance = pow( (pow( point2.x - point1.x, 2 )
					+ pow( point2.y - point1.y, 2 )
					+ pow( point2.z - point1.z, 2 ) ), 0.5 );
}

void linearInterpolation( s_point p_curr, s_point p_target, s_point midpoint )
{
    midpoint.x = (p_target.x - p_curr.x) / 2.0 + p_curr.x;
    midpoint.y = (p_target.y - p_curr.y) / 2.0 + p_curr.y;
    midpoint.z = (p_target.z - p_curr.z) / 2.0 + p_curr.z;
}